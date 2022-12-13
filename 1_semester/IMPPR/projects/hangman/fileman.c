#include "fileman.h"

#include <dirent.h> /* opendir/readdir/closedir */
#include <stdio.h>  /* printf */
#include <string.h> /* strcmp, strlen */
#include <stdlib.h> /* malloc, free */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include "error_handling.h"


#define BUFFER_LEN 256


int is_dic_file(const char *filename) {
  const unsigned int filename_len = strlen(filename);
  const char *suffix = ".dic";
  const unsigned int suffix_len = strlen(suffix);
 
  return (filename_len > suffix_len) && !(strcmp(filename + (filename_len - suffix_len), suffix));
}
  

struct dic_file* get_dic(void) {
  unsigned int pos_count;
  struct dic_file *file, *file_begin;
  DIR *d;
  struct dirent *dir;

  pos_count = 0;
  /* allocate memory for first node */
  file = malloc(sizeof(struct dic_file));
  if (!file)
    malloc_error();
  file_begin = file;
  file->name = NULL;
  file->next = NULL;
  file->prev = NULL;
  /* open current directory to look for .dic files */
  d = opendir(".");
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      /* if file is not a .dic file skip */
      if (!is_dic_file(dir->d_name)) 
        continue;
      /* append node if it is not the first */
      if (file->name != NULL) {
        /* create new node */
        file->next = malloc(sizeof(struct dic_file));   
        if (!file->next)
          malloc_error();
        file->next->prev = file;
        file->next->next = NULL;
        file = file->next;
        
        /* set filename of newly created node */
        file->pos = pos_count++;
        file->name = malloc(strlen(dir->d_name) + 1);
        if (!file->name)
          malloc_error();
        strcpy(file->name, dir->d_name);
      } else { /* if first list element */
        file->pos = pos_count++;
        file->name = malloc(strlen(dir->d_name) + 1);
        if (!file->name)
          malloc_error();
        strcpy(file->name, dir->d_name);
      }
    }
  }
  /* returns the list if there is at least one element, otherwise NULL */
  return file_begin->name ? file_begin : NULL;  
}

char *get_word(const char *filename) {
  FILE *fp;
  unsigned int rand_line_num;
  char c_temp;
  char buffer[BUFFER_LEN];

  /* get random line number */
  srand(time(0));
  rand_line_num = get_line_count(filename);
  
  if (!rand_line_num) {
    empty_file_error(filename);
  }
  rand_line_num = rand() % rand_line_num;

  /* open file as read only */
  fp = fopen(filename, "r");
  if (!fp) { 
    fopen_error(filename);
  }
  
  /* read file char by char and file buffer */
  for (c_temp = fgetc(fp); c_temp != EOF; c_temp = fgetc(fp)) {
    static size_t i = 0;
    if (c_temp != '\n' && c_temp != '\r') {
      if (i >= BUFFER_LEN - 1) {
        fclose(fp);
        fp = NULL;
        line_length_error(filename);
      }
      /* check for only alpha letters in the current buffer */
      if (!((c_temp >= 'A' && c_temp <= 'Z') || (c_temp >= 'a' && c_temp <= 'z'))) {
        continue;
      }
        
      /* change letter to uppercase and put into buffer */
      buffer[i++] = (c_temp >= 'a' ? c_temp - 'a' + 'A' : c_temp);
    } else if (c_temp == '\n') {
      buffer[i] = '\0';
      if (rand_line_num == 0) {
        char *ret_str = malloc(strlen(buffer) - 1);
        if (!ret_str) {
          fclose(fp);
          fp = NULL;
          malloc_error();
        }
        strcpy(ret_str, buffer);

        return ret_str;
      } else {
        i = 0;
        rand_line_num--;
      }
    }
  }

  fclose(fp);
  fp = NULL;
  return NULL;
}

unsigned int get_line_count(const char *filename) {
  FILE *fp;
  unsigned int line_count = 0;
  char c_temp;

  fp = fopen(filename, "r");
  if (!fp) { 
    fopen_error(filename);
  }

  /* get number of rows in file */
  for (c_temp = getc(fp); c_temp != EOF; c_temp = getc(fp)) {
    if (c_temp == '\n')
      line_count++;
  }

  fclose(fp);
  fp = NULL;
  return line_count;
}

