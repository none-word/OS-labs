#include <stdio.h>
#include <stdlib.h>

int** shortestProcess;

void sortByTimeIn(int **array, int n){

  //int** shortestProcess;
  shortestProcess = (int**)malloc(n*sizeof(int));

  shortestProcess[0] = (int*)malloc(n*sizeof(int));
  shortestProcess[1] = (int*)malloc(n*sizeof(int));

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

  //  shortestProcess[0][0] = array[0][0];
  //  shortestProcess[1][0] = array[1][0];

  int pointer_to_current_process = 0;
  int pointer_to_process_from_array = 0;
  int last_in_shortest = 0;
  int pointer_to_next_process = 0;
  int CT = array[0][0];

  for (int i = 0; i <= array[0][n-1]; i++){

    while (CT >= array[0][pointer_to_process_from_array]){
      shortestProcess[0][last_in_shortest] = array[0][pointer_to_process_from_array];
      shortestProcess[1][last_in_shortest] = array[1][pointer_to_process_from_array];
      last_in_shortest++;
      pointer_to_process_from_array++;
    }

    for(int i = pointer_to_next_process ; i < last_in_shortest - 1; i++) {     
       for(int j = pointer_to_next_process ; j < last_in_shortest - i - 1 ; j++) {  
           if(shortestProcess[1][j] > shortestProcess[1][j+1]) { 
              int t0 = shortestProcess[0][j];
              int t1 = shortestProcess[1][j];

              shortestProcess[0][j] = shortestProcess[0][j+1];
              shortestProcess[1][j] = shortestProcess[1][j+1];

              shortestProcess[0][j+1] = t0;
              shortestProcess[1][j+1] = t1;
           }
        }
    }

    CT += shortestProcess[0][pointer_to_next_process];
    pointer_to_next_process ++;

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

  int CT = shortestProcess[0][0];
  double ATAT = 0;
  double AWT = 0;
  printf("\tAT\tBT\tCT\tTAT WT\n\n");
  for (int i = 0; i < n; i++) {
    if (CT < shortestProcess[0][i]){
      CT = shortestProcess[0][i];
    } else {
      CT += shortestProcess[1][i];
    }
    int TAT = CT - shortestProcess[0][i];
    int WT = TAT - shortestProcess[1][i];

    ATAT += TAT;
    AWT += WT;

    printf(
      "P%d\t%d\t%d\t%d\t%d\t%d\n", 
      i + 1, 
      shortestProcess[0][i], 
      shortestProcess[1][i],
      CT,
      TAT,
      WT
      );
  }

  printf("Average Turnaround Time: %f\n", (ATAT / n));
  printf("Average Waiting Time: %f\n", (AWT / n));
  return 0;
}