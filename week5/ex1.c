#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define n 10

void * show(void * arg){

  int * i = (int *) arg;
  printf("Thread %d have been created\n", *i);
  printf("Exited thread number %d\n", *i);
  pthread_exit(NULL);

}

int main(void) {

  pthread_t tid[n];

  for (int i = 0; i < n; i++) {
    
    printf("Creating thread number %d\n", i);
    pthread_create(&tid[i], NULL, show, &i);
    pthread_join(tid[i], NULL);
    
  }

  pthread_exit(NULL);

  return 0;
}