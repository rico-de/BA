/*
 *  File:         main.c 
 *  Version:      0.1
 *  Author:       Rico Ukro, Kesselsdorf, Germany
 *  Description:
 */ 

#include <stdio.h> /* printf */
#include <unistd.h> /*usleep */
#include <stdlib.h> /* exit */
#include <string.h> /* strlen */

#include "hangman_logo.h"
#include "terminal_functions.h"
#include "fileman.h"
#include "gameengine.h"

#define DIC_NOT_FOUND_ERR -10
#define LIST_ERR -11
#define USER_INPUT_ERR -20

/* prints out the starting screen */
void start_screen(void);

/* select the language out of the available dictionary files */
char *select_lang(void);

void malloc_error(void);

int main(int argc, char **argv) {
  char *word;
/*  start_screen(); */
  word = get_word(select_lang()); 

  sleep(1);
  gameloop(word);
  
  free(word);
  return 0;
}

void start_screen(void) {
  clear_terminal();
  printf("\n\n\t");
  print_h_delayed("Hearty welcome to", 200);
  printf("\n\n");
  usleep(1000 * 1000);
  set_red();
  print_v_delayed(HANGMAN_LOGO, LOGO_HEIGHT, 300);
  set_default_color(); 
}

char *select_lang(void) {
  size_t i;
  struct dic_file *file, *file_begin;
  unsigned int input;
  unsigned int file_count;
  file = get_dic();
  if (!file) {
    fprintf(stderr, "No dictionary file found, Call hangman --help. Exiting...\n");
    exit(DIC_NOT_FOUND_ERR);
  }

  file_begin = file;
  printf("Available languages are:\n");
  while (file) {
    /* print out file names without file prefix */
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
  /* TODO: make clearer text*/
  for (i = 0; i < 3; i++) {
    printf("Choose language by entering a number: ");
    fflush(stdin); 
    if (!scanf("%u", &input) || input > file_count) {
      printf("Entered number is not valid!\n");
      if (i == 2) {
        fprintf(stderr, "Got to often wrong input. Exiting...\n");
        exit(USER_INPUT_ERR);
      }
    } else {
      break;
    }
  }
  /* look for file name that belongs to selected number */ 
  while (file) {
    if (file->pos == input) {
      return file->name;
    }
    file = file->next;
  }
  fprintf(stderr, "Error in list. Exiting...\n");
  exit(LIST_ERR);
  /* Satisfy compiler, shouldn't be reached */
  return NULL;
}

