#pragma once

#include <cstdio>
#include "book.h"

struct CARD_INDEX {
    BOOK **pB;
    size_t count;
    size_t cap;
};

void run();

char askForAction();

void printBooks(CARD_INDEX *pCard);

void askAndAddNewBook(CARD_INDEX *pCard);

void addBook(CARD_INDEX *pCard, BOOK *book);

void removeBook(CARD_INDEX *pCard, int index);

void exportpCardToFile(CARD_INDEX *pCard, const char *fileName);

void importpCardFromFile(CARD_INDEX *pCard, const char *fileName);

SortBy askForSortBy();

void selectionSort(BOOK *arr[], size_t size, void(*Swap)(BOOK *, BOOK *), int(*Compare)(BOOK *, BOOK *));

void Swap(BOOK *p1, BOOK *p2);

int CmpByName(BOOK *p1, BOOK *p2);

int CmpByYear(BOOK *p1, BOOK *p2);

