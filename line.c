#include <stdlib.h>
#include <stdbool.h>
#include "array.h"
#include "line.h"

struct Line;

typedef struct Line line;

line newLine() {
    line new;
    new.words = newArray(sizeof(array));
    new.numbers = newArray(sizeof(long double));
    new.row = -1;
    new.isWritten = -1;

    return new;
}

void killLine(line *l) {      //usuwa tablice z pamieci
    killArray(&(l->numbers));
    killMatrix(&(l->words));
}


static bool isNaN (long double number) {
    return number != number;
}

static bool isNumber(array word, long double *number) {
    char *endptr;

    if (getChar(word, 0) == '0') {
        unsigned long long unsignedOct = strtoull(word.T.letters, &endptr, 8);
        if(endptr == word.T.letters + word.size- 1) {
            *number = (long double)unsignedOct;
            return !isNaN(*number);
        }

        unsigned long long unsignedHex = strtoull(word.T.letters + 2, &endptr, 16);
        if(endptr == word.T.letters + word.size - 1) {
            *number = (long double)unsignedHex;
            return !isNaN(*number);
        }
    }

    long double anyNumber = strtold(word.T.letters, &endptr);
    if(endptr == word.T.letters + word.size - 1) {
        *number = anyNumber;
        return !isNaN(*number);
    }

    return false;
}

line separateNumbersFromWords(array words) {
    line thisLine = newLine();

    for (int i = 0; i < words.size; i++) {
        long double number = 0;

        if (isNumber(words.T.matrix[i], &number)) {
            addOne(&(thisLine.numbers));
            thisLine.numbers.T.numbers[thisLine.numbers.size - 1] = number;
        }
        else {
            pushBackWord(&(thisLine.words), words.T.matrix[i]);
        }
    }

    return thisLine;
}

int compareLines (line firstLine, line secondLine) {
    if (firstLine.words.size != secondLine.words.size
    || firstLine.numbers.size != secondLine.numbers.size) {
        return -1;
    }
    
    for (int i = 0; i < firstLine.words.size; i++) {
        if (compareWords(&(firstLine.words.T.matrix[i]), &(secondLine.words.T.matrix[i])) != 0) {
            return -1;
        }
    }

    for (int i = 0; i < firstLine.numbers.size; i++) {
        if (firstLine.numbers.T.numbers[i] != secondLine.numbers.T.numbers[i]) {
            return -1;
        }
    }

    return 1;
}
