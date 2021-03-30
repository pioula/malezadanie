#include <stdlib.h>
#ifndef ARRAY_H
#define ARRAY_H

struct Line;

typedef struct Line line;

struct Array;

typedef struct Array array;

union type_t{
    array *matrix;
    //memory is used only to realloc and malloc memory
    void *memory;
    char *letters;
    long double *numbers;
    line *lines;
    int *integers;
};

typedef union type_t type_t; 

/* T- type of element stored in array,
type - used in realloc in malloc contains the size 
of element that is stored in this array
maxNumberOfElements - the maximum of all sizes that current array has had
typeOfLine - defines the type of inputed line*/

struct Array {
    type_t T;
    size_t allocatedMemory, type;
    int size, maxNumberOfElements, typeOfLine;
};


struct Line {
    array numbers, words;
    int lineNumber;
};

/*initialise array
type - size of element that will be stored in this array */
array newArray(size_t type);

/* reallocs array t if its necessary to put one more element and
and increase its size by one */ 
void addOneMemorySpace(array *t);

//double the memory of array t
void reallocMemory(array *t);

//free all the allocated memory in this array
void killArray(array *t);

//free all the allocated memory in array of arrays
void killMatrix(array *t);

#endif /* ARRAY_H */