/*
  First two numbers in input file are number of sources and number of processes respectively
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int nSource;
int nProcess;

int* resourceExistence;
int* resourceAvailable;
int** currentAllocationMatrix;
int** requestMatrix;

void printAllData(){

  for(int i = 0; i < nSource; i++){
    printf("%d ", resourceExistence[i]);
  }

  printf("\n");
  printf("\n");

  for(int i = 0; i < nSource; i++){
    printf("%d ", resourceAvailable[i]);
  }

  printf("\n");
  printf("\n");

  for(int i = 0; i < nProcess; i++){
    for(int j = 0; j < nSource; j++){
      printf("%d ", currentAllocationMatrix[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  for(int i = 0; i < nProcess; i++){
    for(int j = 0; j < nSource; j++){
      printf("%d ", requestMatrix[i][j]);
    }
    printf("\n");
  }

  printf("\n");

}

void read_data(FILE* file){

  for(int i = 0; i < nSource; i++){
    fscanf(file, "%d", resourceExistence + i);
  }

  for(int i = 0; i < nSource; i++){
    fscanf(file, "%d", resourceAvailable + i);
  }

  for(int i = 0; i < nProcess; i++){
    for(int j = 0; j < nSource; j++){
      fscanf(file, "%d", currentAllocationMatrix[i] + j);
    }
  }

  for(int i = 0; i < nProcess; i++){
    for(int j = 0; j < nSource; j++){
      fscanf(file, "%d", requestMatrix[i] + j);
    }
  }
}

void findDeadlock(FILE* file){

  int i = 0;
  int nCheckedProcesses = 0;
  int nPrevCheckedProcess = 0;

  while(nCheckedProcesses != nProcess && !(i == nProcess && nPrevCheckedProcess == nCheckedProcesses)) {
    int isEnoughResource = 1;
    i %= nProcess;

    for (int j = 0; j < nSource; j++){
      if (requestMatrix[i][j] > resourceAvailable[j]){
        isEnoughResource = 0;
        break;
      }
    }

    nPrevCheckedProcess = nCheckedProcesses;

    if (isEnoughResource == 0){
      i++;
      continue;
    }

    printAllData();

    nCheckedProcesses++;
    for (int j = 0; j < nSource; j++){
      resourceAvailable[j] += currentAllocationMatrix[i][j];
      requestMatrix[i][j] = 0;
    }

    i++;
  }

  if (nCheckedProcesses == nProcess && i == nProcess) {
    fprintf(file, "No deadlock is detected");
    return;
  }

  fprintf(file, "Deadlocks are on process:\n");
  for (int i = 0; i < nProcess; i++) {
    for (int j = 0; j < nSource; j++) {
      if (requestMatrix[i][j] != 0){
        fprintf(file, "%d ", i);
        break;
      }
    }
  }
}

int main(void) {

  FILE* inputFile = fopen("input_dl.txt", "r");
  FILE* outputFile = fopen("output_dl.txt", "w");

  fscanf(inputFile, "%d", &nSource);
  fscanf(inputFile, "%d", &nProcess);

  resourceExistence = malloc(sizeof(int) * nSource);
  resourceAvailable = malloc(sizeof(int) * nSource);

  currentAllocationMatrix = malloc(sizeof(int*) * nProcess);
  for(int i = 0; i < 100; i++){
    currentAllocationMatrix[i] = malloc(sizeof(int) * nSource);
  }

  requestMatrix = malloc(sizeof(int*) * nProcess);
  for(int i = 0; i < 100; i++){
    requestMatrix[i] = malloc(sizeof(int) * nSource);
  }

  read_data(inputFile);
  findDeadlock(outputFile);


  fclose(inputFile);
  fclose(outputFile);
  return 0;
}