/*
  Info:     Christmas tree main.c
  Version:  0.1
  Author:   Rico Ukro, Kesselsdorf, Germany
*/

#include <stdio.h>        /* in-/output */
#include <stdlib.h>       /* random */
#include <time.h>         /* time-function */
#include "tree_elements.h"


int main(int argc, char ** argv) {
  const uint  X_OFFSET = 2, 
              Y_OFFSET = 2;
  uint top_height, top_width;
  /* setting seed for random height of tree */
  srand(time(0));
  top_height = rand() % 15 + 3;
  top_width = 1 + top_height * 2;

  print_tree(top_height, top_width, X_OFFSET, Y_OFFSET);

  return 0;
}
/* x offset bug */
