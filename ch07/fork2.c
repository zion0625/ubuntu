#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
        pid_t pid;
        int n, sum=0, mul=1;

	scanf("%d", &n);
	pid = fork();

	for(int i=1; i <= n; i++){
		sum += i;
		mul *= i;
	}

        if(pid > 0) // parent
        {
                printf("%d\n", sum);
        }
        else if(pid == 0) // child
        {
		printf("%d\n", mul);
        }
	else
	{
		printf("fork failed");
	}
}

