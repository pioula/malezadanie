#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef TEST_H
#define TEST_H

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






#endif /* TEST_H */