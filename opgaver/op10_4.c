#include <stdio.h>
#include <string.h>

const char *commonEnding (char *a, char *b);

int main (void) {


  return 0;
}

const char *commonEnding (char *a, char *b) {
  int i = 0;
  int j = 0;
  char *aEnd = strrchr(a, '\0');
  char *bEnd = strrchr(a, '\0');

  printf("%d", (aEnd - 1));

  /*while (aEnd - 1) {

  }*/
  
}