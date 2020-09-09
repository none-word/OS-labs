#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

        char script[1024];

        fgets(script, 1024, stdin);
        system(script);

        return 0;
}