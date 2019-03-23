#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <signal.h>

int main(){
    pid_t pid = fork(), sid, child;

    char *username;
    username = getlogin();
    char dir[100];
    sprintf(dir,"/home/%s/log",username);

    if(pid<0){
        exit(EXIT_FAILURE);
    }

    if(pid>0){
        exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();

    if(sid < 0){
        exit(EXIT_FAILURE);
    }

    if(chdir("/")<0){
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    int status;
    int minute = 0;
    char dtime[20];

    while(1){
        if(minute%30 == 0){
            minute = 0;
            time_t now = time(NULL);
            struct tm *sekarang = localtime(&now);
            strftime(dtime, sizeof(dtime), "%Y:%m:%d-%H:%M:%S", sekarang);
        }

        child = fork();

        if(child == 0){
            char cmd[200];
            sprintf(cmd, "%s/%s", dir, dtime);
            char *arg[4] = {"mkdir", "-p", cmd, NULL};
            execv("/bin/mkdir", arg);
        }

        while((wait(&status)) > 0);

        minute++;

        kill(child, SIGKILL);
        child = fork();

        if(child == 0){
            char namaFile[200];
            sprintf(namaFile,"%s/%s/log%d.log",dir,dtime,minute);
            char src[] = "var/log/syslog";
            char *argv[4] = {"cp", src, namaFile, NULL};
            execv("/bin/cp", argv);
        }
        
        while((wait(&status)) > 0);
        kill(child, SIGKILL);
        sleep(60);
    }
    
    exit(EXIT_SUCCESS);
}
