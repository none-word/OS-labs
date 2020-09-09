#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

//Since the proccess executed by several cores asynchroniously, so outputing string was jumbled.

int main()
{
	int pid = fork();
	
	int n = 10;

	if (pid == 0) {
	
	printf("Hello from parent [%d - %d]\n", pid, n);
	
	} else {

	printf("Hello from child [%d - %d]\n", pid, n);

	}

	return 0;
}
