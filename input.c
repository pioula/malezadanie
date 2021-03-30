#include <stdlib.h>
#include "input.h"
#include "array.h"
#include "my-string.h"

/*
    letter - char
    position - position of letter in string
    checks if letter is incorrect and then returns 2, or is the first character # 
    if it's then it's comment then and we have to return 1
*/
static int checkType(char letter, int position) {
    if (position == 0 && letter == '#') 
        return 1;

    if (!((9 <= letter && letter <= 13) || (32 <= letter && letter <= 126)))
        return 2;
    
    return 0;
}

void splitLineBySpaces(array *lineOfWords, array inputLine) { 
    addOneMemorySpace(&inputLine);

    //allows to put last word of line into lineOfWord
    inputLine.T.letters[inputLine.size - 1] = '\n';

    int firstCharacter = 0;

    for (int i = 0; i < inputLine.size; i++) {
        int type = checkType(inputLine.T.letters[i], i); 

        if (type != 0) { //if the line is comment or if it is incorrect we can leave
            lineOfWords->typeOfLine = type;
            break;
        }
        else if (isspace(inputLine.T.letters[i])) {
            pushBackPartOfWord(lineOfWords, inputLine, firstCharacter, i);
            
            firstCharacter = i + 1;            
        }
    }

    //if inputLine contains only spaces then it is type of 1
    if (lineOfWords->size == 0 && lineOfWords->typeOfLine == 0)
        lineOfWords->typeOfLine = 1;        
}
