#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int *counter;

void child(void) {
  ++*counter;
  exit(0);
}

int main(void) {

  counter = (int *)malloc(sizeof(int));
  *counter = 1;

  if (fork() == 0) {
    child();
  }

  waitpid(-1, NULL, 0);

  printf("%d\n", *counter);
  return 0;
}