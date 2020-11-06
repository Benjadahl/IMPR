#include <stdio.h>
#include <ctype.h>

void readCode (char *productCode, char *warehouse, char *id, char *qualifiers);

int main (void) {
  char *input = "ATL1203S14";
  char warehouse[4];
  char id[5];
  char qualifiers[4];

  readCode(input, warehouse, id, qualifiers);

  printf("Warehouse: %s\n", warehouse);
  printf("ID: %s\n", id);
  printf("Qualifiers: %s\n", qualifiers);

  return 0;
}

void readCode (char *productCode, char *warehouse, char *id, char *qualifiers) {
  int i = 0;
  int j = 0;

  for (j = 0; !isdigit(productCode[i]); i++, j++)
    warehouse[j] = productCode[i];
  warehouse[j] = '\0';

  for (j = 0; isdigit(id[i]); i++, j++)
    id[j] = productCode[i];
  id[j] = '\0';

  for (j = 0; productCode[i] != '\0'; i++, j++)
    qualifiers[j] = productCode[i];
  qualifiers[j] = '\0';
}