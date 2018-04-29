#include "other.h"

///////////////////////////////////////////////////

#include <cstring>

void Sort(char* pcFirst, int nNumber, int size,
          void (*Swap)(void*, void*), int (*Compare)(void*, void*) )
{
	int i;
	for(i=1; i<nNumber; i++)
		for(int j=nNumber-1; j>=i; j--)
		{
			char* pCurrent = pcFirst+j*size;
			char* pPrevious = pcFirst+(j-1)*size;
			if((*Compare)( pPrevious, pCurrent ) > 0)//требуется
												//переставить
				(*Swap)( pPrevious, pCurrent );
		}
}

void SwapInt(void* p1, void* p2)
{
    int t = *static_cast<int *>(p1);
    *static_cast<int *>(p1) = *static_cast<int *>(p2);
    *static_cast<int *>(p2) = t;
}

int CmpInt(void* p1, void* p2)
{
    return *static_cast<int *>(p1) - *static_cast<int *>(p2);
}

void SwapDouble(void* p1, void* p2)
{
    double t = *static_cast<double *>(p1);
    *static_cast<double *>(p1) = *static_cast<double *>(p2);
    *static_cast<double *>(p2) = t;
}

int CmpDouble(void* p1, void* p2)
{
    return *static_cast<double *>(p1) - *static_cast<double *>(p2);
}

void SwapStr(void* p1, void* p2)
{
    char *t = *static_cast<char **>(p1);
    *static_cast<char **>(p1) = *static_cast<char **>(p2);
    *static_cast<char **>(p2) = t;
}

int CmpStr(void* p1, void* p2)
{
    return strcmp(*static_cast<char **>(p1), *static_cast<char **>(p2));
}

// task 3
const char *GetString1() {
    return "String 1";
}

const char *GetString2() {
    return "String 2";
}

const char *GetString3() {
    return "String 3";
}

void printBook(BOOK &book) {
    printf("Book: %s\n"
           "Author: %s\n"
           "Year: %d\n"
           "Category: ", book.name, book.author, book.year);
    switch (book.category) {
        case 0:
            printf("CATEGORY_1");
            break;
        case 1:
            printf("CATEGORY_2");
            break;
        case 2:
            printf("CATEGORY_3");
            break;
        default:
            printf("%d", book.category);
    }
    printf("\n");
}

bool isCorrectYear(short year) {
    return year > -2000 && year <= 2050;
}

bool isCorrectCategory(int number) {
    return number >= 0 && number < 3;
}
