#include <stdio.h>

int main(void) {
  /* Define conversions to seconds */
  const int secondsInWeek = 604800;
  const int secondsInDay = 86400;
  const int secondsInHour = 3600;
  const int secondsInMinute = 60;

  /* Get input variable */
  int seconds = 0;

  printf("Enter an input in seconds:");
  scanf(" %d", &seconds);

  /* Converts the seconds to each required unit and carry over the remainder */
  const int weeks = seconds / secondsInWeek;
  seconds = seconds % secondsInWeek;

  const int days = seconds / secondsInDay;
  seconds = seconds % secondsInDay;

  const int hours = seconds / secondsInHour;
  seconds = seconds % secondsInHour;

  const int minutes = seconds / secondsInMinute;
  seconds = seconds % secondsInMinute;

  /* Print results */
  printf("Weeks: %d, Days: %d, Hours: %d, Minutes: %d, Seconds: %d\n", weeks, days, hours, minutes, seconds);

 return 0;
}