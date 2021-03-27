#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "input.h"
#include "array.h"
#include "my-string.h"
#include "line.h"

int main() {
    int numberOfLines = 0;
    //lineArray lines = newLineArray(); 
    array words = newArray(sizeof(array));
    
    while(readLine(&words)>0) {
        numberOfLines++;
        
        switch (getType(words)) {
            case 0:  {   //comparable line
                line thisLine = separateNumbersFromWords(words);
                thisLine.row = numberOfLines;
                
                lowerCapitalisation(thisLine.words);

                sortWords(&(thisLine.words));
                sortNumbers(&(thisLine.numbers));

                pushBackLineArray(&lines, thisLine);
                break;
            }
            case 1:     //comment/empty line - nothing to do
                
                break;
            case 2:     //error line
                fprintf(stderr, "ERROR %d\n",numberOfLines);
                break;
        }

        clearWords(&words);
    }

    /*for (int i = 0; i < sizeLineArray(lines); i++) {
        if (getLine(lines, i).isWritten < 0) {
            printf("%d ",getLine(lines, i).row);
            lines.T[i].isWritten = 1;

            for (int j = i + 1; j < sizeLineArray(lines); j++) {
                if (getLine(lines, j).isWritten < 0) {
                    if (compareLines(getLine(lines, i), getLine(lines, j)) > 0) {
                        printf("%d ",getLine(lines, j).row);
                        lines.T[j].isWritten = 1;
                    }
                }
            }

            printf("\n");
        }
    }

    killLineArray(&lines);*/
    killMatrix(&words);
}