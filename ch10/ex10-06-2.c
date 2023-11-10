#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main(){
	pid_t pid;
	sigset_t set;
	int count = 3;

	sigemptyset(&set);
	sigaddset(&set, SIGINT);

	if((pid=fork()) > 0)
	{
		pause();
		printf("[parent] bye!\n");
	}
	else if(pid ==0)
	{
		while(count){
			printf("[child] count is %d\n", count--);
			sleep(1);
		}
		kill(getppid(), SIGINT);
		printf("[child] bye!\n");
	}
	else
		printf("fail to fork\n");
}
