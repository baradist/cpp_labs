//
// Created by o on 29.04.18.
//


#include <cstdio>
#include "book.h"

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
