#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	putenv("MYDATA=5");
	printf("%s\n", getenv("MYDATA"));

	execl("ex-1103-2", "ex-1103-2", (char *)0);
}
