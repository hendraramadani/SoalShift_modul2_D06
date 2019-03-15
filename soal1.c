#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <dirent.h>

int main() {

  pid_t pid, sid;
  
  pid = fork();

  if (pid < 0){
    exit(EXIT_FAILURE);
  }

  if (pid > 0){
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0){
    exit(EXIT_FAILURE);
  }

  if ((chdir("/home/azzamjiul/modul2/")) < 0){
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

    DIR *dir;
    struct dirent *asli;
    char *namaFile,*ekstrak;
    int ganti_nama;
    char namaAsli[110];
    char namaTambahan[10] = "_grey.png";
    char namaBaru[110];
    char src[50] = "/home/azzamjiul/modul2/", dest[50] = "/home/azzamjiul/modul2/gambar/";

  while(1) {
    if ((dir = opendir ("/home/azzamjiul/modul2/")) != NULL) {
        while ((asli = readdir (dir)) != NULL) {
            strcpy(namaAsli, src); 
            strcat(namaAsli,asli->d_name);   
            namaFile=strtok(asli->d_name,".");
            ekstrak=strtok(NULL,".");

            if(ekstrak!=NULL){
                ganti_nama=strcmp(ekstrak,"png");

                if(ganti_nama==0){
                    strcpy(namaBaru,dest);
                    strcat(namaFile,namaTambahan);
                    strcat(namaBaru,namaFile);
                    rename(namaAsli,namaBaru);
                }
            }
        }
        closedir (dir);
    }
    sleep(45);
  }
  exit(EXIT_SUCCESS);
}
