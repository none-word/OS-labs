#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
  
  int file = open("ex1.txt", O_RDWR);
  char* s = "This is a nice day\n";
  ftruncate(file, strlen(s));
  void* addr = mmap(NULL, strlen(s), PROT_WRITE, MAP_SHARED, file, 0);
  strcpy(addr, s);
  munmap(addr, strlen(s));
  close(file);

  return 0;
}