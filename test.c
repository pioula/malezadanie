#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "test.h"

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

static void reallocMemory(array *t) {      //Sprawdza czy skonczyla sie pamiec, jesli tak to podwaja ja
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

int main() {
  
}

/* dla stringow

void pushBackWord(array *t, array word) {     //wrzuca na sam koniec element c
    reallocMemory(t);  
    if (t->maxNumberOfElements <= t->size) 
        t->T.matrix[t->size] = newArray(sizeof(char));

    for (int i = 0; i < word.size; i++) {
        addOne(&(t->T.matrix[t->size]));
        t->T.matrix[t->size].T.letters[i] = word.T.letters[i];
    }

    t->size++;
    if (t->maxNumberOfElements < t->size)
        t->maxNumberOfElements = t->size;
}

void setTypeOfLine(array *t, int typeOfLine) {
    t->typeOfLine = typeOfLine;
}

void clearString(array *t) {     //czysci cala tablice
    t->T.letters = memset(t->T.letters,0,t->size * sizeof(char));
    t->size = 0;
}

void clearWords(array *words) {     //czysci cala tablice
    for (int i = 0; i < words->size; i++) {
        clearString(words->T.matrix);
    }
    words->size = 0;
    words->typeOfLine = 0;
}

void lowerWord(array word) {
    for (int i = 0; i < word.size; ++i) {
        word.T.letters[i] = tolower(word.T.letters[i]);
    }
}

int compareWords(const void *a, const void *b) 
{  
    return memcmp(((array *)a)->T.letters, ((array *)b)->T.letters, (((array *)a)->size));
}


void lowerCapitalisation(array words) {
    for (int i = 0; i < words.size; ++i) {
        lowerWord(words.T.matrix[i]);
    }
}
   
void sortWords(array *words) 
{  
    qsort(words->T.matrix, words->size, sizeof(array), compareWords); 
} 

int readString(array *t) {     //wczytuje tablice z wejscia i zwraca jej dlugosc
    int length = getline(&(t->T.letters),&(t->allocatedMemory),stdin);
    t->size = length;
    return length;
}

void printString(array t) {
    for(int i = 0; i < t.size; i++) {
        printf("%c",t.T.letters[i]);
    }
    puts("");
}

*/

/*
Dla doubli
static int compareDouble(const void *a, const void *b) 
{  
    return *((long double *)a) - *((long double *)b);
} 
   
void sortNumbers(array *numbers) 
{  
    qsort(numbers->T.numbers, numbers->size, sizeof(long double), compareDouble); 
}
*/