# compiler to use
CC = gcc
# flags to compiler
CFLAGS = -Wall -g -O3
# include
INCLUDES = -I/include/ -Iinclude/
# source files
SRCS = src/bits.c src/cheney.c src/trees.c src/test.c
# auto-generate the object files
OBJS = $(SRCS:.c=.o)
# define the executable file
MAIN = cheney

all:    $(MAIN)

$(MAIN): $(OBJS) 
	        $(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS)

.c.o:
	        $(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	        $(RM) *.o *~ $(MAIN) $(OBJS)