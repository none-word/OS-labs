#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
  
  for(int i = 0; i < 10; i++){
    int* a = (int*) malloc(10 * 1024 * 1024);
    memset(a, 0, 10 * 1024 * 1024);
    sleep(1);
  }

  return 0;
}