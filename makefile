CC     = gcc
CFLAGS = -Wall -Wextra -std=c11

.c.o:
	gcc $(CFLAGS) -c $<

all: program test

test: test.o
	gcc -o test test.o

program: main.o input.o my-string.o array.o line-functions.o my-double.o
	gcc -o program main.o input.o my-string.o array.o line-functions.o my-double.o

test.o: test.c test.h

array.o: array.c array.h
my-string.o: my-string.c my-string.h array.o
my-double.o: my-double.c my-double.h array.o
line-functions.o: line-functions.c line-functions.h array.o

input.o: input.c input.h my-string.o array.o

main.o: main.c my-string.o input.o array.o line-functions.o my-double.o

clean:
	rm -f *.o program