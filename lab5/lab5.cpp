
/*************************************************************
	Практическое занятие №5. 
	"Старые" потоковые функции стандартной библиотеки
	Указатели на функции
	Структуры
*************************************************************/
//#define __CRT_SECURE_NO_WARNINGS
//#include <tchar.h>
#include <iostream>
//#include <cstdio>
#include <cmath>
#include "other.h"
#include "book.h"

void task1();

void runCalc();

double Sum(const double d1, const double d2);

double Sub(const double d1, const double d2);

double Mul(const double d1, const double d2);

double Div(const double d1, const double d2);

void task2();

void task3();

BOOK globalBook;

int main() {
//    task1();
    task2();
//    task3();

    //////////////////////////////////////////////////////////////////////////////////////

    //Тема. Структуры С.
    //Задание 1. Объявите структуру BOOK, описывающую книгу
    //(автор, заглавие, год издания, цена, категория…).
    //Подумайте: какого типа могут быть поля структуры.
    //Подсказка: объявление структуры рекомендуется выносить
    //в заголовочный файл.

    //Задание 2. Создайте разными способами (глобальный, локальный, статический,
    //динамический) экземпляры (объекты) типа BOOK (без инициализации).
    //Определите - сколько памяти отводит компилятор под каждый
    //такой объект. Как инициализируются (или не инициализируются) поля
    //структуры. Подумайте: от чего зависит объем выделяемой памяти?

    globalBook;
    BOOK localBook;
    static BOOK staticBook;
    printf("Size of a global book is: %d\n", sizeof(globalBook));
    printf("Size of a local book is: %d\n", sizeof(localBook));
    printf("Size of a static book is: %d\n", sizeof(staticBook));

    //Задание 3. Заполните поля созданных объектов.
    //Замечание: если для хранения строки используется массив, необходимо
    //предусмотреть "защиту" от выхода за границы массива.

    printf("Enter a name of the book:\n");
    scanf_s("%20s", globalBook.name);
    fflush(stdin); // TODO: flush doesn't work

    printf("Enter a book's author:\n");
    scanf_s("%20s", globalBook.author);
    fflush(stdin);

    printf("Enter a book's year:\n");
    scanf_s("%4d", &globalBook.year);
    fflush(stdin);

    printf("Choose a category-number (0-2):");
    scanf_s("%1d", &globalBook.category);
    fflush(stdin);

    //Задание 4. Напишите функцию, выводящую на экран реквизиты книги.
    //Подумайте: как эффективнее передавать экземпляр BOOK в функцию.
    //Для вывода на консоль используйте функцию стандартной библиотеки
    //printf

    printBook(globalBook);

    //Задание 5. Напишите функцию для формирования полей структуры.
    //Для ввода используйте функцию стандартной библиотеки scanf
    //Замечание: неплохо заложить в такую функцию возможность проверки
    //корректности введенного значения, например, год издания не может быть
    //меьше, чем... (год появления письменности), категорию ползователь
    //должен выбирать из существующих, цена не может быть отрицательной...

    printf("Enter a name of the book:\n");
    scanf_s("%20s", localBook.name);
    fflush(stdin); // TODO: flush doesn't work

    printf("Enter a book's author:\n");
    scanf_s("%20s", localBook.author);
    fflush(stdin);

    short year;
    do {
        printf("Enter a book's year:\n");
        scanf_s("%5d", &year);
        fflush(stdin);
    } while (!isCorrectYear(year));
    localBook.year = year;

    int categoryNumber;
    do {
        printf("Choose a category-number (0-2):");
        scanf_s("%1d", &categoryNumber);
        fflush(stdin);
    } while (!isCorrectCategory(categoryNumber));
    localBook.category = static_cast<Category >(categoryNumber);

    printBook(localBook);

    return 0;
}

void task1() {
    //Тема "Старые" потоковые функции стандартной библиотеки
    //Задание 1. С помощью функции scanf сформирйуте три коэффициента: A,B,C
    int A = 0;
    int B = 0;
    int C = 0;
    printf("Enter A, B and C: ");
//	scanf_s("%d %d %d", &A, &B, &C);
    scanf_s("%d %d %d", &A, &B, &C);
    //Задание 2. Выведите (красиво!) таблицу значений y=A*x*x + B*x + C
    //при изменении x в диапазоне -2 до +2 с шагом 0.5
    printf("y = A*x*x + B*x + C\n");
    for (double x = -2; x <= 2; x += 0.5) {
        printf("x = %e => y = %e\n", x, A * x * x + B * x + C);
    }

    ///////////////////////////////////////////////////////////////////
    //Тема Указатели на функции

    //Задание 1. Указатель на функцию. "Калькулятор".
    //Напишите функции:
    //1)Sum - принимает два значения double и возвращает сумму
    //этих значений
    //2)Sub- принимает два значения double и возвращает разность
    //этих значений
    //3)Mul - *
    //4)Div - /
    //5)а для возведения в степень можете использовать функцию стандартной библиотеки
    //		- pow(). Подсказка 1: прототип функции находится в <cmath>.
    //		Подсказка 2: стандартная библиотека предоставляет несколько перегруженных
    //		вариантов этой функции, а Вам потребуется сформировать указатель на
    //		double pow(double, double);

    //Предоставьте пользователю	следующую возможность:
    //пока пользователь хочет пользоваться услугами Вашего калькулятора,
    //он может вводить два значения и знак операции
    //а Вы выводите результат. Результат получаете посредством вызова
    //соответствующей Вашей функции по указателю.
    //Предусмотрите возможность ввода непредусмотренного знака операции
    runCalc();

}

