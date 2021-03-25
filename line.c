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
        if(endptr == word.T + sizeString(word) - 1) {
            *number = (long double)unsignedOct;
            return !isNaN(*number);
        }

        unsigned long long unsignedHex = strtoull(word.T + 2, &endptr, 16);
        if(endptr == word.T + sizeString(word) - 1) {
            *number = (long double)unsignedHex;
            return !isNaN(*number);
        }
    }

    long double anyNumber = strtold(word.T, &endptr);
    if(endptr == word.T + sizeString(word) - 1) {
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

int compareLines (line firstLine, line secondLine) {
    if (sizeStringMatrix(firstLine.words) != sizeStringMatrix(secondLine.words)
    || sizeDoubleArray(firstLine.numbers) != sizeDoubleArray(secondLine.numbers)) {
        return -1;
    }
    
    for (int i = 0; i < sizeStringMatrix(firstLine.words); i++) {
        if (compareWords(&(firstLine.words.T[i]), &(secondLine.words.T[i])) != 0) {
            return -1;
        }
    }

    for (int i = 0; i < sizeDoubleArray(firstLine.numbers); i++) {
        if (getDouble(firstLine.numbers, i) != getDouble(secondLine.numbers, i)) {
            return -1;
        }
    }

    return 1;
}
