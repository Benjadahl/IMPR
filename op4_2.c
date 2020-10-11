#include <stdio.h>

int main (void) {
  int m = 0,
      n = 0,
      k = 0,
      range1 = 0,
      range2 = 0,
      result = 0,
      i = 0,
      j = 0;

  printf("m=");
  scanf("%d", &range1);
  
  printf("n=");
  scanf("%d", &range2);

  printf("k=");
  scanf("%d", &k);

  m = range2 < range1 ? range2 : range1;
  n = range1 > range2 ? range1 : range2;

  printf("m: %d n: %d k: %d \n", m, n, k);


  for (i = m; i <= n; i++) {
    if (!(i % k)) {
      for (j = i; j <= n; j += k) {
        result += j;
      }
      
      printf("Result: %d\n", result);
      return 0;
    }
  }

  return 1;
}