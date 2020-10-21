#include <stdio.h>

double multi_apply (double (*f)(double), int n, double s);
double half (double x);

int main (void) {
  int x = 8;

  printf("%f", multi_apply(&half, 2, x));

  return 0;
}

double multi_apply (double (*f)(double), int n, double s) {
  int sum = s;
  int i = 0;

  for (i = 0; i < n; i++) {
    sum = (*f)(sum);
  }

  return sum;
}

double half (double x) {
  return x / 2;
}

