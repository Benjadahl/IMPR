#include <stdio.h>
#include "primes.h"

void getGoldbachPairs (int i);
int evenCeil (int i);

int main (void) {
  int min = 0;
  int max = 100;
  int c = 0;

  printf("Enter min/max number for search: ");
  scanf("%d%d", &min, &max);


  for (c = evenCeil(min); c <= max; c += 2) {
    getGoldbachPairs(c);
  }

  return 0;
}

void getGoldbachPairs (int i) {
  int j;
  int resolution = 0;

  for (j = 1; j <= i/2; j += 2) {
    if (is_prime(j) && is_prime(i - j)) {
      printf("%d = %d + %d\n", i, j, i - j);
      resolution++;
    }
  }

  if (resolution > 0) {
    printf("Resolution: %d\n", resolution);
  }
}

int evenCeil (int i) {
  return i % 2 == 0 ? i : i +1;
}