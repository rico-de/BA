# Info:     Makefile for compiling "hangman" project
# Version:  1.0
# Author:   Rico Ukro, Kesselsdorf, Germany

APP     := hangman
OBJS    := main.o
CC      := gcc
CFLAGS  := -Wall -ansi -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition -static
INCLUDE :=
LIBS    :=


$(APP): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(LIBS)

.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

clean:
	-rm -f *.o  
  
