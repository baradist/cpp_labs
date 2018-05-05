//
// Created by o on 29.04.18.
//


#include <cstdio>
#include "book.h"

void printBook(BOOK &book) {
    printf("Author: %s\n"
           "Name: %s\n"
           "Year: %d\n"
           "Price: %f\n"
           "Category: ", book.name, book.author, book.year);
    // TODO: improve
    switch (book.category) {
        case 0:
            printf("PROSE");
            break;
        case 1:
            printf("POESY");
            break;
        case 2:
            printf("SCIENCE");
            break;
        case 3:
            printf("UNDEF");
            break;
        default:
            printf("%d", book.category);
    }
    printf("\n\n");
}

bool isCorrectYear(int year) {
    return year > -2000 && year <= 2050;
}

bool isCorrectCategory(int number) {
    return number >= 0 && number < 4;
}

bool fillNewBook(BOOK &newBook) {
    printf("Enter a name of the book:\n");
    scanf("%79s", newBook.name);
    fflush(stdin); // TODO: flush doesn't work

    printf("Enter a book's author:\n");
    scanf("%29s", newBook.author);
    fflush(stdin);

    int year;
    do {
        printf("Enter a book's year:\n");
        scanf("%4d", &year);
        fflush(stdin);
    } while (!isCorrectYear(year));
    newBook.year = year;
	// TODO: ask for price
	newBook.price = 0.;
    int categoryNumber;
    do {
        printf("Choose a category-number (0-3):");
        scanf("%1d", &categoryNumber);
        fflush(stdin);
    } while (!isCorrectCategory(categoryNumber));
    newBook.category = static_cast<eCategory >(categoryNumber);
	
	return true;
}
