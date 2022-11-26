/*
 * Info:                Christmas tree main.c
 * Version:             1.0
 * Author:              Rico Ukro, Kesselsdorf, Germany
 * Course of studies:   Informationstechnik
 * Tools:               VIM TMUX
 */

#include <stdio.h>        /* in-/output */
#include <stdlib.h>       /* random/malloc/free */
#include <time.h>         /* time-function */
#include <string.h>       /* strcpy */

typedef unsigned int uint;

/* star pattern*/
const char *STAR[] = {
  "\\ /",
  "-X-",
  "/|\\",
  " A "
};
const uint  STAR_WIDTH = 3,
            STAR_HEIGHT = 4;
              
/* trunk pattern */
const char *TRUNK[] = {
  "|||"
};
const uint  TRUNK_WIDTH = 3,
            TRUNK_HEIGHT = 1; 

/* tree char elements */
const char BACKGROUND_ELEMENT = ' ';
const char START_CHAR_ELEMENT = '/';
const char FILLING_ELEMENT  = 'X';
const char STOP_CHAR_ELEMENT  = '\\';
const char ORNAMENTS[] = "*_oO";
const uint ORNAMENT_FREQUENCY = 3;

/* color constants */
const char RED[] = "\033[0;31m";
const char BROWN[] = "\033[33m";
const char YELLOW[] = "\033[1;33m";
const char GREEN[] = "\033[1;32m";
const char DARK_GREEN[] = "\033[32m";
const char WHITE[] = "\033[1;37m";

/* tree positioning offsets */
const uint X_OFFSET = 2, Y_OFFSET = 2;

/* declaration - returns the greates value of two parameters */
uint max(const uint val1, const uint val2);

int main(int argc, char ** argv) {
  /* tree constrains */
  uint top_width, top_height;
  uint tree_width, tree_height;
  uint top_start, trunk_start;
  
  /* helper to avoid having two ornaments by each other */
  char* row;
  char* last_row;

  /* for loop variables */
  uint i, j;

  /* holds number of spaces to first element in row */
  uint space_count; 

  /* setting seed for random height of tree */
  srand(time(0));

  top_height = rand() % 15 + 3;
  top_width = 1 + top_height * 2;
  tree_width = 2*X_OFFSET + max(STAR_WIDTH, max(TRUNK_WIDTH, top_width)); 
  tree_height = 2*Y_OFFSET + STAR_HEIGHT + top_height + TRUNK_HEIGHT ;
  
  top_start = STAR_HEIGHT + Y_OFFSET;
  trunk_start = Y_OFFSET + STAR_HEIGHT + top_height;

  row = malloc((tree_width + 1) * sizeof(char));
  last_row = malloc((tree_width + 1) * sizeof(char));

  /* print y offset */
  printf("%s", WHITE);
  for (i = 0; i < Y_OFFSET; i++) {
    for (j = 0; j < tree_width; j++) {
      printf("%c", BACKGROUND_ELEMENT);
    }
    printf("\n");
  }

  /* print star */
  for (i = Y_OFFSET; i < top_start; i++) {
    space_count = (top_width - STAR_WIDTH) / 2 + X_OFFSET;
    for (j = 0; j < tree_width; j++) {
      if (j < space_count || j >= (STAR_WIDTH + space_count)) {
        printf("%s%c", WHITE, BACKGROUND_ELEMENT);
      }
      else {
        printf("%s%c", YELLOW, STAR[i - Y_OFFSET][j - space_count]);
      }
    }
    row[tree_width] = '\0';
    printf("%s\n", row);
  }

  /* print top */
  for (i = top_start; i < trunk_start; i++) {
    /* calculate tree width in actual line*/
    uint line_tree_width = 1 + (i - top_start + 1) * 2;
    space_count = (top_width - line_tree_width) / 2 + X_OFFSET;
    if (i > top_start) 
      /* last_row = row */
      strcpy(last_row, row);
    for (j = 0; j < tree_width; j++) {
      /* background */
      if (j < space_count || j >= (line_tree_width + space_count)) {
        printf("%s%c", WHITE, BACKGROUND_ELEMENT);
        row[j] = BACKGROUND_ELEMENT;
      }
      /* tree start char in actual row */
      else if (j == space_count) {
        printf("%s%c", DARK_GREEN, START_CHAR_ELEMENT);
        row[j] = START_CHAR_ELEMENT; 
      }
      /* tree stop char in actual row */
      else if (j == line_tree_width + space_count - 1) {
        printf("%s%c", DARK_GREEN, STOP_CHAR_ELEMENT);
        row[j] = STOP_CHAR_ELEMENT;
      }
      /* tree fillig */
      else {
        /* check for regular BACKGROUND_ELEMENT in field left and up in depency of rand() and ORNAMENT_FREQUENCY*/
        if (!(rand() % ORNAMENT_FREQUENCY) 
            && ((i == top_start) || (last_row[j] == FILLING_ELEMENT))
            && ((j == (space_count + 1)) || (row[j - 1] == FILLING_ELEMENT) || (row[j - 1] == START_CHAR_ELEMENT) || (row[j - 1] == STOP_CHAR_ELEMENT))) {
          /* place ornament */
          printf("%s%c", RED, ORNAMENTS[rand() % ((sizeof(ORNAMENTS) - 1)/sizeof(char))]);
           row[j] = ORNAMENTS[rand() % ((sizeof(ORNAMENTS) - 1)/sizeof(char))];
        }
        else {
          printf("%s%c", GREEN, FILLING_ELEMENT); 
          row[j] = FILLING_ELEMENT; 
        }
      }
    }
    row[tree_width] = '\0';
    printf("\n");
  }

  /* print trunk */
  for (i = trunk_start; i < tree_height - Y_OFFSET; i++) {
    space_count = (top_width - TRUNK_WIDTH) / 2 + X_OFFSET;
    for (j = 0; j < tree_width; j++) {
      if (j < space_count || j >= (TRUNK_WIDTH + space_count)) {
        printf("%s%c", WHITE, BACKGROUND_ELEMENT);
      }
      else {
        printf("%s%c", BROWN, TRUNK[i - Y_OFFSET - STAR_HEIGHT - top_height][j - space_count]);
      }
    }
    printf("\n");
  } 

  /* print y offset */
  for (i = tree_height - Y_OFFSET; i < tree_height; i++) {
    for (j = 0; j < tree_width; j++) {
      printf("%s%c", WHITE, BACKGROUND_ELEMENT);
    }
    printf("\n");
  }
  free(row);
  free(last_row);
  return 0;
}

/* returns the greatest value of two */
uint max(const uint val1, const uint val2) {
  return val1 > val2 ? val1 : val2;
}
