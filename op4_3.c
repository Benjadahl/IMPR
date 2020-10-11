#include <stdio.h>

int main (void) {
  int input = 0;
  int result = 0;
  int n;
  int i;

  scanf("%d", &input);

  n = input;

  if (n > 0) {
    for (i = n; i <= 2 * n; i++) {
      result += i;
    }
  } else if (n < 0) {
    for (i = 2 * n; i <= n; i++)  {
      result += i;
    }
  }

  printf("%d", result);
  return 0;
}