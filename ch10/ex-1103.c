#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int num=0;

int main(){
        static struct sigaction act;

        void int_handle(int);

        act.sa_handler = int_handle;
        sigfillset(&(act.sa_mask));
        sigaction(SIGINT, &act, NULL);

	sleep(10);
}

void int_handle(int signum)
{
        char buf[1024] = "exit";
	int fd;

	fd = open("a.txt", O_CREAT | O_EXCL, 0664);
	write(fd, buf, 1024);
}
