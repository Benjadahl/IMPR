#include <stdio.h>
#include <math.h>
#include "CuTest.h"

/* Prototype functions */
void solveQuadraticEquation(double a, double b, double c);

int main(void) {
  int looping = 1;
  double a = 0, b = 0, c = 0;

  do {
    /* Load in coeficients from user */
    printf("Enter coeficients a, b, and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    looping = a != 0 || b != 0 || c != 0;

    if (looping) {
      solveQuadraticEquation(a, b, c);
    }
  } while (looping);

  return 0;
}

/* Calculate discriminant given a, b, and c values */
double getDiscriminant(double a, double b, double c) {
  double discriminant;
  discriminant = b * b - 4 * a * c;
  return discriminant;
}

/* Test discriminant function */
void testGetDiscriminant1 (CuTest *tc) {
  int actual = getDiscriminant(1, 2, 3);
  int expected = -8;
  CuAssertIntEquals(tc, expected, actual);
}

void testGetDiscriminant2 (CuTest *tc) {
  int actual = getDiscriminant(2, 3, 4);
  int expected = -23;
  CuAssertIntEquals(tc, expected, actual);
}

CuSuite* getDiscriminantGetSuite() {
  CuSuite* suite = CuSuiteNew();

  SUITE_ADD_TEST(suite, testGetDiscriminant1);
  SUITE_ADD_TEST(suite, testGetDiscriminant2);

  return suite;
}

/* Calculate the first root given a, b and discriminant input */
double getRoot1(double a, double b, double discriminant) {
  double root1;
  root1 = (-b + sqrt(discriminant))/(2*a);
  return root1;
}

/* Calculate the second root given a, b and discriminant input */
double getRoot2(double a, double b, double discriminant) {
  double root2;
  root2 = (-b - sqrt(discriminant))/(2*a);
  return root2;
}

/* Prints roots of the quadratic equation a * x*x + b * x + c = 0 */
void solveQuadraticEquation(double a, double b, double c){
  double discriminant, root1, root2;

  discriminant = getDiscriminant(a, b, c);

  if (discriminant < 0) {
    printf("No roots\n");
  }
  else if (discriminant == 0){
    root1 = getRoot1(a, b, discriminant);
    printf("One root: %f\n", root1);
  }
  else {
    root1 = getRoot1(a, b, discriminant);
    root2 = getRoot2(a, b, discriminant);
    printf("Two roots: %f and %f\n", root1, root2);
  }

}   