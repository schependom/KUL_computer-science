#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define SIZE 4096

char buf1[SIZE] = "hello\0";
char buf2[SIZE] = "world\0";

pthread_mutex_t lock1, lock2;
pthread_t tid1, tid2;

struct thread_args {
  char *a, *b;
  pthread_mutex_t *lock_a, *lock_b;
};

struct thread_args t1 = {
    .a = buf1, .b = buf2, .lock_a = &lock1, .lock_b = &lock2};

struct thread_args t2 = {
    .a = buf2, .b = buf1, .lock_a = &lock2, .lock_b = &lock1};

void *swap(void *args) {
  FILE *temp;

  /*
  FIX DEADLOCK:

    pthread_mutex_t *first_lock = args->lock_a;
    pthread_mutex_t *second_lock = args->lock_b;

    // Enforce locking order based on memory address
    if (first_lock > second_lock) {
        first_lock = args->lock_b;
        second_lock = args->lock_a;
    }

    pthread_mutex_lock(first_lock);
    pthread_mutex_lock(second_lock);
  */

  pthread_mutex_lock(((struct thread_args *)args)->lock_a);
  temp = tmpfile(); // create a temporary file
  fprintf(temp, "%s",
          ((struct thread_args *)args)
              ->a); // print a string to the file (from beginning address to \0
                    // = null-terminator)

  pthread_mutex_lock(((struct thread_args *)args)->lock_b);
  memcpy(((struct thread_args *)args)->a, ((struct thread_args *)args)->b,
         SIZE);
  rewind(temp); // move cursor to the start of the file
  fscanf(
      temp, "%s",
      ((struct thread_args *)args)->b); // read from file and place in buffer b
  fclose(temp);

  pthread_mutex_unlock(((struct thread_args *)args)->lock_b);
  pthread_mutex_unlock(((struct thread_args *)args)->lock_a);

  pthread_exit(0);
}

int main(void) {
  pthread_mutex_init(&lock1, NULL);
  pthread_mutex_init(&lock2, NULL);

  pthread_create(&tid1, NULL, swap,
                 (void *)&t1); // (void*) cast is required because
                               // pthread_create expects a void* argument
  pthread_create(&tid2, NULL, swap, (void *)&t2);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  printf("%s %s\n", buf1, buf2);

  return 0;
}