#include <stdio.h>
#include <stdlib.h>

int calculations = 0;

typedef struct fibonacci
{
  long n;
  long value;
  struct fibonacci *previous;
} fibonacci;

long fib(long n)
{ /* working program: fib-memo.c - an exercise*/
  long result;

  static fibonacci *prevPtr;
  fibonacci *searcPtr = prevPtr;
  fibonacci *newResult;

  while (searcPtr != NULL)
  {
    if (searcPtr->n == n)
    {
      return searcPtr->value;
    }
    else
    {
      searcPtr = searcPtr->previous;
    }
  }

  if (n == 0)
    result = 0;
  else if (n == 1)
    result = 1;
  else
  {
    result = fib(n - 1) + fib(n - 2);
  }

  calculations++;
  newResult = malloc(sizeof(fibonacci));
  newResult->value = result;
  newResult->n = n;
  newResult->previous = prevPtr;
  prevPtr = newResult;

  return result;
}

int main(void)
{
  long i;

  for (i = 0; i < 1000; i++)
    printf("Fib(%li) = %li\n", i, fib(i));

  printf("%d calculations made\n", calculations);
  return 0;
}
