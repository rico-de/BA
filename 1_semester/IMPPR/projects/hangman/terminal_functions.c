#include "terminal_functions.h"
#include <stdio.h>  /* printf/fflush */
#include <unistd.h> /* sleep/usleep */


/* const char RED[] = "\033[0;31m"; */
const char RED[] = "\033[31m";
const char GREEN[] = "\033[32m";
const char DEFAULT_COLOR[] = "\033[0m";

void clear_terminal(void) {
  printf("\e[1;1H\e[2J");
}

void set_default_color(void) {
  printf("%s", DEFAULT_COLOR);
}

void set_red(void) {
  printf("%s", RED);
}

void set_green(void) {
  printf("%s", GREEN);
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

