#include "array.h"
#include "my-double.h"

static int compareDouble(const void *a, const void *b) 
{  
    return *((long double *)a) - *((long double *)b);
} 
   
void sortNumbers(array *numbers) 
{  
    qsort(numbers->T.numbers, numbers->size, sizeof(long double), compareDouble);
} 