#include <stdio.h>
#include <unistd.h>

int main(void) {
  
  char buf[5];
  int buffer = setvbuf(stdout, buf, _IOLBF, sizeof(char)*5);
  char* s = "Hello";
  for (int i = 0; i < 5; i++){
    printf("%c",s[i]);
    sleep(1);
  }

  for (int i = 0; i < 5; i++){
    printf("%c", buf[i]);
  }
  return 0;
}