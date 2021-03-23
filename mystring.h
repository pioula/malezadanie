#ifndef MYSTRING_H
#define MYSTRING_H

struct String {
    char *T;
    int numberOfChars;
    size_t allocatedMemory;
};

typedef struct String string;

string newString();

char getChar(string array, int i);

void setChar(string *array, int i, char v);

int sizeString(string array);

void pushBackString(string *array, char c);

void clearString(string *array);

void killString(string *array);

int readString(string *array);

void printString(string array);

void lowerWord(string word);

int compareWords(const void *a, const void *b);
#endif /* MYSTRING_H */