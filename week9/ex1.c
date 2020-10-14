#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;

  printf("Please, write the number of page frames:\n");
  scanf("%d", &n);

  FILE *file = fopen("Lab_09_input.txt", "r");

  int* stored_pages = (int*)calloc(n, sizeof(int));
  unsigned int* age = (unsigned int*)calloc(n, sizeof(unsigned int));
  int current_page;
  int hits = 0;
  int misses = 0;
  while (fscanf(file, "%d", &current_page) != EOF) {
    int met = 0;
    for (int i = 0; i < n; i++){
      if (stored_pages[i] == current_page) {
        hits++;
        met = 1;
      }
      age[i] >>= 1;
    }
    if (!met){
      misses++;
      int min_age = 1024;
      int i_min_age = -1;
      for (int i = 0; i < n; i++) {
        if (stored_pages[i] == 0) {
          min_age = 0;
          i_min_age = i;
        }
        if (age[i] < min_age){
          min_age = age[i];
          i_min_age = i;
        }
        age[i] >>= 1;
      }

      stored_pages[i_min_age] = current_page;
      age[i_min_age] = 32;
    }
  }

  printf("Hits: %d\nMisses: %d\nRatio: %f", hits, misses, (hits * 1.0)/(misses * 1.0));
  return 0;
}