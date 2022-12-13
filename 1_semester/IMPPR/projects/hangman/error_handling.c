#include "error_handling.h"

#include <stdio.h> /* fprintf */
#include <stdlib.h> /* exit */

const int DIC_NOT_FOUND_ERR = -10;
const int LIST_ERR = -11;
const int USER_INPUT_ERR = -20;
const int MALLOC_ERR = -1;
const int FOPEN_ERR = -11;
const int LINE_LENGTH_ERR = -12;
const int FILE_SYNTAX_ERR = -13;
const int EMPTY_FILE_ERR = -14;

void dic_not_found_error(void) {
  fprintf(stderr, "No dictionary file found, call 'hangman help' for more infos. Exiting...\n");
  exit(DIC_NOT_FOUND_ERR);
}

void user_input_error(void) {
  fprintf(stderr, "Got to often wrong input. Exiting...\n");
  exit(USER_INPUT_ERR);
}

void list_error(void) {
  fprintf(stderr, "Error in list algorithm. Exiting...\n");
  exit(LIST_ERR);
}

void malloc_error(void) {
  fprintf(stderr, "Couldn't allocate memory. Exiting...\n");
  exit(MALLOC_ERR);
}

void empty_file_error(const char* filename) {
  fprintf(stderr, "Language file %s is empty. Exiting...\n", filename);
  exit(EMPTY_FILE_ERR);
}

void fopen_error(const char* filename) {
  fprintf(stderr, "Error opening file %s. Exiting...\n", filename);
  exit(FOPEN_ERR);
}

void line_length_error(const char* filename) {
  fprintf(stderr, "Line in dictionary file %s is to long. Exiting...\n", filename);
  exit(LINE_LENGTH_ERR);
}

void file_syntax_error(const char* filename) {
  fprintf(stderr, "Non alpha letters in language file %s, call 'hangman help' for more infos. Exiting...\n", filename);
  exit(FILE_SYNTAX_ERR);
}
