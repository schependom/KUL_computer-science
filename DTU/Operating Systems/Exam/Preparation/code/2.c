#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define THREAD_COUNT 10000

int A = 0;
pthread_t thread_id[THREAD_COUNT];

void *count(void *input) {
  // 1. load
  // 2. increment
  // 3. store
  // ! -> NOT ATOMIC!
  // ! -> scheduler can interrupt between these steps
  A++;
  pthread_exit(NULL);
}
int main(void) {
  int i;
  for (i = 0; i < THREAD_COUNT; i++)
    pthread_create(&thread_id[i], NULL, count, NULL);
  for (i = 0; i < THREAD_COUNT; i++)
    pthread_join(thread_id[i], NULL);
  printf("%d\n", A);
  // ! -> This would print something less than 10000 most of the time
  /*
  FIXES:
      1. Use a mutex
      2. Do the create and join in the same loop
      3. Use a semaphore
  */
  return 0;
}