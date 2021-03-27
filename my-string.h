#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "array.h"
#ifndef MY_STRING_H
#define MY_STRING_H

void pushBackWord(array *t, array word);

void clearString(array *t);

void clearWords(array *words);

int compareWords(const void *a, const void *b);

void lowerCapitalisation(array words);

void sortWords(array *words);

int readString(array *t);

void printString(array t);

#endif