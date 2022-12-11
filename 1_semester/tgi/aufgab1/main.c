#include <stdio.h>

/* 
 * Collatz 
 * wenn x gerade, dann x = x / 2
 * wenn x ungerade, dann x = 3 * x + 1
*/

void collatz(int);

int main(int argc, char ** argv) {
  int number;

  printf("Enter a number: ");
  fflush(stdin);
  scanf("%d", &number);

  if (!number) {
    printf("Wrong input!\n");
    return -1;
  }
  collatz(number);

  return 0;
}


void collatz(int num) {
  static int count = 0;
  printf("%d: num = %d\n", count++,  num);
  if (num == 1)
    return;
  !(num % 2) ? collatz(num / 2) : collatz(3 * num + 1);
  return;
}
