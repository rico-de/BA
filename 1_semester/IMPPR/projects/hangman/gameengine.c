#include "gameengine.h"
#include <stdio.h>  /* printf */
#include <unistd.h> /* sleep */
#include <string.h> /* strlen */
#include "error_handling.h"
#include "hangman_figure.h"
#include "terminal_functions.h"
#include "fileman.h"

/* prints out hangman figure */
void print_figure(const size_t state, const char* word, const char* searched_word);

/* check searched_word contains letter */
int word_contains_letter(const char letter, const char* searched_word);

/* holds the failed input letters */
unsigned int wrong_letters['z' - 'a' + 1];

/* puts the input char into the guessed word */
void fill_guessed_word(char input, char* guessed_word, const char* searched_word);


void gameloop(const char* searched_word) {
  int i;
  size_t state;
  char input;
  char* guessed_word;
  
  state = 0;

  guessed_word = malloc(strlen(searched_word) + 1);
  if (!guessed_word) 
    malloc_error();
  /* clear guess_word */
  for (i = 0; i < strlen(searched_word); i++)
    guessed_word[i] = ' ';
  guessed_word[strlen(searched_word)] = '\0'; 
  

  /* clear wrong_letters array */
  for (i = 0; i < sizeof(wrong_letters) / sizeof(unsigned int); i++) {
    wrong_letters[i] = 0;
  }

  /* start the game loop */
  while (1) {
    clear_terminal();
    print_figure(state, guessed_word, NULL);
    if (state) {
      printf("Wrong letters: ");
      for (i = 0; i <= 'Z' - 'A'; i ++) {
        if (wrong_letters[i]) 
          printf("%c ", 'A' + i);
      }
    }
    printf("\nGuess a letter: ");

    fflush(stdin);
    /* workaround for not working fflush(stdin) */
    while (getc(stdin) != '\n');

    scanf("%c", &input);
    /* check if input is a letter */
    if (!((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))) {
      printf("You have to enter a letter. Try again.\n");
      sleep(3);
      continue;
    }
    /* change input to uppercase */
    if (input >= 'a') 
      input = input - 'a' + 'A';

    if (word_contains_letter(input, searched_word))
      fill_guessed_word(input, guessed_word, searched_word);
    else {
      /* add input to wrong_letters array */
      wrong_letters[input - 'A'] = 1;      
      state++;
    }
    
    /* if lost game */
    if (state == FIGURE_STATES - 1) {
      clear_terminal();
      print_figure(state, NULL, searched_word); 
      return;
    }
    
    /* if won game */
    if (!strcmp(guessed_word, searched_word)) {
      clear_terminal();
      print_figure(state, guessed_word, searched_word); 
      return;
    }
    fflush(stdout);
    sleep(1);
  }

  free(guessed_word);
}

void print_figure(const size_t state, const char* word, const char* searched_word) {
  size_t i, j;
  unsigned int word_len;
  if (word)
    word_len = strlen(word);
  /* print hangman figure row by row */
  for (i = 0; i < FIGURE_HEIGHT; i++) {
    printf("%s", FIGURE[state][i]); 
    /* sideinfos */
    if (i == FIGURE_HEIGHT / 2 - 1) {
      printf("\t");
      if (word && !searched_word) {
        for (j = 0; j < word_len; j++) {
          if (word[j] == ' ') {
            printf("_ ");
          } else {
            printf("%c ", word[j]);
          }
        }
      } else if (!word && searched_word) {
        set_red();
        printf("You loose! The right word is ");
        set_default_color();
      } else if (word && searched_word) {
        set_green();
        printf("You've won! The word is ");
        set_default_color();
      }
    } else if (i == FIGURE_HEIGHT / 2 + 1 && searched_word) {
      printf("\t\t\t%s", searched_word);
    } 
    printf("\n");
  }
}

int word_contains_letter(const char letter, const char* searched_word) {
  char* p_word = (char*)searched_word;  
  do {
    if (*p_word == letter) 
      return 1;
  } while(*p_word++);

  return 0;
}

void fill_guessed_word(char input, char* guessed_word, const char* searched_word) {
  size_t i;
  const size_t len = strlen(guessed_word);
  for (i = 0; i < len; i++) {
    if (input == searched_word[i])
      guessed_word[i] = input;
  }
}
