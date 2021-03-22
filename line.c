#include <stdlib.h>
#include "mystring-matrix.h"
#include "double-array.h"
#include "line.h"

struct Line;

typedef struct Line line;

line newLine() {
    line new;
    new.words = newStringMatrix();
    new.numbers = newDoubleArray();

    return new;
}

doubleArray getNumbers(line l) {     // zwraca wartosc w i
    return l.numbers;
}

stringMatrix getWords(line l) {     // zwraca wartosc w i
    return l.words;
}

void killLine(line *l) {      //usuwa tablice z pamieci
    killDoubleArray(&(l->numbers));
    killStringMatrix(&(l->words));
}


