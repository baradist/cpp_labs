#pragma once

#include <iostream>
//Прототипы используемых в данном задании функций:

void Sort(char* pcFirst, int nNumber, int size,
	 void (*Swap)(void*, void*), int (*Compare)(void*, void*) );
void SwapInt(void* p1, void* p2);
int CmpInt(void* p1, void* p2);

void SwapDouble(void* p1, void* p2);
int CmpDouble(void* p1, void* p2);

void SwapStr(void* p1, void* p2);
int CmpStr(void* p1, void* p2);

template <typename T>
void printArray(T arr[], int size);

const char* GetString1();
const char* GetString2();
const char* GetString3();


// C-structs
enum Category { CATEGORY_1, CATEGORY_2, CATEGORY_3};

struct BOOK {
    char author[21];
    char name[21];
    short year;
    Category category;
};

void printBook(BOOK &book);

bool isCorrectYear(short year);

bool isCorrectCategory(int number);

