#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_NAME_LGT 50
#define amountOfPersons 11

typedef struct person{
  char fornavn[MAX_NAME_LGT];
  char efternavn[MAX_NAME_LGT];
  char vejnavn[MAX_NAME_LGT];
  int vejnummer;
  int postnummer;
  char bynavn[MAX_NAME_LGT];
} person;

int comparePersons (const void *p1, const void *p2);

int main (void) {
  person persons[amountOfPersons];
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

  while (fgets(curLine, MAX_NAME_LGT, ipf) != NULL) {
    i++;
  }

  printf("%d", i);

  rewind(ipf);
  i=0;

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

    i++;
  }

  qsort(persons, amountOfPersons, sizeof(person), comparePersons);

  for (i = 0; i < amountOfPersons; i++)
  {
    person *curPerson = &persons[i];

    fprintf(opf, "%s: %s\n", curPerson->bynavn, curPerson->efternavn);
  }
  

  fclose(ipf);  
  fclose(opf);  
    
  return EXIT_SUCCESS;
}

int comparePersons (const void *p1, const void *p2) {
  return strcmp(((person*) p1)->efternavn, ((person*) p2)->efternavn);
}