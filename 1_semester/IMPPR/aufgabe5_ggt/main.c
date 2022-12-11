#include <stdio.h>

int ggT_k(int, int);
int ggT_m(int, int);
int ggT_r(int, int, int);
int kgV(int, int);

int main(int argc, char **argv) {
  int n1, n2;
  n2 = 105;
  n1 = 360;

  printf("Der ggt von %d und %d ist %d.\n", n1, n2, ggT_r(n1, n2, 1));

  printf("Das kgV von %d und %d ist %d.\n", n1, n2, kgV(n1, n2));

  return 0;
}

/* Subtraktions methode */
int ggT_k(int num1, int num2) {
  while(num2) {
    if (num1 > num2) {
      printf("%d - %d = %d\n", num1, num2, num1 - num2);
      num1 -= num2;
    } else {
      printf("%d - %d = %d\n", num2, num1, num2 - num1);
      num2 -= num1;
    }
   }
  return num1;
}

/* modulo version */
int ggT_m(int num1, int num2) {
  int rest = 1;
  while(rest) {
    rest = num1 % num2;
    printf("%d %% %d = %d\n", num1, num2, rest);
    num1 = num2;
    num2 = rest;
  }
  return num1;
}

/* rekursiv, mit optionaler Eingabe der Schritte */
int ggT_r(int num1, int num2, int ausgabe) {
  int rest;
  if (ausgabe) 
    printf("Zahl1: %d, Zahl2: %d\n", num1, num2);
  if (num1 <= 0 || num2 <= 0)
    return -1;
  rest = num1 % num2;
  if (rest) 
    return ggT_r(num2, rest, ausgabe);
  else
    return num2;
}

int kgV(int num1, int num2) {
  return (num1*num2) / ggT_r(num1, num2, 0);
}

