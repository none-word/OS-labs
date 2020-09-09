#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(){

  char script[1024];

  while(1){

    fgets(script, 1024, stdin);

    char *arguments[1024];
    int arg = 0, k = 0;

    for (int i = 0; i < 1024; i++){
      
    }

    arguments[0] = malloc(1024 * sizeof(char));

    for (int i = 0; i < 1024; i++) {

      if (script[i] == '\n') {
        break;
      }

      if (script[i] == '\0') {
        break;
      }

      if (script[0] == ' ') {

        k = 0;

        arguments[++arg] = malloc(1024 * sizeof(char));
        continue;

      }

      arguments[arg][k] = script[i];
    }

    if (!strcmp("&", arguments[arg])) {

      int n = fork();
      if (n == 0) {
        execve(arguments[0], arguments, NULL);
      }

    }
    else {
      system(script);
    }

  }

  return 0;
}