#pragma once

enum eCategory{ PROSE, POESY , SCIENCE , UNDEF };
struct BOOK
{
    char author[30]; //автор
    char name[80]; //название
    int year; //год издания
    float price; //цена
    eCategory category; //категория
};

void printBook(BOOK &book);

bool isCorrectYear(int year);

bool isCorrectCategory(int number);

bool fillNewBook(BOOK &newBook);
