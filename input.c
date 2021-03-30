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

void readLine(array *lineOfWords, array inputLine) { //zwraca 1 jezeli udalo sie wczytac -1 w przeciwnym przypadku
    addOne(&inputLine);
    inputLine.T.letters[inputLine.size - 1] = '\n'; //zapewnia wejscie do linii 32
    
    splitToWords(inputLine, lineOfWords);

    if (lineOfWords->size == 0 && lineOfWords->typeOfLine == 0)
        lineOfWords->typeOfLine = 1;        
}
