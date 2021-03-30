#include "array.h"
#ifndef LINE_FUNCTIONS_H
#define LINE_FUNCTIONS_H

/* initialise line */
line newLine();

/* frees all memory alloceted by line */
void killLine(line *l);

/* frees all memory allocated by array of lines */
void killLineArray(array *t);

line separateNumbersFromWords(array words);

/* a, b are type of (line *). Decides, which line is lower.
if a < b then returns negative integer
if a > b then returns positive integer
if a == b then returns 0*/
int compareLines(const void *a, const void *b);

/* sort lines using compareLines */
void sortLines(array *lines);

/* returns array of integers that containes all numbers of lines that are similar
to lines.T.matrix[i] including number of i-th line */
array findSimilarLines(int *i, array lines);

#endif /* LINE_FUNCTIONS_H */