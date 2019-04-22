CC=gcc
CFLAGS=-Wall

all: program
program: program.o
program.o: program.c program.h headers.h

clean:
	rm -f program program.o
run: program
	./program
