#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

/* functions for miscellanious error situations */

void dic_not_found_error(void);

void user_input_error(void);

void list_error(void);

void malloc_error(void);

void file_syntax_error(const char* filename);

void empty_file_error(const char* filename);

void fopen_error(const char* filename);

void line_length_error(const char* filename);


#endif /* ERROR_HANDLING_H */
