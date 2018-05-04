#pragma once

#include <cstdio>
#include "book.h"

struct CARD_INDEX
{
    BOOK **pB;
    size_t count;
    size_t cap;
};

void printBooks(CARD_INDEX cardIndex);

void addBook(CARD_INDEX *pCard, BOOK &book);