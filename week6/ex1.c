#include <stdio.h>
#include <stdlib.h>

void sortByTimeIn(int **array, int n){

  for(int i = 0 ; i < n - 1; i++) {
       
       for(int j = 0 ; j < n - i - 1 ; j++) {  
           if(array[0][j] > array[0][j+1]) { 
              int t0 = array[0][j];
              int t1 = array[1][j];

              array[0][j] = array[0][j+1];
              array[1][j] = array[1][j+1];

              array[0][j+1] = t0;
              array[1][j+1] = t1;
           }
        }
    }

}

int main(void) {
  int n;
  
  printf("Please, write number of the process\n");
  scanf("%d", &n);

  int** buffer;
  buffer = (int**)malloc(2*sizeof(int));

  buffer[0] = (int*)malloc(n*sizeof(int));
  buffer[1] = (int*)malloc(n*sizeof(int));

  for (int i = 0; i < n; i++){
    printf("Please, write arrival time of the process\n");
    scanf("%d", &buffer[0][i]);
    printf("Please, write burst time of the process\n");
    scanf("%d", &buffer[1][i]);
  }

  sortByTimeIn(buffer, n);

  int CT = buffer[0][0];
  double ATAT = 0;
  double AWT = 0;
  printf("\tAT\tBT\tCT\tTAT WT\n\n");
  for (int i = 0; i < n; i++) {
    if (CT < buffer[0][i]){
      CT = buffer[0][i];
    } else {
      CT += buffer[1][i];
    }
    int TAT = CT - buffer[0][i];
    int WT = TAT - buffer[1][i];

    ATAT += TAT;
    AWT += WT;

    printf(
      "P%d\t%d\t%d\t%d\t%d\t%d\n", 
      i + 1, 
      buffer[0][i], 
      buffer[1][i],
      CT,
      TAT,
      WT
      );
  }

  printf("Average Turnaround Time: %f\n", (ATAT / n));
  printf("Average Waiting Time: %f\n", (AWT / n));
  return 0;
}