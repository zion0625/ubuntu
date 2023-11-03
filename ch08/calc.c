#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<math.h>

int main()
{
	int x, y;
	pid_t pid;
	int status;

	scanf("%ld %ld", &x, &y);

	pid = fork();

	if(pid > 0){
		int i;
		i = pow(x, y);
		wait(&status);
		printf("result: %ld\n", i + status>>8);
	}
	else if(pid ==0){
		int j, sum=0;
		for(j=x; j <= y; j++){
			sum += j;
		}
		exit(sum);
	}
}
