#pragma once

#include <cstdio>
#include "book.h"

struct CARD_INDEX
{
    BOOK **pB;
    size_t count;
    size_t cap;
};

void run();

char askForAction();

void printBooks(CARD_INDEX cardIndex);

void addBook(CARD_INDEX *pCard, BOOK &book);

void removeBook(CARD_INDEX *pCard, int index);

void exportCardIndexToFile(CARD_INDEX *pCard, const char *fileName);

void importCardIndexFromFile(CARD_INDEX *pCard, const char *fileName);
