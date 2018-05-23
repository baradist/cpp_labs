#include <cstring>
#include "card_index.h"

void run() {
    //setlocale(LC_CTYPE, ".866");
    BOOK **pB = new BOOK *[2];
    CARD_INDEX pCard = {pB, 0, 2};

//    void (*pSwap[2])(BOOK *, BOOK *) = {SwapByYear, Swap};
    int (*pCmp[2])(BOOK *, BOOK *) = {CmpByName, CmpByYear};

    printf("Welcome to our library!\n");
    char actionNumber = 'x';
    while (true) {
        actionNumber = askForAction();
        switch (actionNumber) {
            case '1':
                printBooks(&pCard);
                break;
            case '2':
                // add a new book
            {
                askAndAddNewBook(&pCard);
            }
                break;
            case '3':
                // remove books
                int index;
                printf("Choose a book's index to remove: \n");
                scanf("%d", &index);
                removeBook(&pCard, index);
                break;
            case '4':
                // export
                exportpCardToFile(&pCard, "card_index.txt");
                break;
            case '5':
                // import
                importpCardFromFile(&pCard, "card_index.txt");
                break;
            case '6':
                // sort
            {
                SortBy sortBy = askForSortBy();
                selectionSort(pCard.pB, pCard.count, Swap, pCmp[sortBy]);
                break;
            }
            case 'x':
            case 'X':
                delete[] *pCard.pB;
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
           "6) sort books\n"
           "x) EXIT\n"
           "(type 1-5 or x):\n");
    scanf("%1s", actionStr);
    char actionNumber = actionStr[0];
    delete[] actionStr;
    return actionNumber;
}

void printBooks(CARD_INDEX *pCard) {
    for (int i = 0; i < pCard->count; ++i) {
        printf("Index: %d\n", i);

        printBook((*pCard).pB[i]);
    }
}

void askAndAddNewBook(CARD_INDEX *pCard) {
    BOOK *pNewBook = new BOOK;
    if (!askToFillNewBook(pNewBook)) {
        delete pNewBook;
        return;
    }
    addBook(pCard, pNewBook);
}

void addBook(CARD_INDEX *pCard, BOOK *book) {
    if (pCard->count >= pCard->cap) //емкость исчерпана
    {
        //перераспределяем память
        pCard->cap = pCard->cap * 3 / 2 + 1;
        BOOK **pBNew = new BOOK *[pCard->cap];
        for (int i = 0; i < pCard->count; ++i) {
            pBNew[i] = (*pCard).pB[i];
        }
        delete[] (*pCard).pB;
        (*pCard).pB = pBNew;
    }
    //добавляем книгу в картотеку
    (*pCard).pB[pCard->count] = book;
    pCard->count++;
}

void removeBook(CARD_INDEX *pCard, int index) {
    if (index >= pCard->count || index < 0) {
        printf("Incorrect index (%d)", index);
    }
    for (size_t i = index; i < pCard->count - 1; i++) {
        *pCard->pB[i] = *pCard->pB[i + 1];
    }
    delete[] pCard->pB[--pCard->count];
}

void exportpCardToFile(CARD_INDEX *pCard, const char *fileName) {
    FILE *f = fopen(fileName, "w");
    if (!f) {
        printf("File %s isn't open!\n", fileName);
        return;
    }
    fprintf(f, "%d\n", pCard->count);
    for (size_t i = 0; i < pCard->count; i++) {
        fprintf(f, "%30s %80s %4d %8f %1d\n",
                pCard->pB[i]->author,
                pCard->pB[i]->name,
                pCard->pB[i]->year,
                pCard->pB[i]->price,
                pCard->pB[i]->category);
    }
    fclose(f);
}

void importpCardFromFile(CARD_INDEX *pCard, const char *fileName) {
    FILE *f = fopen(fileName, "r");
    if (!f) {
        printf("File %s isn't open!\n", fileName);
        return;
    }
    int size;
    fscanf(f, "%d\n", &size);
    pCard->count = 0;
    BOOK *newBook;
    for (size_t i = 0; i < size; i++) {
        newBook = new BOOK;
        fscanf(f, "%30s %80s %4d %8f %1d",
               newBook->author,
               newBook->name,
               &newBook->year,
               &newBook->price,
               &newBook->category);
        addBook(pCard, newBook);
    }
    fclose(f);
}

SortBy askForSortBy() {
    printf("how to sort?\n");
    printf("0 - by name, 1 - by year\n");
    int i;
    scanf("%d", &i);
    fseek(stdin, 0, 0);
    return static_cast<SortBy> (i);
}

void selectionSort(BOOK *arr[], size_t size, void(*Swap)(BOOK *, BOOK *), int(*Compare)(BOOK *, BOOK *)) {
    if (size < 2) {
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        // find min value
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (Compare(arr[j], arr[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // swap with first not sorted
            Swap(arr[minIndex], arr[i]);
        }
    }
}

void Swap(BOOK *p1, BOOK *p2) {
    BOOK t = *p1;
    *p1 = *p2;
    *p2 = t;
}

int CmpByName(BOOK *p1, BOOK *p2) {
    return strcmp(p1->name, p2->name);
}

int CmpByYear(BOOK *p1, BOOK *p2) {
    return p1->year - p2->year;
}
