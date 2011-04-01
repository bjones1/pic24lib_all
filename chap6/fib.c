#include "pic24_all.h"
#include <stdio.h>

uint16 fib (uint16 n) {
  uint16 f1;

  if (n == 0) return 0;
  if (n == 1) return 1;
  f1 = fib(n-1);
  f1 = fib(n-2) + f1;
  return (f1);
}

main (void) {

  uint16  k,j;
  j = 13;
  k = fib(j);

  printf (
    "fib(%d) is: %d\n",
    j,k);
}
