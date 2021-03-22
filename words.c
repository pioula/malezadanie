#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "words.h"
#include "mystring-matrix.h"
#include "mystring.h"
#include "double-array.h"
#include "line.h"


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

static void lowerWord(string word) {
    for (int i = 0; i < sizeString(word); ++i) {
        setChar(&word, i, tolower(getChar(word, i)));
    }
}

void lowerCapitalisation(stringMatrix *words) {
    for (int i = 0; i < sizeStringMatrix(*words); ++i) {
        lowerWord(getString(*words, i));
    }
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