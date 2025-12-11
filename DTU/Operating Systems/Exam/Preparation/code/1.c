#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int counter = 1;

void child(void) {
  counter++;
  exit(0);
}

int main(void) {
  if (fork() == 0) {
    child();
  }

  waitpid(-1, NULL, 0);

  printf("%d\n", counter);
  return 0;
}