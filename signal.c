#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
void sighandler(int signo){
	if(signo==SIGINT){
		write(1,"Sigint called",12);
	}
}
int main(int argc,char *argv[]){
	int pid=fork();
	if(pid>0){
		write(1,"PARENT RUN",10);
		pause();
		write(1,"after pause PARENT RUN",12);

		
	}
	if(pid==0){
		int ret=kill(getppid(),0);
		if(ret==0){
			write(1,"parent killed",13);
		}
	}
}
