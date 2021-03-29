#include "array.h"
#ifndef LINE_FUNCTIONS_H
#define LINE_FUNCTIONS_H

line newLine();

void killLine(line *l);

void killLineArray(array *t);

line separateNumbersFromWords(array words);

int compareLines(const void *a, const void *b);

void sortLines(array *lines);

array findSimilarLines(int *i, array lines);

#endif /* WORDS_H */