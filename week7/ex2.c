#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  scanf("%d", &n);

  int* array;
  array = (int*)malloc(n * sizeof(int));
  for(int i = 0; i < n; i++){
    array[i] = i;
  }

  printf("Result array: \n");
  for (int i = 0; i < n; i++){
    printf("%d ", array[i]);
  }

  free(array);
  return 0;
}