void runCalc() {
    double (*pSum)(double, double) = &Sum;
    double (*pSub)(double, double) = &Sub;
    double (*pMul)(double, double) = &Mul;
    double (*pDiv)(double, double) = &Div;
    double (*pPow)(double, double) = &pow;
    double (*pF)(double, double);
    double x1 = 0;
    double x2 = 0;
    char oper;

    while (true) {
        printf("Type an expression (for example \"1 + 2\"):");
//	scanf_s("%e %c %e", &x1, &oper, &x2);
        scanf_s("%g %c %g", &x1, &oper, &x2);

        switch (oper) {
            case '+':
                pF = pSum;
                break;
            case '-':
                pF = pSub;
                break;
            case '*':
                pF = pMul;
                break;
            case '/':
                pF = pDiv;
                break;
            case '^':
                pF = pPow;
                break;
            default:
                printf("Exit\n");
                return;
        }

        printf("%e %c %e = %e\n", x1, oper, x2, (*pF)(x1, x2));
    }
}

double Sum(const double d1, const double d2) {
    return d1 + d2;
}

double Sub(const double d1, const double d2) {
    return d1 - d2;
}

double Mul(const double d1, const double d2) {
    return d1 * d2;
}

double Div(const double d1, const double d2) {
    return d1 / d2;
}

void task2() {
    //Задание 2. Указатель на функцию в качестве аргумента.
    //Дана заготовка функции сортировки любых объектов - Sort.
    //Функция принимает следующие параметры:
    //1) указатель на первый сортируемый элемент
    //2) количество сортируемых элементов
    //3) размер элемента в байтах
    //4) указатель на функцию перестановки элементов
    //5) указатель на функцию сравнения элементов

    //2a. Напишите функцию перестановки двух целых значений -
    // SwapInt, которая принимает два void указателя и
    //меняет значения местами

    //Напишите функцию сравнения двух целых значений -
    // CmpInt, которая принимает два void указателя и
    //возвращает int результат сравнения:
    //<0 - первый элемент меньше, чем второй
    //=0 - равны
    //>0 - первый элемент больше, чем второй
    {
        int nAr[] = {5, 4, 3, 2, 1, 0, 9, 8, 7, 6};    //массив для сортировки

        int nTotal = 10; //количество элементов в массиве
        //Печать исходного массива
        printArray(nAr, nTotal);

        //Вызов сортировки
        Sort(reinterpret_cast<char *>(&nAr[0]), nTotal, sizeof(int), SwapInt, CmpInt);

        //Печать результатов сортировки
        printArray(nAr, nTotal);
    }
    //Задание 2б. По аналогии с 8а создайте вспомогательные
    //функции - SwapDouble и CmpDouble и вызовите функцию Sort
    //для сортировки массива вещественных значений.
    {
        double dAr[] = {5., 4., 3., 2., 1., 0., 9., 8., 7., 6.};    //массив для сортировки

        int nTotal = 10; //количество элементов в массиве
        //Печать исходного массива
        printArray(dAr, nTotal);

        //Вызов сортировки
        Sort(reinterpret_cast<char *>(&dAr[0]), nTotal, sizeof(double), SwapDouble, CmpDouble);

        //Печать результатов сортировки
        printArray(dAr, nTotal);
    }

    //Задание 2в*. По аналогии с 8а создайте вспомогательные
    //функции - SwapStr и CmpStr и вызовите функцию Sort
    //для сортировки массива указателей на строки.
    {
        char s[] = "QWERTY"; // TODO: ???
		char WWW[] = "WWW";
		char SDF[] = "SDF";
		char ABC[] = "ABC";
		char zxcv[] = "zxcv";
		char *arStr[] = { WWW, SDF, ABC, s, zxcv };

        int nTotal = 5; //количество элементов в массиве
        //Печать исходного массива
        printArray(arStr, nTotal);

        //Вызов сортировки
        Sort(reinterpret_cast<char *>(&arStr[0]), nTotal, sizeof(double), SwapStr, CmpStr);

        //Печать результатов сортировки
        printArray(arStr, nTotal);
    }
}

template<typename T>
void printArray(T arr[], int size) { // TODO: move to other.cpp
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
}

void task3() {
    //Задание 3. Массивы указателей на функцию.
    //Напишите несколько функций вида
    //const char* GetString1();
    //const char* GetString2();
    //		...., каждая из функций возвращает указатель на свою строку
    //(подумайте - какой адрес Вы имеете право возвращать из функции)

    //Объявите и проинициализируйте массив указателей на функции
    //GetString1,GetString2...
    const char *(*pGetString[3])(void) = {GetString1, GetString2, GetString3};


    //Введите номер функции, которую Вы хотите вызвать:
    int n;
    printf("Enter number of GetString-function:\n");
//    scanf_s("%d", n);
    n = 2;
    //Вызовите функцию
    const char *gotString = pGetString[n]();

    //Распечатайте результат
    printf("Result is: %s\n", gotString);
}
