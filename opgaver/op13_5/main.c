#include <stdio.h>
#include <stdlib.h>


#define MAX_NAME_LGT 50

typedef struct person{
  char fornavn[MAX_NAME_LGT];
  char efternavn[MAX_NAME_LGT];
  char vejnavn[MAX_NAME_LGT];
  int vejnummer;
  int postnummer;
  char bynavn[MAX_NAME_LGT];
} person;

int main (void) {
  person persons[11];
  int i = 0;

  FILE *ipf;
  FILE *opf;

  char curLine[MAX_NAME_LGT];

  ipf = fopen("adresser.txt", "r");
  opf = fopen("out.txt", "w");

  if (ipf == NULL || opf == NULL) {
    printf("Error could not open file");
    return EXIT_FAILURE;
  }

  while(fgets(curLine, MAX_NAME_LGT, ipf) != NULL) {
    person *curPerson = &persons[i];

    sscanf(curLine, "%s %[^,], %[^1234567890]%d, %d %[^.].", 
    curPerson->fornavn,
    curPerson->efternavn,
    curPerson->vejnavn,
    &(curPerson->vejnummer),
    &(curPerson->postnummer),
    curPerson->bynavn);

    printf("%-10s %-10s %-25s %-10d  %-10d %-10s\n",
    curPerson->fornavn,
    curPerson->efternavn,
    curPerson->vejnavn,
    curPerson->vejnummer,
    curPerson->postnummer,
    curPerson->bynavn);

    fprintf(opf, "%s: %s\n", curPerson->bynavn, curPerson->efternavn);

    i++;
  }

  fclose(ipf);  
  fclose(opf);  
    
  return EXIT_SUCCESS;
}