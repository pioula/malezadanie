#include <stdlib.h>
#include <stdbool.h>
#include "mystring-matrix.h"
#include "double-array.h"
#include "line.h"

struct Line;

typedef struct Line line;

line newLine() {
    line new;
    new.words = newStringMatrix();
    new.numbers = newDoubleArray();
    new.row = -1;
    new.isWritten = -1;

    return new;
}

doubleArray getNumbers(line l) {     // zwraca wartosc w i
    return l.numbers;
}

stringMatrix getWords(line l) {     // zwraca wartosc w i
    return l.words;
}

void killLine(line *l) {      //usuwa tablice z pamieci
    killDoubleArray(&(l->numbers));
    killStringMatrix(&(l->words));
}


static bool isNaN (long double number) {
    return number != number;
}

static bool isNumber(string word, long double *number) {
    char *endptr;

    if (getChar(word, 0) == '0') {
        unsigned long long unsignedOct = strtoull(word.T, &endptr, 8);
        if(endptr == word.T + sizeString(word)) {
            *number = (long double)unsignedOct;
            return !isNaN(*number);
        }
    }

    long double anyNumber = strtod(word.T, &endptr);
    if(endptr == word.T + sizeString(word)) {
        *number = anyNumber;
        return !isNaN(*number);
    }

    return false;
}

line separateNumbersFromWords(stringMatrix words) {
    line thisLine = newLine();

    for (int i = 0; i < sizeStringMatrix(words); i++) {
        long double number = 0;

        if (isNumber(getString(words, i), &number)) {
            pushBackDouble(&(thisLine.numbers), number);
        }
        else {
            pushBackStringMatrix(&(thisLine.words), getString(words, i));
        }
    }

    return thisLine;
}

