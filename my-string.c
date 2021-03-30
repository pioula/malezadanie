#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my-string.h"
#include "array.h"

void pushBackWord(array *t, array word) {     //wrzuca na sam koniec element c
    if (t->maxNumberOfElements <= t->size) {
        reallocMemory(t);
        t->T.matrix[t->size] = newArray(sizeof(char));
    }

    if ((int)t->T.matrix[t->size].allocatedMemory <= word.size) {
        t->T.matrix[t->size].allocatedMemory = word.size * 2;
        t->T.matrix[t->size].T.memory = realloc(t->T.matrix[t->size].T.memory, t->T.matrix[t->size].allocatedMemory * t->T.matrix[t->size].type);
    }

    memcpy(t->T.matrix[t->size].T.letters, word.T.letters, word.size);

    t->T.matrix[t->size].size = word.size;
    
    t->size++;
    if (t->maxNumberOfElements < t->size)
        t->maxNumberOfElements = t->size;
}

void pushBackPartOfWord(array *t, array word, int begin, int end) {
    if (begin >= end)
        return;

    if (t->maxNumberOfElements <= t->size) {
        reallocMemory(t);
        t->T.matrix[t->size] = newArray(sizeof(char));
    }

    if ((int)t->T.matrix[t->size].allocatedMemory <= end - begin + 1) {
        t->T.matrix[t->size].allocatedMemory = (end - begin + 1) * 2;
        t->T.matrix[t->size].T.memory = realloc(t->T.matrix[t->size].T.memory, t->T.matrix[t->size].allocatedMemory * t->T.matrix[t->size].type);
    }

    for (int i = begin; i < end; i++) {
        t->T.matrix[t->size].T.letters[i - begin] = word.T.letters[i];
    }
    t->T.matrix[t->size].T.letters[end - begin] = '\0';

    t->T.matrix[t->size].size = end - begin + 1;

    t->size++;
    if (t->maxNumberOfElements < t->size)
        t->maxNumberOfElements = t->size;
}

void clearString(array *t) {     //czysci cala tablice
    t->T.letters = memset(t->T.letters,0,t->size * sizeof(char));
    t->size = 0;
}

void clearWords(array *words) {     //czysci cala tablice
    for (int i = 0; i < words->size; i++) {
        clearString(&(words->T.matrix[i]));
    }
    words->size = 0;
    words->typeOfLine = 0;
}

static void lowerWord(array word) {
    for (int i = 0; i < word.size; ++i) {
        word.T.letters[i] = tolower(word.T.letters[i]);
    }
}

static int min (int x, int y) {
    if (x > y) return y;
    else return x;
}

int compareWords(const void *a, const void *b) 
{
    return memcmp(((array *)a)->T.letters, ((array *)b)->T.letters, min(((array *)a)->size,((array *)b)->size));
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
