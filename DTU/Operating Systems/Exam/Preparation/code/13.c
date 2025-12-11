#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int a = 0;
  fork();               // 2 processes
  printf("%d\n", a);    // 2 x 0
  fork();               // 4 processes
  a++;                  // all 4 processes increment to 1
  printf("%d\n", a);    // 4 x 1
  fork();               // 8 processes
  waitpid(-1, NULL, 0); // all processes wait for any child process to finish,
                        // then exit
  exit(0);
}