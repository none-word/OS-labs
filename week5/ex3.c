#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define n 10

int position = 0;
int producer_sleep = 0;
int consumer_sleep = 1;
int counter;

void * produce(void * arg){
  counter = 0;  
  while(1){
    while(producer_sleep);
    if (counter % 1000 == 0){
      printf("Producer %d\n", counter);
    }
    if(position==10) {
      producer_sleep = 1;
      consumer_sleep = 0;
      counter++;
      continue;
    }
    position++;
  }
  pthread_exit(NULL);
}

void * consume(void * arg){
  counter = 0;
  while(1){
    while(consumer_sleep);
    if (counter % 1000 == 0){
      printf("Consumer %d\n", counter);
    }
    if(position==0) {
      producer_sleep = 0;
      consumer_sleep = 1;
      counter++;
      continue;
    }
    position--;
  }
  pthread_exit(NULL);
}

int main(void) {

  pthread_t threadProducer;
  pthread_t threadConsumer;

  pthread_create(&threadProducer, NULL, produce, NULL);
  pthread_create(&threadConsumer, NULL, consume, NULL);

  for(;;);
  return 0;
}