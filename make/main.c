#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include "sqr.h"
#include "mult_acc.h"

double x = 9;

void * conta_a_toa(void * ptr) {
  volatile unsigned int i;
  printf("Na thread...\n");
  for(i=0; i < 0xffffffff ;i++);
  printf("conta finalizou na thread\n");
  pthread_exit(NULL);
  return NULL;
}

int main(void) {
  double y;
  int z;

  pthread_t thr;

#ifdef OPTION2
  y = 2;
#else
  x = 1.4142;
#endif

  int r = pthread_create(&thr, NULL, conta_a_toa, NULL);
  if (r == 0) {
    printf("Ok criando a thread\n");
  }
  else {
    perror("criando a thread");
    exit(1);
  }
  printf("O quadrado de %g é %g\n", y, sqr(y));
  /* inicializar x no módulo mult_acc */
  mult_set_x(1);
  z = mult_acc(2);
  printf("multacc=%d\n", z);
  z = mult_acc(4);
  printf("multacc=%d\n", z);

  /* volatile unsigned int i; */
  /* for(i=0; i < 0xffffffff ;i++); */

  sleep(10);

  printf("conta finalizou na main\n");

  pthread_join(thr, NULL);
  return 0;
}
