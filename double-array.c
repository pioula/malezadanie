#include <stdlib.h>
#include <stdio.h>
#include "double-array.h"

struct DoubleArray;

typedef struct DoubleArray doubleArray;

doubleArray newDoubleArray() {
    doubleArray new;
    new.numberOfElements = 0;
    new.allocatedMemory = 1;

    new.T = (long double*)malloc(new.allocatedMemory * sizeof(long double));

    return new;
}

long double getDouble(doubleArray array, int i) {     // zwraca wartosc w i
    return array.T[i];
}

void setDouble(doubleArray *array, int i, long double v) {     // ustawia wartosc w i
    array->T[i] = v;
}

int sizeDoubleArray(doubleArray array) {    //zwraca liczbe znakow w tablicy
    return array.numberOfElements;
}

static void reallocMemory(doubleArray *array) {      //Sprawdza czy skonczyla sie pamiec, jesli tak to podwaja ja
    if (array->numberOfElements >= (int)array->allocatedMemory) {
        array->allocatedMemory *= 2;
        array->T = realloc(array->T, array->allocatedMemory * sizeof(long double));
    }
}

void pushBackDouble(doubleArray *array, long double c) {     //wrzuca na sam koniec element c
    reallocMemory(array);
    array->T[array->numberOfElements] = c;
    array->numberOfElements++;
}

void killDoubleArray(doubleArray *array) {      //usuwa tablice z pamieci
    free(array->T);
}

static int myCompare(const void *a, const void *b) 
{  
    return *((long double *)a) - *((long double *)b);
} 
   
void sortNumbers(doubleArray *numbers) 
{  
    qsort(numbers->T, sizeDoubleArray(*numbers), sizeof(long double), myCompare); 
}
