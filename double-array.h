#ifndef DOUBLE_ARRAY_H
#define DOUBLE_ARRAY_H

struct DoubleArray {
    long double *T;
    int numberOfElements;
    long unsigned int allocatedMemory;
};

typedef struct DoubleArray doubleArray;

doubleArray newDoubleArray();

long double getDouble(doubleArray array, int i);

void setDouble(doubleArray *array, int i, long double v);

int sizeDoubleArray(doubleArray array);

void pushBackDouble(doubleArray *array, long double c);

void clearDoubleArray(doubleArray *array);

void killDoubleArray(doubleArray *array);

#endif /* DOUBLE_ARRAY_H */