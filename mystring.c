#define  _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mystring.h"

struct String;

typedef struct String string;

string newString() {
    string new;
    new.numberOfChars = 0;
    new.allocatedMemory = 1;

    new.T = (char*)malloc(new.allocatedMemory * sizeof(char));

    return new;
}

char getChar(string array, int i) {     // zwraca wartosc w i
    return array.T[i];
}

void setChar(string *array, int i, char v) {     // ustawia wartosc w i
    array->T[i] = v;
}


int sizeString(string array) {    //zwraca liczbe znakow w tablicy
    return array.numberOfChars;
}

static void reallocMemory(string *array) {      //Sprawdza czy skonczyla sie pamiec, jesli tak to podwaja ja
    if (array->numberOfChars >= (int)array->allocatedMemory) {
        array->allocatedMemory *= 2;
        array->T = realloc(array->T, array->allocatedMemory * sizeof(char));
    }
}

void pushBackString(string *array, char c) {     //wrzuca na sam koniec element c
    reallocMemory(array);
    array->T[array->numberOfChars] = c;
    array->numberOfChars++;
}

void clearString(string *array) {     //czysci cala tablice
    array->T = memset(array->T,0,array->numberOfChars);
    array->numberOfChars = 0;
}

void killString(string *array) {      //usuwa tablice z pamieci
    free(array->T);
}

int readString(string *array) {     //wczytuje tablice z wejscia i zwraca jej dlugosc
    int length = getline(&(array->T),&(array->allocatedMemory),stdin);
    array->numberOfChars = length;
    return length;
}

void printString(string array) {
    for(int i = 0; i < sizeString(array); i++) {
        printf("%c",getChar(array, i));
    }
    puts("");
}

void lowerWord(string word) {
    for (int i = 0; i < sizeString(word); ++i) {
        setChar(&word, i, tolower(getChar(word, i)));
    }
}

int compareWords(const void *a, const void *b) 
{  
    return memcmp(((string *)a)->T, ((string *)b)->T, sizeString(*((string *)a)));
} 

