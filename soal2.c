#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

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
  if ((chdir("/home/dani/modul2/soal2/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  char mode[] = "0777";
  int i = strtol(mode, 0, 8);

  while(1) {
  	struct stat info;
	char elenku[] = "/home/dani/modul2/soal2/hatiku/elen.ku";
    		if(stat(elenku, &info)==0){
        		struct passwd *usr = getpwuid(info.st_uid);
        		struct group  *grp= getgrgid(info.st_gid);
				if(!strcmp(grp->gr_name, "www-data") && !strcmp(usr->pw_name, "www-data")){
            				chmod(elenku,i);
            				remove(elenku);
        			}	      
    		}
    	sleep(3);
  }  
  exit(EXIT_SUCCESS);
}
