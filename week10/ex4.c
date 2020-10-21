#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

// int* i_nodes = (int*)calloc(0, sizeof(int)*100);
// int contains(){
  
// }

struct File{
  int number;
  char* name;
};

int main(void) {
  
  struct File* files = (struct File*)malloc(sizeof(struct File) * 100);
  
  // for (int i = 0; i < 100; i++){
  //   files -> number = 0;
  // }

  DIR* dir = opendir("./tmp");

  struct stat *buff;
  struct dirent *file;

  int i = 0;
  while((file = readdir(dir)) != NULL){
    if (strcmp(file -> d_name, "..") != 0 && strcmp(file -> d_name, ".") != 0){
      struct stat *buff;
      stat(file -> d_name, buff);
      printf("%s  %li\n", file -> d_name, buff -> st_ino);

      files[i].number = buff -> st_ino;
      files[i].name = file -> d_name;
      i++;

      printf("\n");
    }
  }
}