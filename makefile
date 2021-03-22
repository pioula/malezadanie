CC     = gcc
CFLAGS = -Wall -Wextra

.c.o:
	gcc $(CFLAGS) -c $<

all: program

program: main.o mystring.o mystring-matrix.o input.o double-array.o line.o words.o
	gcc -o program main.o mystring.o mystring-matrix.o input.o double-array.o line.o words.o

mystring.o: mystring.c mystring.h
double-array.o: double-array.c double-array.h
mystring-matrix.o: mystring-matrix.c mystring-matrix.h mystring.o
line.o: line.c line.h mystring-matrix.o double-array.o

input.o: input.c input.h mystring.o mystring-matrix.o
words.o: words.c words.h mystring.o double-array.o mystring-matrix.o line.o

main.o: main.c mystring.o mystring-matrix.o input.o double-array.o line.o words.o

clean:
	rm -f *.o program