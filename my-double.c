#include "array.h"
#include "my-double.h"

//takes two pointers a, b of long doubles and return their difference
static int compareDouble(const void *a, const void *b) 
{  
    return *((long double *)a) - *((long double *)b);
} 
   
void sortNumbers(array *numbers) 
{  
    qsort(numbers->T.numbers, numbers->size, sizeof(long double), compareDouble);
}

static int compareInt(const void *a, const void *b) 
{  
    return *((int *)a) - *((int *)b);
} 
   
void sortIntegers(array *integers) 
{  
    qsort(integers->T.integers, integers->size, sizeof(int), compareInt);
} 

//takes two pointers of arrays of integers a, b and return difference of their first elements
static int compareRows(const void *a, const void *b) 
{  
    return (*((array *)a)).T.integers[0] - (*((array *)b)).T.integers[0];
} 
   
void sortRows(array *rows) 
{  
    qsort(rows->T.matrix, rows->size, sizeof(array), compareRows);
} 