#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int flag = 1;
void handler(int sig) { flag = 0; }

int main(void) {
  signal(SIGTERM, handler);
  printf("%d\n", getpid());
  while (flag)
    sleep(1);
  return 7;
}