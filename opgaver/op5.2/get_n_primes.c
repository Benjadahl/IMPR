#include <stdio.h>
#include "primes.h"

int main (void) {
  int n = 0;

  scanf("%d", &n);

  printf("%d", is_prime(n));


  return 0;
}