#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "input.h"
#include "array.h"
#include "my-string.h"
#include "line-functions.h"
#include "my-double.h"

int main() {
    int numberOfLines = 0;
    array lines = newArray(sizeof(line)); 
    array words = newArray(sizeof(array));
    
    while(readLine(&words)>0) {
        numberOfLines++;

        switch (words.typeOfLine) {
            case 0:  {   //comparable line
                line thisLine = separateNumbersFromWords(words);
                thisLine.row = numberOfLines;
                
                lowerCapitalisation(thisLine.words);

                sortWords(&(thisLine.words));
                sortNumbers(&(thisLine.numbers));

                addOne(&lines);
                lines.T.lines[lines.size - 1] = thisLine;
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

    for (int i = 0; i < lines.size; i++) {
        if (lines.T.lines[i].isWritten < 0) {
            printf("%d ",lines.T.lines[i].row);
            lines.T.lines[i].isWritten = 1;

            for (int j = i + 1; j < lines.size; j++) {
                if (lines.T.lines[j].isWritten < 0) {
                    if (compareLines(lines.T.lines[i], lines.T.lines[j]) > 0) {
                        printf("%d ",lines.T.lines[j].row);
                        lines.T.lines[j].isWritten = 1;
                    }
                }
            }

            printf("\n");
        }
    }

    killLineArray(&lines);
    killMatrix(&words);
}