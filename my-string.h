#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "array.h"
#ifndef MY_STRING_H
#define MY_STRING_H

void pushBackWord(array *t, array word);

//copies characters from word from begin to end and puts at the back of t
void pushBackPartOfWord(array *t, array word, int begin, int end);

//t - array of chars
void clearString(array *t);

//words - array of arrays of chars
void clearWords(array *words);

/* a, b - strings (char *)
if a is smaller lexicographically then returns integerer smaller than 0
if a == b then return 0
if a > b then return integer greater than 0*/
int compareWords(const void *a, const void *b);

//changes all uppercase of words to lowercase
void lowerCapitalisation(array words);

//runs qsort using compareWords - words are sorted lexicographically
void sortWords(array *words);

/*t.T is (char *). Read line from input and place it in t, and then returns length of string
if function fails it returns -1 */
int readString(array *t);

#endif /* MY_STRING_H */