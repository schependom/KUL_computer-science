#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  fork();
  fork();
  printf("a\n");
  exit(0);
}