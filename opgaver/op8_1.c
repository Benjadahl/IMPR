#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void maaltid (void);

int main (void) {
  int i = 0;

  srand(time(NULL));

  for (i = 0; i < 25; i++) {
    maaltid();
  }

  return 0;
}

void maaltid (void) {
  enum forret {guacamole, tarteletter, lakserulle, graeskarsuppe};
  enum hovedret {gyldenkaal, hakkeboef, gullash, forlorenHare};
  enum dessert {pandekagerMedIs, gulerodskage, choklademousse, citronfromage};

  int selectedForret = (enum forret)(rand() % 4);
  int selectedHovedret = (enum hovedret)(rand() % 4);
  int selectedDessert = (enum dessert)(rand() % 4);

  switch (selectedForret)
  {
    case guacamole:
      printf("guacamole");
      break;

    case tarteletter:
      printf("tarteletter");
      break;

    case lakserulle:
      printf("lakserulle");
      break;

    case graeskarsuppe:
      printf("graeskarsuppe");
      break;
    
    default:
      printf("NA");
      break;
  }

  printf("\n");

  switch (selectedHovedret)
  {
    case gyldenkaal:
      printf("gyldenkaal");
      break;

    case hakkeboef:
      printf("hakkeboef");
      break;

    case gullash:
      printf("gullash");
      break;

    case forlorenHare:
      printf("forlorenHare");
      break;
    
    default:
      printf("NA");
      break;
  }

  printf("\n");

  switch (selectedDessert)
  {
    case pandekagerMedIs:
      printf("pandekagerMedIs");
      break;

    case gulerodskage:
      printf("gulerodskage");
      break;

    case choklademousse:
      printf("choklademousse");
      break;

    case citronfromage:
      printf("citronfromage");
      break;
    
    default:
      printf("NA");
      break;
  }

  printf("\n\n");

}