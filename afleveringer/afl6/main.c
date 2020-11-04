#include <stdio.h>
#include <math.h>

double h (double x);
double trap (double a, double b, double n, double (*f)(double));
double sum (double i, double max, double step, double (*f)(double));

int main(void) {
  int n = 2;

  /* Use resolution 2^1 to 2^7 */
  for (n = 2; n <= 128; n = n * 2) {
    printf("trap(h)=%f n=%d \n", trap(-2, 2, n, &h), n);
  }

  return 0;
}

/* h function defines half circle from -2 to 2 */
double h (double x) {
  return sqrt(4 - pow(x, 2));
}

/* trap function calculates the area under the curve,
   a and b are the borders, n is the resolution,
   f is a function pointer for which to calculate the area under */
double trap (double a, double b, double n, double (*f)(double)) {
  double h = 0;

  h = (b - a) / n;

  return h/2*(f(a) + f(b) + 2 * sum(a, b, h, f));
}

/* sum function calculates the sum of multiple function calls */
double sum (double i, double max, double step, double (*f)(double)) {
  double result = 0;
  double x = 0;

  for (x = i; x < max; x += step)
  {
    result += f(x);
  }

  return result;
}