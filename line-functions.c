#include <stdlib.h>
#include <stdbool.h>
#include "array.h"
#include "line-functions.h"
#include "my-string.h"

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

void killLineArray(array *t) {      //usuwa tablice z pamieci
    for (int i = 0; i < t->size; i++) {
        killLine(&(t->T.lines[i]));
    }
    
    free(t->T.lines);
}

static bool isNaN (long double number) {
    return number != number;
}

static bool checkForHexError (array word) {
    if (word.size > 1) {
        if (word.T.letters[1] == 'x' || word.T.letters[1] == 'X' ) {
            return true;
        }
    }
    if (word.size > 2) {
        if (word.T.letters[2] == 'x' || word.T.letters[2] == 'X') {
            return true;
        }   
    }
    return false;
}

static bool isNumber(array word, long double *number) {
    char *endptr;

    if (word.T.letters[0] == '0') {
        unsigned long long unsignedOct = strtoull(word.T.letters, &endptr, 8);
        if(endptr == word.T.letters + word.size - 1) {
            *number = (long double)unsignedOct;
            return !isNaN(*number);
        }

        unsigned long long unsignedDec = strtoull(word.T.letters, &endptr, 10);
        if(endptr == word.T.letters + word.size - 1) {
            *number = (long double)unsignedDec;
            return !isNaN(*number);
        }

        unsigned long long unsignedHex = strtoull(word.T.letters, &endptr, 16);
        if(endptr == word.T.letters + word.size - 1) {
            if (word.size > 1) {
                if (word.T.letters[1] == 'x' || word.T.letters[1] == 'X' ) {    
                    *number = (long double)unsignedHex;
                    return !isNaN(*number);
                }
            }
        }

        if (word.size == 3) { //0x
            if (word.T.letters[0] == '0' && (word.T.letters[1] == 'x' || word.T.letters[1] == 'X')) {
                *number = (long double)0;
                return true;
            }
        }
    }
    
    if (checkForHexError(word))
        return false;
        

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

int compareLines(const void *a, const void *b) {
    line firstLine = *((line *)a);
    line secondLine = *((line *)b);

    if (firstLine.words.size != secondLine.words.size)
        return firstLine.words.size - secondLine.words.size;

    if (firstLine.numbers.size != secondLine.numbers.size)
        return firstLine.numbers.size - secondLine.numbers.size;

    for (int i = 0; i < firstLine.words.size; i++) {
        int tmp = compareWords(&(firstLine.words.T.matrix[i]), &(secondLine.words.T.matrix[i]));
        if (tmp != 0) {
            return tmp;
        }
    }

    for (int i = 0; i < firstLine.numbers.size; i++) {
        if (firstLine.numbers.T.numbers[i] != secondLine.numbers.T.numbers[i]) {
            if (firstLine.numbers.T.numbers[i] < secondLine.numbers.T.numbers[i]) {
                return -1;
            }
            else {
                return 1;
            }
        }
    }

    return 0;
}

void sortLines(array *lines) {
    qsort(lines->T.lines, lines->size, sizeof(line), compareLines); 
}

array findSimilarLines(int *i, array lines) {
    array row = newArray(sizeof(int));
    addOne(&row);
    row.T.integers[row.size - 1] = lines.T.lines[*i].row;
    
    int comparingLine = *i;
    (*i)++;
    if (*i < lines.size) {
        while (compareLines(&(lines.T.lines[comparingLine]), &(lines.T.lines[*i])) == 0) {
            addOne(&row);
            row.T.integers[row.size - 1] = lines.T.lines[*i].row;
            (*i)++;
            
            if (*i >= lines.size)
                break;
        }
    }

    return row;    
}
