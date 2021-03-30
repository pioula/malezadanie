#include <stdlib.h>
#include "array.h"

union type_t;

typedef union type_t type_t; 

struct Array;

typedef struct Array array;

struct Line;

typedef struct Line line;

//checks if allocation succeded, ptr - dynamic array
static void allocationTest (void *ptr) {
    if (ptr == NULL)
        exit(1);
}

array newArray(size_t type) {
    array new;
    new.size = 0;
    new.allocatedMemory = 8;
    new.type = type;
    new.typeOfLine = 0; //initially all of the lines are correct
    new.maxNumberOfElements = 0;
    new.T.memory = malloc(new.allocatedMemory * type);
    
    allocationTest(new.T.memory);

    return new;
}

void reallocMemory(array *t) {
    if (t->size >= (int)t->allocatedMemory) {
        t->allocatedMemory *= 2;
        t->T.memory = realloc(t->T.memory, t->allocatedMemory * t->type);

        allocationTest(t->T.memory);
    }
}

void addOneMemorySpace(array *t) {     
    reallocMemory(t);
    t->size++;
    if (t->size > t->maxNumberOfElements)
        t->maxNumberOfElements = t->size;
}

void killArray(array *t) {     
    free(t->T.memory);
}


void killMatrix(array *t) {     
    for (int i = 0; i < (int)t->maxNumberOfElements; i++) {
        killArray(&(t->T.matrix[i]));
    }
    
    free(t->T.matrix);
}

