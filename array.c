#include <stdlib.h>
#include "array.h"

union type_t;

typedef union type_t type_t; 

struct Array;

typedef struct Array array;

array newArray(size_t type) {
    array new;
    new.size = 0;
    new.allocatedMemory = 1;
    new.type = type;
    new.typeOfLine = 0;
    new.maxNumberOfElements = 0;
    new.T.memory = (void *)malloc(new.allocatedMemory * type);

    return new;
}

void reallocMemory(array *t) {      //Sprawdza czy skonczyla sie pamiec, jesli tak to podwaja ja
    if (t->size >= (int)t->allocatedMemory) {
        t->allocatedMemory *= 2;
        t->T.memory = realloc(t->T.memory, t->allocatedMemory * t->type);
    }
}

void addOne(array *t) {     //wrzuca na sam koniec element c
    reallocMemory(t);
    t->size++;
}

void killArray(array *t) {      //usuwa tablice z pamieci
    free(t->T.memory);
}


void killMatrix(array *t) {      //usuwa tablice z pamieci
    for (int i = 0; i < (int)t->maxNumberOfElements; i++) {
        killArray(&(t->T.matrix[i]));
    }
    
    free(t->T.matrix);
}
