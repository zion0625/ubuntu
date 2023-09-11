#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char **argc)
{
	int filedes;
	off_t newpos;

	filedes = open(argv[1], O_RDONLY);

	newpos = lseek(filedes, (off_t)0, SEEK_END);

	printf("flie size : %d\n", newpos);

	close(filedes);
}
