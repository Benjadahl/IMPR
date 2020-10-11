#include <stdio.h>

/* Prints GCD of two intergers entered into the terminal*/
int main(void) {
  int input1 = 0;
  int input2 = 0;
  int smallest = 0;
  int largest = 0;
  int i = 0;

  /* Input loop, break loop if one input is negative*/
  do {
    /*Print in the beginning of loop, as to not print when exiting*/
    if (i != 0) {
      printf("%d \n", i);
    }

    printf("Enter two numbers(seperated by space) > ");
    scanf("%d%d", &input1, &input2);

    /* Sort inputs */
    smallest = input1 < input2 ? input1 : input2;
    largest = input1 > input2 ? input1 : input2;

    /* Handle 0-edge cases */
    if (smallest == 0 || largest == 0) {
      if (smallest == 0 && largest == 0) {
        printf("Undefined\n");
      }

      i = largest;
    } else {
      /* Loop for finding GCD, decrements 1 at a time and checks if it is a common divider.
         The loop stops if it is a common divider. Value of i is now the GCD*/
      for (i = smallest; largest % i || smallest % i; i--);
    }
  } while (smallest >= 0 && largest >= 0);

  return 0;
}