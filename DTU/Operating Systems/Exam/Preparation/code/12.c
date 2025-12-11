#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int a = 0;
  fork();              // 2 children
  fork();              // 4 children
  fork();              // 8 children
  printf("%d\n", ++a); // 8 times 1
  exit(0);
}