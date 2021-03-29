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
    array output = newArray(sizeof(array));

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

    sortLines(&lines);

    int i = 0;
    while ( i < lines.size) {
        addOne(&output);
        output.T.matrix[output.size - 1] = findSimilarLines(&i, lines);

        sortIntegers(&(output.T.matrix[output.size - 1]));        
    }

    sortRows(&output);

    for (int i = 0; i < output.size; i++) {
        printf("%d",output.T.matrix[i].T.integers[0]);

        for (int j = 1; j < output.T.matrix[i].size; j++) {
             printf(" %d",output.T.matrix[i].T.integers[j]);
        }

        printf("\n");
    }
    
    killMatrix(&output);
    killLineArray(&lines);
    killMatrix(&words);
    exit(0);
}