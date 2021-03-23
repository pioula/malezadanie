#include "line.h"
#ifndef LINE_ARRAY_H
#define LINE_ARRAY_H

struct LineArray {
    line *T;
    int numberOfElements;
    size_t allocatedMemory;
};

typedef struct LineArray lineArray;

lineArray newLineArray();

line getLine(lineArray array, int i);

void setLine(lineArray *array, int i, line v);

int sizeLineArray(lineArray array);

void pushBackLineArray(lineArray *array, line c);

void killLineArray(lineArray *array);


#endif /* LINE_ARRAY_H */