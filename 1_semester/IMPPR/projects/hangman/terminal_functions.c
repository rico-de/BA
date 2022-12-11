#include "terminal_functions.h"
#include <stdio.h>
#include <unistd.h>


const char RED[] = "\033[0;31m";

void clear_terminal(void) {
  printf("\e[1;1H\e[2J");
}

void set_red(void) {
  printf("%s", RED);
}

void print_v_delayed(const char **ARR, const unsigned int HEIGHT, const unsigned int DELAY_MS) { 
  size_t i;
  for (i = 0; i < HEIGHT; i++) {
    printf("%s\n", ARR[i]);
    fflush(stdout);
    usleep(1000 * DELAY_MS);
  }
}

void print_h_delayed(const char *STR, const unsigned int DELAY_MS) {
  size_t i = 0;
  while (STR[i] != '\0') {
    printf("%c", STR[i]);
    fflush(stdout);
    usleep(1000 * DELAY_MS);
    i++;
  }
}

