#include <stdlib.h>
#include "input.h"
#include "mystring.h"
#include "mystring-matrix.h"


static int checkType(char letter, int position) {
    if (position == 0 && letter == '#') 
        return 1;

    if (!((9 <= letter && letter <= 13) || (32 <= letter && letter <= 126)))
        return 2;
    
    return 0;
}

static void splitToWords(string line, stringMatrix *words) {
    
    string word = newString();
    
    for (int i = 0; i < sizeString(line); i++) {
        int type = checkType(getChar(line, i), i); 

        if (type != 0) {
            setType(words, type);
            break;
        }
        else if ((9 <= getChar(line, i) && getChar(line, i) <= 13) || getChar(line, i) == ' ') {
            if (sizeString(word) > 0) {
                pushBackStringMatrix(words, word);
                clearString(&word);
            }            
        }
        else {
            pushBackString(&word, getChar(line, i));
        }
    }

    killString(&word);
}

int readLine(stringMatrix *lineOfWords) { //zwraca 1 jezeli udalo sie wczytac -1 w przeciwnym przypadku
    string wholeLine = newString();

    int length = readString(&wholeLine);

    if (length == -1) {
        killString(&wholeLine);
        return -1;
    }

    pushBackString(&wholeLine, '\n'); //zapewnia wejscie do linii 32

    splitToWords(wholeLine, lineOfWords);

    if (sizeStringMatrix(*lineOfWords) == 0 && getType(*lineOfWords) == 0)
        setType(lineOfWords, 1);
        
    killString(&wholeLine);
    return 1;  
}
