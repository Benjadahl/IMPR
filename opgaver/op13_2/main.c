#include <stdio.h>
#include <string.h>

#define maxLength 100

int main (int argc, char *argv[]){
  char *keyword;
  char *filename;
  char curLine[maxLength];
  FILE *ifp;

  if (argc < 3) {
    printf("Format: search [keyword] [filename]\n");
    return 1;
  }

  keyword = argv[1];
  filename = argv[2];

  ifp = fopen(filename, "r");
  
  while (fgets(curLine, maxLength, ifp) != NULL)
  {
    if (strstr(curLine, keyword) != NULL) {
      printf("%s", curLine);
    }
  }
  

  return 0;
}