/*
 *  File:         main.c 
 *  Version:      0.1
 *  Author:       Rico Ukro, Kesselsdorf, Germany
 *  Description:
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "hangman_logo.h"

void clear_terminal(void);
void malloc_error(void);

const char RED[] = "\033[0;31m";

int main(int argc, char **argv) {
  
  size_t i;

  clear_terminal();


  printf("\n\n\tWelcome to\n\n%s", RED);
  usleep(1000 * 1000);
  for (i = 0; i < HANGMAN_LOGO_HEIGHT; i++) {
    printf("%s\n", hangman_logo[i]);
    usleep(300 * 1000);
  }
  
  return 0;
}

void clear_terminal(void) {
  printf("\e[1;1H\e[2J");
}


void malloc_error(void) {
  /* TODO: print error warning */
}
