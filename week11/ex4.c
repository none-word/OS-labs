#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(){
  int file = open("ex1.txt", O_RDWR);
  int file_out = open("ex1.memcpy.txt", O_RDWR);
  struct stat buffer;
  fstat(file, &buffer);
  ftruncate(file_out, buffer.st_size);
  void* address1 = mmap(NULL, buffer.st_size, PROT_READ, MAP_SHARED, file, 0);
  void* address2 = mmap(NULL, buffer.st_size, PROT_WRITE, MAP_SHARED, file_out, 0);
  memcpy(address2, address1, buffer.st_size);
  close(file);
  close(file_out);
}