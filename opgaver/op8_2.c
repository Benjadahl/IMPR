#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIE_MAX_EYES 6
#define DIES_TO_ROLL 7

int roll_die(void);
void roll_multiple_dies(int n, int array[]);

int main(void)
{
  int i;
  int dies[DIES_TO_ROLL];

  srand(time(NULL));

  roll_multiple_dies(DIES_TO_ROLL, dies);

  /* Print array content */
  for (i = 0; i < DIES_TO_ROLL; i++)
  {
    printf("Dice %d: %d\n", i, dies[i]);
  }
  

  return 0;
}

int roll_die(void)
{
  return (rand() % DIE_MAX_EYES) + 1;
}

void roll_multiple_dies(int n, int array[]) {
  int i = 0;

  for (i = 0; i < n; i++)
  {
    array[i] = roll_die();
  }
  
}