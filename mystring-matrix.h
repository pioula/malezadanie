#include "mystring.h"

#ifndef MYSTRING_MATRIX_H
#define MYSTRING_MATRIX_H

struct StringMatrix {
    string *T;
    int numberOfStrings;
    size_t allocatedMemory;
    int maxNumberOfWords;
    int whatTypeOfLineItIs; //0 - comparable/ 1 - comment or empty/ 2 - error
};

typedef struct StringMatrix stringMatrix;

stringMatrix newStringMatrix();

string getString(stringMatrix array, int i);

void setString(stringMatrix *array, int i, string v);

int sizeStringMatrix(stringMatrix array);

void pushBackStringMatrix(stringMatrix *array, string c);

void clearStringMatrix(stringMatrix *array);

void killStringMatrix(stringMatrix *array);

void setType(stringMatrix *array, int type);

int getType(stringMatrix array);

void lowerCapitalisation(stringMatrix *words);

void sortWords(stringMatrix *words);

#endif /* MYSTRING_MATRIX_H */