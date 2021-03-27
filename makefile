CC     = gcc
CFLAGS = -Wall -Wextra -std=c11

.c.o:
	gcc $(CFLAGS) -c $<

all: program test

test: test.o
	gcc -o test test.o

program: main.o input.o my-string.o array.o
	gcc -o program main.o input.o my-string.o array.o

test.o: test.c test.h

array.o: array.c array.h
my-string.o: my-string.c my-string.h array.o

input.o: input.c input.h my-string.o array.o

main.o: main.c my-string.o input.o array.o

clean:
	rm -f *.o program