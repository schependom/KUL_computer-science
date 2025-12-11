#include <pthread.h>
#include <stdio.h>

pthread_t thread_id[5];

void *count(void *a) {
  printf("%d\n", *(int *)a);
  pthread_exit(NULL);
}

int main(void) {
  int i;
  for (i = 1; i <= 5; i++) {
    pthread_create(&thread_id[i], NULL, count, &i);
    pthread_join(thread_id[i], NULL);
  }
  return 0;
}