#pragma once

enum Category { CATEGORY_1, CATEGORY_2, CATEGORY_3};

struct BOOK {
    char author[21];
    char name[21];
    short year;
    Category category;
};

void printBook(BOOK &book);

bool isCorrectYear(short year);

bool isCorrectCategory(int number);
