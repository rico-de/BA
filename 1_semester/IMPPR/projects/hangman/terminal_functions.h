#ifndef TERMINAL_FUNCTIONS_H
#define TERMINAL_FUNCTIONS_H


/* clears the actual stdin */
void clear_terminal(void); 

/* set terminal color to red */
void set_red(void); 

/* prints out an 2d char array, row by row delayed by DELAY_MS */
void print_v_delayed(const char **ARR, const unsigned int HEIGHT, const unsigned int DELAY_MS); 

/* prints out a string char by char, delayed by DELAY_MS */
void print_h_delayed(const char *STR, const unsigned int DELAY_MS);

#endif /* TERMINAL_FUNCTIONS_H */
