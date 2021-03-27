#include <stdlib.h>
#ifndef ARRAY_H
#define ARRAY_H

struct Array;

typedef struct Array array;

union type_t{
    array *matrix;
    void *memory;
    char* letters;
    long double* numbers;
};

typedef union type_t type_t; 

struct Array {
    type_t T;
    size_t allocatedMemory, type;
    int size, maxNumberOfElements, typeOfLine;
};

array newArray(size_t type);

void addOne(array *t);

void reallocMemory(array *t);

void killArray(array *t);

void killMatrix(array *t);

#endif /* ARRAY_H */