# Info:     Makefile for compiling "christmas tree" project
# Version:  1.0
# Author:   Rico Ukro, Kesselsdorf, Germany

APP     := christmas_tree
OBJS    := main.o tree_elements.o
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
  
