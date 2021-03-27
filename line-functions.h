#include "array.h"
#ifndef LINE_FUNCTIONS_H
#define LINE_FUNCTIONS_H

line newLine();

void killLine(line *l);

void killLineArray(array *t);

line separateNumbersFromWords(array words);

int compareLines (line firstLine, line secondLine);

#endif /* WORDS_H */