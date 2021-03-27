CC     = gcc
CFLAGS = -Wall -Wextra -std=c11

.c.o:
	gcc $(CFLAGS) -c $<

all: program test

test: test.o
	gcc -o test test.o

program: main.o mystring.o mystring-matrix.o input.o double-array.o line.o line-array.o
	gcc -o program main.o mystring.o mystring-matrix.o input.o double-array.o line.o line-array.o

test.o: test.c test.h

mystring.o: mystring.c mystring.h
double-array.o: double-array.c double-array.h
mystring-matrix.o: mystring-matrix.c mystring-matrix.h mystring.o
line.o: line.c line.h mystring-matrix.o double-array.o
line-array.o: line-array.c line-array.h line.o

input.o: input.c input.h mystring.o mystring-matrix.o

main.o: main.c mystring.o mystring-matrix.o input.o double-array.o line.o line-array.o

clean:
	rm -f *.o program