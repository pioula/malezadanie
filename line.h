#include "mystring-matrix.h"
#include "double-array.h"
#ifndef LINE_H
#define LINE_H

struct Line {
    doubleArray numbers;
    stringMatrix words;
    int row;
    int isWritten;
};

typedef struct Line line;

line newLine();

doubleArray getNumbers(line l);

stringMatrix getWords(line l);

void killLine(line *l);

line separateNumbersFromWords(stringMatrix words);

#endif /* WORDS_H */