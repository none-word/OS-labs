#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// So, every time when program is called fork, process are dublicated, so number of proccess equal to 2^n, where n is number of calling fork

int main(){

	for (int i = 0; i < 3; i++) {
	
		fork();
	}

	sleep(5);
	return 0;
}
