#include <stdio.h>

void tauschValue(int num1, int num2);
void tauschReference(int*, int*);

int main(int argc, char** argv) {
  int n1, n2;
  n1 = 5;
  n2 = 7;

  printf("Vor Aufrufen der Funktionen:\tn1=%d\tn2=%d\n", n1, n2);

  tauschValue(n1, n2);

  printf("Nach tauschValue:\t\tn1=%d\tn2=%d\n", n1, n2);

  tauschReference(&n1, &n2);
  
  printf("Nach tauschReference:\t\tn1=%d\tn2=%d\n", n1, n2);


  return 0;
}

void tauschValue(int num1, int num2) {
  int temp;
  temp = num1;
  num1 = num2;
  num2 = temp;
}

void tauschReference(int* num1, int* num2) {
  int temp; 
  temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

