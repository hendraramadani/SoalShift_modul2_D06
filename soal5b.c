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
    char target[15] = {"soal5a"};
    
    char *arg[3] = {"killall", target, NULL};
    execv("/usr/bin/killall", arg);

    return 0;
}
