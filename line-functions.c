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
            //printf("xd: %Lf\n",*number);
            //puts("Oct");
            return !isNaN(*number);
        }

        unsigned long long unsignedDec = strtoull(word.T.letters, &endptr, 10);
        //printf("lol %lld",unsignedDec);
        if(endptr == word.T.letters + word.size - 1) {
            *number = (long double)unsignedDec;
          //  puts("DEC");
            return !isNaN(*number);
        }

        unsigned long long unsignedHex = strtoull(word.T.letters, &endptr, 16);
        if(endptr == word.T.letters + word.size - 1) {
            if (word.size > 1) {
                if (word.T.letters[1] == 'x' || word.T.letters[1] == 'X' ) {    
                    *number = (long double)unsignedHex;
                    //printf("xd: %Lf\n",*number);
            //        puts("HEX");
                    return !isNaN(*number);
                }
            }
        }

        if (word.size == 3) { //0x
            if (word.T.letters[0] == '0' && (word.T.letters[1] == 'x' || word.T.letters[1] == 'X')) {
                *number = (long double)0;
              //  puts("DU{S");
                return true;
            }
        }
    }
    
    if (checkForHexError(word))
        return false;
        

    long double anyNumber = strtold(word.T.letters, &endptr);
    //printf("xd: %Lf\n",anyNumber);
    if(endptr == word.T.letters + word.size - 1) {
        *number = anyNumber;
        //puts("ANY");
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
