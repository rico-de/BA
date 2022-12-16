# Info:     Makefile for compiling "hangman" project
# Version:  1.0
# Author:   Rico Ukro, Kesselsdorf, Germany

APP     := hangman
OBJS    := main.o error_handling.o terminal_functions.o fileman.o gameengine.o
CC      := gcc
CFLAGS  := -Wall -ansi -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition
INCLUDE :=
LIBS    :=


$(APP): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(LIBS)

.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

clean:
	-rm -f *.o  
  
