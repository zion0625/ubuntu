#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>

int num =1;

int main(){
	static struct sigaction act;
	
	void int_handle(int);

	act.sa_handler = int_handle;
	sigfillset(&(act.sa_mask));
	sigaction(SIGINT, &act, NULL);
	while(num){
		printf("i'm sleepy..\n");
		sleep(1);
	}
}

void int_handle(int signum){
	char buffer[] = "exit\n";
	int fd = open("a.txt", O_CREAT | O_RDWR, 0777);
	write(fd, buffer, strlen(buffer));

	close(fd);
	num=0;
}
