# My Makefile for simple programs
# I'm choosing ANSI-C for my language
CC=gcc

# These CFLAGS are defined by the UVa
# Online Judge, so I'll make sure they
# Compile here also
CFLAGS=-lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE

all: prob101

prob101: prob101.c
	$(CC) $(CFLAGS) prob101.c -o prob101

clean:
	rm -rf *.exe* 101 *.o