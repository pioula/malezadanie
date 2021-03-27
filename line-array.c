#include <stdlib.h>
#include <stdio.h>
#include "array.h"
#include "line-array.h"

struct LineArray;

typedef struct LineArray lineArray;

lineArray newLineArray() {
    lineArray new;
    new.numberOfElements = 0;
    new.allocatedMemory = 1;

    new.T = (line*)malloc(new.allocatedMemory * sizeof(line));

    return new;
}

line getLine(lineArray array, int i) {     // zwraca wartosc w i
    return array.T[i];
}

void setLine(lineArray *array, int i, line v) {     // ustawia wartosc w i
    array->T[i] = v;
}

int sizeLineArray(lineArray array) {    //zwraca liczbe znakow w tablicy
    return array.numberOfElements;
}

static void reallocMemory(lineArray *array) {      //Sprawdza czy skonczyla sie pamiec, jesli tak to podwaja ja
    if (array->numberOfElements >= (int)array->allocatedMemory) {
        array->allocatedMemory *= 2;
        array->T = realloc(array->T, array->allocatedMemory * sizeof(line));
    }
}

void pushBackLineArray(lineArray *array, line c) {     //wrzuca na sam koniec element c
    reallocMemory(array);
    array->T[array->numberOfElements] = c;
    array->numberOfElements++;
}

void killLineArray(lineArray *array) {      //usuwa tablice z pamieci
    for (int i = 0; i < sizeLineArray(*array); i++) {
        killLine(&((*array).T[i]));
    }
    
    free(array->T);
}