#include <stdio.h>
#include "primes.h"

int main (void) {
  int n = 0;
  int i;

  printf("Enter max number for search: ");
  scanf("%d", &n);

  for (i = 0; i <= n; i++) {
    if (is_prime(i)) {
      printf("%d \n", i);
    }
  }

  return 0;
}