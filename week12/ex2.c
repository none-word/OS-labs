#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
  assert(argv[1] != "-a");
  char* buff = (char*)malloc(sizeof(char) * 1000);
  fread(buff, 1000, 1, stdin);
  for (int i = 2; i < argc; i++){
    FILE* outputFile = fopen(argv[i], "a");
    fprintf(outputFile, "%s", buff);
    fclose(outputFile);
  }
  return 0;
}