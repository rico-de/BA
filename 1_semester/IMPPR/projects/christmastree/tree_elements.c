#include <stdio.h>      /* in-/output */
#include <stdlib.h>     /* malloc/free */
#include "tree_elements.h"
#include <string.h>     /* strcpy */
/*
#include <unistd.h> */     /* usleep */


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


/* returns the greater value of two */
uint max(const uint val1, const uint val2) {
  return val1 > val2 ? val1 : val2;
}

/* print the tree function */
void print_tree(const uint TOP_HEIGHT, const uint TOP_WIDTH, 
                const uint X_OFFSET, const uint Y_OFFSET) {
  
  /* constructing 2d char array that holds the tree*/ 
  const uint TREE_WIDTH = 2*X_OFFSET + max(STAR_WIDTH, max(TRUNK_WIDTH, TOP_WIDTH)); 
  const uint TREE_HEIGHT = 2*Y_OFFSET + STAR_HEIGHT + TOP_HEIGHT + TRUNK_HEIGHT ;
  
  const uint TOP_START = STAR_HEIGHT + Y_OFFSET;
  const uint TRUNK_START = Y_OFFSET + STAR_HEIGHT + TOP_HEIGHT;
  
  char* row = malloc((TREE_WIDTH + 1) * sizeof(char));
  char* last_row = malloc((TREE_WIDTH + 1) * sizeof(char));

  uint i, j;
  uint space_count; 

  /* print y offset */
  printf("%s", WHITE);
  for (i = 0; i < Y_OFFSET; i++) {
    for (j = 0; j < TREE_WIDTH; j++) {
      printf("%c", BACKGROUND_ELEMENT);
    }
    printf("\n");
  }

  /* print star */
  for (i = Y_OFFSET; i < TOP_START; i++) {
    space_count = (TOP_WIDTH - STAR_WIDTH) / 2 + X_OFFSET;
    for (j = 0; j < TREE_WIDTH; j++) {
      if (j < space_count || j >= (STAR_WIDTH + space_count)) {
        printf("%s%c", WHITE, BACKGROUND_ELEMENT);
      }
      else {
        printf("%s%c", YELLOW, STAR[i - Y_OFFSET][j - space_count]);
      }
    }
    row[TREE_WIDTH] = '\0';
    printf("%s\n", row);
  }

  /* print top */
  for (i = TOP_START; i < TRUNK_START; i++) {
    uint line_tree_width = 1 + (i - TOP_START + 1) * 2;
    space_count = (TOP_WIDTH - line_tree_width) / 2 + X_OFFSET;
    if (i > TOP_START) 
      strcpy(last_row, row);
    for (j = 0; j < TREE_WIDTH; j++) {
      if (j < space_count || j >= (line_tree_width + space_count)) {
        printf("%s%c", WHITE, BACKGROUND_ELEMENT);
        row[j] = BACKGROUND_ELEMENT;
      }
      else if (j == space_count) {
        printf("%s%c", DARK_GREEN, START_CHAR_ELEMENT);
        row[j] = START_CHAR_ELEMENT; 
      }
      else if (j == line_tree_width + space_count - 1) {
        printf("%s%c", DARK_GREEN, STOP_CHAR_ELEMENT);
        row[j] = STOP_CHAR_ELEMENT;
      }
      else {
        /* check for regular BACKGROUND_ELEMENT in field left and up in depency of rand() and ORNAMENT_FREQUENCY*/
        if (!(rand() % ORNAMENT_FREQUENCY) 
            && ((i == TOP_START) || (last_row[j] == FILLING_ELEMENT))
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
    row[TREE_WIDTH] = '\0';
    printf("\n");
  }

  /* print trunk */
  for (i = TRUNK_START; i < TREE_HEIGHT - Y_OFFSET; i++) {
    space_count = (TOP_WIDTH - TRUNK_WIDTH) / 2 + X_OFFSET;
    for (j = 0; j < TREE_WIDTH; j++) {
      if (j < space_count || j >= (TRUNK_WIDTH + space_count)) {
        printf("%s%c", WHITE, BACKGROUND_ELEMENT);
        /* row[j] = BACKGROUND_ELEMENT; */
      }
      else {
        printf("%s%c", BROWN, TRUNK[i - Y_OFFSET - STAR_HEIGHT - TOP_HEIGHT][j - space_count]);
      }
    }
    printf("\n");
  } 

  /* print y offset */
  for (i = TREE_HEIGHT - Y_OFFSET; i < TREE_HEIGHT; i++) {
    for (j = 0; j < TREE_WIDTH; j++) {
      printf("%s%c", WHITE, BACKGROUND_ELEMENT);
    }
    printf("\n");
  }
  free(row);
  free(last_row);
}  
