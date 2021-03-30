#include "array.h"
#ifndef MY_DOUBLE_H
#define MY_DOUBLE_H

//numbers - array of long doubles. Sorts numbers in increasing order
void sortNumbers(array *numbers);

//integers - array of integers. Sorts integers in increasing order
void sortIntegers(array *integers);

//rows - matrix of integers representing numbers of lines from input
//sort rows by the smallest number in each row in increasing order
void sortRows(array *rows);

#endif /* MY_DOUBLE_H */