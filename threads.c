#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>

static void *
threadFunc(void *arg){
	char *s =(char *)arg;
	write(1,s,strlen(s));
	return (void *)strlen(s);
}

int main(int argc,char *argv[]){
	pthread_t t1;
	void *res;
	int s;
	
	s=pthread_create(&t1, NULL,threadFunc,"This is wasi\n");
	if(s!=0){
		perror("pthread");	
	}
	
	write(1,"Message from main thread\n",25);
	s=pthread_join(t1,&res);
	if(s!=0){
		perror("pthread_join");
	}
	
	printf("Thread returned %ld\n",(long)res);
	
	exit(EXIT_SUCCESS);
}
