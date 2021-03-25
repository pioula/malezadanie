#ifndef DOUBLE_ARRAY_H
#define DOUBLE_ARRAY_H

struct DoubleArray {
    long double *T;
    int numberOfElements;
    size_t allocatedMemory;
};

typedef struct DoubleArray doubleArray;

doubleArray newDoubleArray();

long double getDouble(doubleArray array, int i);

void setDouble(doubleArray *array, int i, long double v);

int sizeDoubleArray(doubleArray array);

void pushBackDouble(doubleArray *array, long double c);

void killDoubleArray(doubleArray *array);

void sortNumbers(doubleArray *numbers);

#endif /* DOUBLE_ARRAY_H */