/*
  Description:  shows arithmetica operations and the use of the printf function
  Author:       Rico Ukro
  Date:         22-11-21
*/

#include <stdio.h>

void print(void);
void arithmetic(void);

int main(int argc, char **argv) {
  print(); 
  arithmetic();
  return 0;
}

void print(void) {
  printf("Hallo Welt!\n");
}

void arithmetic(void) {
  /* declaration and initialisation of the variables */
  int ix = 42, iy = 21;
  double dx = 42.0815, dy = 3.14159; 

  /* some basic mathematic operations for integers */
  printf("%d + %d = %d\n", ix, iy, ix + iy);
  printf("%d - %d = %d\n", ix, iy, ix - iy);
  printf("%d * %d = %d\n", ix, iy, ix * iy);
  printf("%d / %d = %d\n", ix, iy, ix / iy);
  printf("%d %% %d = %d\n", ix, iy, ix % iy);
  
  /* some basic mathematic operations for doubles */
  printf("%f + %f = %f\n", dx, dy, dx + dy);
  printf("%f - %f = %f\n", dx, dy, dx - dy);
  printf("%f * %f = %f\n", dx, dy, dx * dy);
  printf("%f / %f = %f\n", dx, dy, dx / dy);
}

