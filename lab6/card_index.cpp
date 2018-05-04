#include "card_index.h"

void printBooks(CARD_INDEX cardIndex) {
    for (int i = 0; i < cardIndex.count; ++i) {
        printBook(*(cardIndex.pB)[i]);
    }
}

void addBook(CARD_INDEX *pCard, BOOK &book) {
    if (pCard->count >= pCard->cap) //емкость исчерпана
    {
        //перераспределяем память
        pCard->cap = pCard->cap * 3 / 2 + 1;
        BOOK *newBooks = new BOOK[pCard->cap];
        for (int i = 0; i < pCard->count; ++i) {
            newBooks[i] = *(pCard->pB)[i];
        }
        delete[] *pCard->pB;
        *pCard->pB = newBooks;
    }
    //добавляем книгу в картотеку
	pCard->pB[pCard->count++] = &book;
}
