#include "card_index.h"

void printBooks(CARD_INDEX cardIndex) {
    for (int i = 0; i < cardIndex.count; ++i) {
		printf("Index: %d\n", i);
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

void removeBook(CARD_INDEX *pCard, int index) {
	if (index >= pCard->count || index < 0) {
		printf("Incorrect index (%d)", index);
	}
	for (size_t i = index; i < pCard->count - 1; i++)
	{
		*pCard->pB[i] = *pCard->pB[i + 1];
	}
	delete[] pCard->pB[--pCard->count];
}

void exportCardIndexToFile(CARD_INDEX *pCard, const char *fileName) {
	FILE* f = fopen(fileName, "w");
	if (!f) {
		printf("File %s isn't open!\n", fileName);
		return;
	}
	fprintf(f, "%d\n", pCard->count);
	for (size_t i = 0; i < pCard->count; i++)
	{
		fprintf(f, "%30s %80s %4d %8f %1d\n",
			pCard->pB[i]->author,
			pCard->pB[i]->name,
			pCard->pB[i]->year,
			pCard->pB[i]->price,
			pCard->pB[i]->category);
	}
	fclose(f);
}

void importCardIndexFromFile(CARD_INDEX * pCard, const char * fileName)
{
	FILE* f = fopen(fileName, "r");
	if (!f) {
		printf("File %s isn't open!\n", fileName);
		return;
	}
	size_t size;
	fscanf(f, "%d\n", &size);
	pCard->count = 0;
	BOOK *newBook;
	for (size_t i = 0; i < size; i++)
	{
		newBook = new BOOK;
		fscanf(f, "%30s %80s %4d %8f %1d",
			&newBook->author,
			&newBook->name,
			&newBook->year,
			&newBook->price,
			&newBook->category);
		addBook(pCard, *newBook);
	}
	fclose(f);
}
