#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int accounts[2];
pthread_mutex_t lock[2];
pthread_t tid1, tid2;

struct Transact {
  int from;
  int to;
  int amount;
};

struct Transact t1 = {.from = 0, .to = 1, .amount = 10};
struct Transact t2 = {.from = 1, .to = 0, .amount = 20};

void *transfer(void *in) {
  struct Transact trs = *(struct Transact *)in;

  // ! Should always be locked in the SAME order to prevent deadlock:
  //
  // if (trs.from < trs.to) {
  //   a = trs.from;
  //   b = trs.to;
  // } else {
  //   a = trs.to;
  //   b = trs.from;
  // }
  //
  // pthread_mutex_lock(&lock[a]);
  // sleep(1);
  // pthread_mutex_lock(&lock[b]);

  pthread_mutex_lock(&lock[trs.from]);
  sleep(1);
  pthread_mutex_lock(&lock[trs.to]);

  accounts[trs.from] -= trs.amount;
  accounts[trs.to] += trs.amount;

  pthread_mutex_unlock(&lock[trs.to]);
  pthread_mutex_unlock(&lock[trs.from]);

  pthread_exit(0);
}

int main(void) {
  pthread_mutex_init(&lock[0], NULL);
  pthread_mutex_init(&lock[1], NULL);

  accounts[0] = 100;
  accounts[1] = 100;

  pthread_create(&tid1, NULL, transfer, (void *)&t1);
  pthread_create(&tid2, NULL, transfer, (void *)&t2);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  printf("%d\n", accounts[0]);
}