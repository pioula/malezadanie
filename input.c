#include <stdlib.h>
#include "input.h"
#include "array.h"
#include "my-string.h"

static int checkType(char letter, int position) {
    if (position == 0 && letter == '#') 
        return 1;

    if (!((9 <= letter && letter <= 13) || (32 <= letter && letter <= 126)))
        return 2;
    
    return 0;
}

static void splitToWords(array line, array *words) {
    int firstCharacter = 0;

    for (int i = 0; i < line.size; i++) {
        int type = checkType(line.T.letters[i], i); 

        if (type != 0) {
            words->typeOfLine = type;
            break;
        }
        else if (isspace(line.T.letters[i])) {
            pushBackPartOfWord(words, line, firstCharacter, i);
            
            firstCharacter = i + 1;            
        }
    }
}

/*static void splitToWords(array line, array *words) {
    
    array word = newArray(sizeof(char));
    
    for (int i = 0; i < line.size; i++) {
        int type = checkType(line.T.letters[i], i); 

        if (type != 0) {
            words->typeOfLine = type;
            break;
        }
        else if (isspace(line.T.letters[i])) {
            if (word.size > 0) {
                addOne(&word);
                word.T.letters[word.size-1] = '\0';
                pushBackWord(words, word);
                clearString(&word);
            }            
        }
        else {
            addOne(&word);
            word.T.letters[word.size - 1] = line.T.letters[i];
        }
    }

    killArray(&word);
}*/

int readLine(array *lineOfWords) { //zwraca 1 jezeli udalo sie wczytac -1 w przeciwnym przypadku
    array wholeLine = newArray(sizeof(char));

    int length = readString(&wholeLine);

    if (length == -1) {
        killArray(&wholeLine);
        return -1;
    }

    addOne(&wholeLine);
    wholeLine.T.letters[wholeLine.size - 1] = '\n'; //zapewnia wejscie do linii 32
    
    splitToWords(wholeLine, lineOfWords);

    if (lineOfWords->size == 0 && lineOfWords->typeOfLine == 0)
        lineOfWords->typeOfLine = 1;
        
    killArray(&wholeLine);
    return 1;  
}
