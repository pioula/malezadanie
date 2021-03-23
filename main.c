#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "mystring-matrix.h"
#include "input.h"
#include "line.h"
#include "double-array.h"


int main() {
    int numberOfLines = 0;
    stringMatrix words = newStringMatrix();
    
    while(readLine(&words)>0) {
        numberOfLines++;
        
        switch (getType(words)) {
            case 0:  {   //comparable line
                line thisLine = separateNumbersFromWords(words);
                lowerCapitalisation(&(thisLine.words));
                
                sortWords(&(thisLine.words));
                sortNumbers(&(thisLine.numbers));
                
                
                break;
            }
            case 1:     //comment/empty line - nothing to do
                
                break;
            case 2:     //error line
                
                break;
        }

        clearStringMatrix(&words);
    }
    killStringMatrix(&words);
}