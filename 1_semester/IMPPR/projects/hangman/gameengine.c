#include "gameengine.h"

#include <stdio.h> /* printf */
#include <unistd.h> /* sleep */
#include <string.h> /* strlen */
#include "hangman_figure.h"
#include "terminal_functions.h"
#include "fileman.h"

void print_figure(const size_t state, const char* word);
void check_input(const char letter);

/* holds the not correct input letters */
unsigned int wrong_letters['z' - 'a' + 1];

void gameloop(const char* searched_word) {
  int i;
  size_t state;
  char input;
  char* guess_word;
  
  state = 0;

  guess_word = malloc(strlen(searched_word) + 1);
  if (!guess_word) 
    malloc_error();
  /* clear guess_word */
  for (i = 0; i < strlen(searched_word); i++)
    guess_word[i] = ' ';
  guess_word[strlen(searched_word)] = '\0'; 
  

  /* clear wrong_letters array */
  for (i = 0; i < sizeof(wrong_letters) / sizeof(unsigned int); i++) {
    wrong_letters[i] = i + 'a';
  }
  printf("%s\n", searched_word); fflush(stdout);
  sleep(3);

  while (1) {
    clear_terminal();
    print_figure(state, guess_word);
    input = getc(stdin);
    check_input(input);
    /* state = state < FIGURE_STATES - 1 ? state + 1 : 0;
    sleep(1); */
  }

  free(guess_word);
}

void print_figure(const size_t state, const char* word) {
  size_t i, j;
  unsigned int word_len = strlen(word);

  for (i = 0; i < FIGURE_HEIGHT; i++) {
    printf("%s", FIGURE[state][i]); 
    if (i == FIGURE_HEIGHT / 2 - 1) {
      printf("\t");
      for (j = 0; j < word_len; j++) {
        if (word[j] == ' ') {
          printf("_ ");
        } else {
          printf("%c ", word[j]);
        }
      }
    }
    printf("\n");
  }

}

void check_input(const char letter) {
  
}
