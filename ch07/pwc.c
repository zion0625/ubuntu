#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	char filename[64];
	int n;

	for(int n=1; i < argc; i++){
		strcpy(filename, argv[n]);
		printf("run \"wc %s\"\n", filename);

		pid = fork();

		if(pid ==0){
			execlp("wc", "wc", filename, (char *)0);
			printf("wc %s\n", filename);
			exit(1);
		}
	}
}
