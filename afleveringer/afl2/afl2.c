#include <stdio.h>

int main(void) {
  /* Define conversions to seconds */
  const int secondsInHour = 3600;
  const int secondsInMinute = 60;

  /* Define output variables */
  int hours = 0;
  int minutes = 0;
  int seconds = 0;

  /* Get input variable */
  int input = 0;

  printf("Enter an input in seconds:");
  scanf(" %d", &input);

  seconds = input;

  /* Converts the seconds to each required unit and carry over the remainder */
  hours = seconds / secondsInHour;
  seconds = seconds % secondsInHour;

  minutes = seconds / secondsInMinute;
  seconds = seconds % secondsInMinute;

  /* Print results */
  if (hours > 0) {
    printf(hours > 1 ? "%d hours" : "%d hour", hours);
  }

  if (minutes > 0) {
    if (hours > 0) {
      if (seconds > 0) {
        printf(", ");
      } else {
        printf(" and ");
      }
    }

    printf(minutes > 1 ? "%d minutes" : "%d minute", minutes);
  }

  if (seconds > 0) {
    if (hours > 0 || minutes > 0) {
      printf(" and ");
    }
    
    printf(seconds > 1 ? "%d seconds " : "%d second ", seconds);
  }

  printf("\n");  

 return 0;
}