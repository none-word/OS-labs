#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main(void) {
  
  struct rusage usage;
  for(int i = 0; i < 10; i++){
    int* a = (int*) malloc(10 * 1024 * 1024);
    memset(a, 0, 10 * 1024 * 1024);
    getrusage(RUSAGE_SELF, &usage);
    long long time = usage.ru_maxrss;
    printf("Usage memory: %lli\n", time);
    sleep(1);
  }

  return 0;
}