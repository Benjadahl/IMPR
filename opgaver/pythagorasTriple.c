#include <stdio.h>

int main(void) {
  int m = 0,
      n = 0,
      hypontenuse = 0,
      side1 = 0,
      side2 = 0;

  printf("Enter two numbers seperated by spaces, enter the greates number first:");

  scanf(" %d %d", &m, &n);

  side1 = m * m - n * n;
  side2 = 2 * m * n;
  hypontenuse = m * m + n * n;

  printf("m: %d, n: %d \n", m, n);
  printf("Side_1: %d, Side_2: %d, Hypotenusen: %d", side1, side2, hypontenuse);

 return 0; 
}