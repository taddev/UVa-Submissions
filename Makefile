# My Makefile for simple programs
# I'm choosing ANSI-C for my language
CC=gcc

# These CFLAGS are defined by the UVa
# Online Judge, so I'll make sure they
# Compile here also
CFLAGS=-lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE

all:


clean:
	rm -rf *.exe* *.o *.out