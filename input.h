#include "array.h"

#ifndef INPUT_H
#define INPUT_H

/* takes
lineOfWords - pointer to array of strings
inputLine - string
and split inputLine into words by characters: ' ', '/r', '/v', 'n', '/f', '\t'
and then inputs them into lineOfWords. */
void splitLineBySpaces(array *lineOfWords, array inputLine);

#endif /* INPUT_H */