#include "array.h"
#ifndef LINE_H
#define LINE_H

struct Line {
    array numbers, words;
    int row;
    int isWritten;
};

typedef struct Line line;

line newLine();

void killLine(line *l);

line separateNumbersFromWords(array words);

int compareLines (line firstLine, line secondLine);

#endif /* WORDS_H */