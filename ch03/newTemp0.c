#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int filedes;

	filedes = creat("temp0.txt", 0644);

	close(filedes);
}
