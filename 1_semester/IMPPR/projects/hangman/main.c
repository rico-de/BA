/*
 *  File:         main.c 
 *  Version:      1.1
 *  Author:       Rico Ukro, Kesselsdorf, Germany
 *  Tools:        tmux, vim, gcc, make
 *  Description:  Classic hangman game, with custom configurable dictionaries.
 *                Commandline option: hangman help
 */ 

#include <stdio.h>  /* printf */
#include <unistd.h> /* usleep */
#include <stdlib.h> /* exit */
#include <string.h> /* strlen */

#include "error_handling.h"
#include "hangman_logo.h"
#include "terminal_functions.h"
#include "fileman.h"
#include "gameengine.h"


/* prints out the starting screen */
void start_screen(void);

/* prints out the help page */
void help_screen(void);

/* select the language out of the available dictionary files */
char *select_lang(void);

/* main */
int main(int argc, char **argv) {
  if (argc >= 2) {
    if (!(strcmp(argv[1], "help"))) 
      help_screen();
    else 
      printf("Unknown argument(s).");
  } else {
    /* holds the randomly selected word out of the dictionary file */
    char *word;
    /* for play again input */
    char play_again;
    /* print start screen */
    start_screen();
    sleep(1);
    do {
      /* get a random word out of the selected language file */
      word = get_word(select_lang()); 

      /* start game loop with word */
      gameloop(word);
      
      do {
        char c;
        printf("Do you want to play again? y/n: ");
        fflush(stdout);
        /* flush stdin -> workaround for non working fflush(stdin) on linux */
        while((c = getchar()) != '\n' && c != EOF);
        play_again = getchar();
      } while ((play_again != 'y') && (play_again != 'n')); /* ask until 'y' or 'n' */
    } while (play_again != 'n'); /* play again until user enters 'n' */
    free(word);
  }
  return 0;
}

void start_screen(void) {
  clear_terminal();
  printf("\n\n\t");
  /* print each letter delayed */
  print_h_delayed("Hearty welcome to", 200);
  printf("\n\n");
  usleep(1000 * 1000);
  set_red();
  /* print each row delayed */
  print_v_delayed(HANGMAN_LOGO, LOGO_HEIGHT, 300);
  set_default_color(); 
}

void help_screen(void) {
  printf("usage: hangman [help]\n\n"
         "Game rules are the classic hangman game rules.\n\n"
         "Customize your hangman experience: \n\n"
         "  Create a custom '*.dic' dictionary file. The language selection menu in the game, creates the 'languages' out of the filenames, \nwithout the '.dic' file ending.\n"
         "In the dictionary file, every word has to be in a new line. Empty lines aren't allowed.\n"
         "A word consists of the letters [A-Z][a-z].\n");
}


char *select_lang(void) {
  size_t i;
  /* dic_file is a node in a double linked list */
  struct dic_file *file, *file_begin;
  unsigned int input;
  unsigned int file_count;

  /* get the start node of the double linked list, filled with the .dic filenames in the current directory */
  file = get_dic();
  if (!file) {
    dic_not_found_error();
  }

  /* save start node of list */
  file_begin = file;
  printf("\nAvailable languages\n");
  while (file) {
    /* print out file names without file ending */
    unsigned int lang_len = strlen(file->name) - strlen(".dic");
    file_count = file->pos;
    printf("\t(%d) ", file->pos);
    for (i = 0; i < lang_len; i++) {
      printf("%c", file->name[i]);
    } 
    printf("\n");
    file = file->next;
  }
  file = file_begin;

  /* get user input to select lang, 3 re-tries */
  for (i = 0; i < 3; i++) {
    printf("\nSelect language by entering the corresponding number: ");
    fflush(stdout);
    if (!scanf("%u", &input) || input > file_count) {
      printf("Entered number is not valid!\n");
      if (i == 2) {
        user_input_error();
      }
    } else {
      break;
    }
    while (getchar() != '\n'); /* fflush(stdin) */
  }
  /* look for file name that belongs to selected number */ 
  while (file) {
    if (file->pos == input) {
      return file->name;
    }
    file = file->next;
  }
  list_error();
  /* Satisfy compiler, shouldn't be reached */
  return NULL;
}

