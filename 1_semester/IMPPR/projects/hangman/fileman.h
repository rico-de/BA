#ifndef FILEMAN_H
#define FILEMAN_H


/* holds the filenames of all dictionaries in current dir */
struct dic_file{
  unsigned int pos;
  char *name;
  struct dic_file *next;
  struct dic_file *prev; 
};
  
/* returns the available dictionaries */
struct dic_file* get_dic(void);

/* check the given filename for .dic ending */
int is_dic_file(const char *filename);

/* returns a randomly choosen word out of the file */
char *get_word(const char *filename);

/* returns the number of lines in file filename */
unsigned int get_line_count(const char *filename);

/* call in case of malloc err */
void malloc_error(void);

#endif /* FILEMAN_H */
