#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "mystring-matrix.h"

struct StringMatrix;

typedef struct StringMatrix stringMatrix;

stringMatrix newStringMatrix() {
    stringMatrix new;
    new.numberOfStrings = 0;
    new.allocatedMemory = 1;
    new.whatTypeOfLineItIs = 0;
    new.T = (string*)malloc(new.allocatedMemory * sizeof(string));

    return new;
}

string getString(stringMatrix array, int i) {     // zwraca wartosc w i
    return array.T[i];
}

void setString(stringMatrix *array, int i, string v) {     //ustawia wartosc w i
    array->T[i] = v;
}


int sizeStringMatrix(stringMatrix array) {    //zwraca liczbe znakow w tablicy
    return array.numberOfStrings;
}

static void reallocMemory(stringMatrix *array) {      //Sprawdza czy skonczyla sie pamiec, jesli tak to podwaja ja
    if (array->numberOfStrings >= (int)array->allocatedMemory) {
        array->allocatedMemory *= 2;
        array->T = realloc(array->T, array->allocatedMemory * sizeof(string));
    }
}

void pushBackStringMatrix(stringMatrix *array, string c) {     //wrzuca na sam koniec element c
    reallocMemory(array);  
    
    array->T[array->numberOfStrings] = newString();
    
    for (int i = 0; i < sizeString(c); i++) {
        pushBackString(&(array->T[array->numberOfStrings]), getChar(c, i));
    }

    array->numberOfStrings++;
}

void setType(stringMatrix *array, int type) {
    array->whatTypeOfLineItIs = type;
}

int getType(stringMatrix array) {
    return array.whatTypeOfLineItIs;
}

void clearStringMatrix(stringMatrix *array) {     //czysci cala tablice
    for (int i = 0; i < sizeStringMatrix(*array); i++) {
        clearString(&((*array).T[i]));
    }
    array->numberOfStrings = 0;
    array->whatTypeOfLineItIs = 0;
}

void killStringMatrix(stringMatrix *array) {      //usuwa tablice z pamieci
    for (int i = 0; i < (int)array->allocatedMemory; i++) {
        killString(&((*array).T[i]));
    }
    
    free(array->T);
}

void lowerCapitalisation(stringMatrix *words) {
    for (int i = 0; i < sizeStringMatrix(*words); ++i) {
        lowerWord(getString(*words, i));
    }
}
   
void sortWords(stringMatrix *words) 
{  
    qsort(words->T, sizeStringMatrix(*words), sizeof(string), compareWords); 
} 

