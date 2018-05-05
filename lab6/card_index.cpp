#include "card_index.h"

void run() {
	//setlocale(LC_CTYPE, ".866");
	BOOK *pB = new BOOK[2];
	CARD_INDEX cardIndex = { &pB, 0, 2 };

	printf("Welcome to our library!\n");
	char actionNumber = 'x';
	while (true) {
		actionNumber = askForAction();
		switch (actionNumber) {
		case '1':
			printBooks(cardIndex);
			break;
		case '2':
			// add a new book
			{
				BOOK *newBook = new BOOK;
				if (!fillNewBook(*newBook)) {
					delete newBook;
					continue;
				}
				addBook(&cardIndex, *newBook);
			}
			break;
		case '3':
			// remove books
			int index;
			printf("Choose a book's index to remove: \n");
			scanf("%d", &index);
			removeBook(&cardIndex, index);
			break;
		case '4':
			// export
			exportCardIndexToFile(&cardIndex, "card_index.txt");
			break;
		case '5':
			// import
			importCardIndexFromFile(&cardIndex, "card_index.txt");
			break;
		case 'x':
		case 'X':
			delete[] * cardIndex.pB;
			return;
		}
	}
}

char askForAction() {
	char *actionStr = new char[2];
	printf("1) print books\n"
		"2) add a new book\n"
		"3) remove books\n"
		"4) export books to a file\n"
		"5) import books from a file\n"
		"x) EXIT\n"
		"(type 1-5 or x):\n");
	scanf("%1s", actionStr);
	char actionNumber = actionStr[0];
	delete[] actionStr;
	return actionNumber;
}

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
