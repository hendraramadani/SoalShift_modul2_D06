#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main() {
  pid_t pid = fork(), sid;

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {
    char makan[] = "/home/dani/Documents/makanan/makan_enak.txt";
    struct stat info;
    stat(makan, &info);
	time_t timeProg = time(NULL);
        time_t timeMakan = info.st_atime; 
    if (difftime(timeProg,timeMakan)<=30) {
      int i=1;
      while (1) {
        char dest[200] = "/home/dani/Documents/makanan/";
        char str[20] = "";
        sprintf(str, "makanan_sehat%d.txt", i);
        strcat(dest, str);

        i++;
      }
    }
    sleep(5);
  }
  
  exit(EXIT_SUCCESS);
}
