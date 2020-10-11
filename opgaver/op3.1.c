#include <stdio.h>
#include <math.h>

double roundSpecific(double input, int n) {
  int m = pow(10, n);
  return roundf(input * m) / m;
}

int main(void) {
  double x = 0, y= 0, r=0;

  printf("x=");
  scanf("%lf", &x);

  printf("y=");
  scanf("%lf", &y);

  printf("r=");
  scanf("%lf", &r);

  double l = sqrt(pow(x, 2) + pow(y, 2));

  r = roundSpecific(r, 2);
  l = roundSpecific(l, 2);

  printf("l: %lf \n", l);

  printf("r: %lf \n", r);

  printf(l > r ? "Outside" : l == r ? "On" : "Inside \n");

 return 0;
}

