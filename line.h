#include "mystring-matrix.h"
#include "double-array.h"
#ifndef LINE_H
#define LINE_H

struct Line {
    doubleArray numbers;
    stringMatrix words;
};

typedef struct Line line;

line newLine();

doubleArray getNumbers(line l);

stringMatrix getWords(line l);

void killLine(line *l);

#endif /* WORDS_H */