#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

int main(){
    pid_t child3;
    char hasil[1050];
    int status, pipes[4];

    child3 = fork();

    if(child3 ==0){
        execl("/usr/bin/unzip", "unzip", "campur2.zip", NULL);
    }
    else{
        pid_t child2;
        int p2;
        while(wait(&status)>0);
        pipe(pipes);
        pipe(pipes+2);

        child2 = fork();

        if(child2 == 0){
           close(pipes[0]);
           close(pipes[2]);
           close(pipes[3]);

           dup2(pipes[1], STDOUT_FILENO); //handle hasil ls
           close(pipes[1]);
           execlp("ls","ls","/home/azzamjiul/SISOP/sesilab2/campur2",(char*)NULL);
        }
        else{
            pid_t child1;
            child1 = fork();
            
            if(child1==0){
                close(pipes[1]);
                dup2(pipes[0], STDIN_FILENO); //masukin hasil ls
                close(pipes[0]);
                close(pipes[2]);
                dup2(pipes[3], STDOUT_FILENO); // handel hasil grep
                close(pipes[3]);
                execlp("grep", "grep", ".txt$", (char*) NULL);
            }
            else{
                close(pipes[1]);
                int print = read(pipes[2],hasil,sizeof(hasil)); // ambil hasil grep
                close(pipes[2]);

                FILE* file;
                file = fopen("daftar.txt","w+");
                fprintf(file,"Daftar nama file yang berformat .txt :\n%.*s\n",print,hasil);
                printf("Daftar nama file yang berformat .txt :\n%.*s\n",print,hasil);
                fclose(file);
            }
        }
    }
}
