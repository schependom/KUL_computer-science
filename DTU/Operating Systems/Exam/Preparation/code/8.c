#include <pthread.h>
#include <stdio.h>

#define THREAD_COUNT 100000

// All global variables are shared between threads in the SAME process
int A = 0;
pthread_mutex_t m; // lock
pthread_t thread_id[THREAD_COUNT];

void *count(void *input) {
  pthread_mutex_lock(&m);
  A++;
  pthread_mutex_unlock(&m);
  pthread_exit(NULL);
}

int main(void) {
  int i;
  pthread_mutex_init(&m, NULL);
  for (i = 0; i < THREAD_COUNT; i++)
    pthread_create(&thread_id[i], NULL, count, NULL);
  for (i = 0; i < THREAD_COUNT; i++)
    pthread_join(thread_id[i], NULL);
  printf("%d\n", A);
  return 0;
}