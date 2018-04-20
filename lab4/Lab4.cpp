
/*************************************************************
	Практическое занятие №3. Функции.
	Объявление, определение, вызов.
	Передача параметров. Возвращение значения.
	Указатели на функции
*************************************************************/
#include <iostream>
//#include <tchar.h>
//#include <cstdio>
//#include <cstdarg>
#include "Lab4.h"
#include "other.h"

using namespace std;

//#define	  stop __asm nop


int main() {
    task1();
    task2();
//    task3();
    task4();

	//Задание 5. Создайте одномерный массив (размерность вычисляется в процессе
	//выполнения программы), заполните его значениями.
	//Напишите функцию, которая добавляет в массив ервре значение только при
	//условии, что такого значения в массиве еще нет. Подсказка: при этом размер
	//массива должен увеличиться! Функция НЕ ДОЛЖНА ничего возвращать.

    //Для проверки напишите функцию, которая выводит значения всех элементов на экран


/*
	//Задание 6. Рекурсивные функции. Напишите рекурсивную функцию вычисления
	//суммы первых N натуральных чисел.



*/
/*
	//Задание 7а. Функции с переменным числом параметров.
	//Напишите функцию (дана заготовка VarArgs, не использующая
	// макросы), которая принимает переменное число аргументов
	// типа int и выводит на печать число принятых параметров и
	// их значения.
	// Признаком конца списка является нулевое значение.
	
	int nN1=5, nN2=11, nN3=4, nN4=7, nN5=-1;
	VarArgs(nN1,0);	
	VarArgs(nN1,nN2,0);	
	VarArgs(nN1,nN2,nN3,nN4,nN5,0);	
	stop


	//Задание 7б. Модифицируйте функцию 5а с помощью макросов
	// va_start, va_arg, va_end
*/




    //Задание 8. Возвращение адреса.
    //Напишите функцию, которая находит минимальное значение в массиве,
    // таким образом, чтобы ее вызов можно было использовать слева от знака
    // равенства: *MyMin(параметры) = 0;



    return 0;
}

void task1() {
    cout << "task1" << endl;

    /////////////////////////////////////////////////////////////////////////////
    // Задание 1. Ссылки.
    //Объявите ссылку на тип double. Посредством ссылки измените значение
    double val = 42;
    double &rVal = val;
    cout << val << endl;
    rVal += 1;
    cout << val << endl;

    //Раскомментируйте две следующих строчки. Что следует сделать, чтобы
    //linker не выдавал ошибки при создании exe-файла Подсказка: ссылка ref
    //должна быть внешней
    extern int ref;
    ref++;

    //Раскомментируйте следующую строку. Что следует сделать, чтобы
    //компилятор не выдавал ошибки
    const int &ref1 = 1;

    //Задан указатель:
    char c = 'A';
    char *pc = &c;
    //Объявите ссылку на указатель.
    char *&rpc = pc;
    cout << rpc << endl;
    // Посредством ссылки измените
    //а) значение по адресу
    *rpc = 'B';
    cout << rpc << endl;
    //б) сам адрес
    rpc++;
    cout << rpc << endl;
}

void task2() {

    //Задание 2. Отличия при передаче параметров а) по значению,
    // б) по ссылке, в) по указателю
    //Объявите и определите три функции , которые увеличивают заданное
    //с помощью параметра значение на 1 ( а) - IncByValue(),
    // б) - IncByPointer(), в) - IncByReference() ).
    //Проверьте правильность с помощью отладчика.
    //
    //Замечание: объявления функций принято помещать в заголовочный файл
    int val = 1;//значение этой переменной должно быть увеличено с помощью
    //каждой из функций на единицу
    printf("Initial val = %d\n", val);
    IncByValue(val); // it should be like: val = IncByValue(val); otherwise, it doesn't work
    printf("After IncByValue, val = %d\n", val);
    IncByPointer(&val);
    printf("After IncByPointer, val = %d\n", val);
    IncByReference(val);
    printf("After IncByReference, val = %d\n", val);


    //Задание 2а. Передача параметров c помощью указателя и по ссылке.
    //Перегруженные имена функций.
    //Создайте функцию (функции) Swap(), которая меняет значения
    //переменных nX и nY местами.
    // а)Функция должна принимать два указателя на int, оперируя с
    //которыми менять значения переменных в вызывающей программе
    // б)Функция должна принимать две ссылки на int
    //Проверьте правильность с помощью приведенного ниже фрагмента.

    int nX = 1;
    int nY = -1;
    printf("nX = %d, nY = %d\n", nX, nY);
    Swap(&nX, &nY);    //поменяли местами значения nX и nY с
    //помощью указателей на nX и nY
    printf("nX = %d, nY = %d\n", nX, nY);
    Swap(nX, nY);    //а теперь обратно с помощью ссылок на nX и nY
    printf("nX = %d, nY = %d\n", nX, nY);
}

int IncByValue(int val) {
    return ++val;
}

void IncByPointer(int *pInt) {
    (*pInt)++;
}

void IncByReference(int &val) {
    val++;
}

template<typename T>
void Swap(T *pVal, T *pVal1) {
    T t = *pVal;
    *pVal = *pVal1;
    *pVal1 = t;
}

template<typename T>
void Swap(T &val, T &val1) {
    T t = val;
    val = val1;
    val1 = t;
}

void task3() {

    //Задание 3. Указатели на массивы в качестве аргументов.
    //3a.Напишите два варианта функции поиска минимального элемента
    //1. во встроенном двухмерном массиве

    //1.Например:
    int ar[N][M] = {{1, 2, 3, 5},
                    {5, 6, 7, 8}};
    //подумайте - как и где должны быть заданы N и M
    int res = Min(ar);
    printf("The minimum is %d\n", res);

    //2. в динамическом двухмерном массиве (обе размерности вычисляются)
    size_t sizeX = 4;
    size_t sizeY = 2;
    int **ppInt = new int *[sizeY];
    for (int i = 0; i < sizeY; i++) {
        ppInt[i] = new int[sizeX];
    }
    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            ppInt[y][x] = rand() % 20 - 10;
        }
    }
    printArray(ppInt, sizeX, sizeY);
    res = Min(ppInt, sizeX, sizeY);
    printf("The minimum is %d\n", res);
    for (int i = 0; i < sizeY; i++) {
        delete[] ppInt[i];
    }
    delete[] ppInt;
    ppInt = nullptr;

    //3b. Напишите функцию сравнения двух строк - MyStrCmp():
    //Функция должна принимать два указателя на сравниваемые
    //строки (возможно Вы должны указать компилятору, что функция
    //не имеет права модифицировать содержимое строк)
    //Функция должна возвращать отрицательное значение, если
    //первая строка лексиграфически меньше второй, 0 - если
    //они равны и положительное значение, если первая строка
    //больше второй.
    //Вспомните, что признаком конца строки является нулевой байт.
    //Создайте две строки для сравнения:
    char *string1 = new char[21];
    char *string2 = new char[21];
    printf("Enter the first string (max 20 chars):");
    cin >> string1;
    printf("Enter the second string (max 20 chars):");
    cin >> string2;

    //Вызовите функцию сравнения
    res = MyStrCmp(string1, string2);
    //Выведите результат сравнения с помощью cout:
    cout << res << endl;
}

template<typename T>
int Min(T **ppT, size_t X, size_t Y) {
    T *p = *ppT;
    T min = *p;
    for (int i = 1; i < X * Y; ++i) {
        if (*(p + i) < min) {
            min = *p;
        }
    }
    return min;
}

int Min(const int pInt[N][M]){
    const int *p = pInt[0];
    int min = *p;
    for (int i = 1; i < N * M; ++i) {
        if (*(p + i) < min) {
            min = *p;
        }
    }
    return min;
}

int MyStrCmp(const char *s1, const char *s2) {
    for (int i = 0; s1[i] || s2[i]; ++i) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}

template<typename T>
void printArray(T **arr, size_t X, size_t Y) {
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            cout << arr[y][x] << ' ';
        }
        cout << endl;
    }
}

void task4() {

    //Задание 4.Ссылки в качестве параметров. Передача указателя на встроенный
    //массив в качестве параметра функции.
    //Напишите две взаимодополняющие друг друга функции:
    //1.  ... DayOfYear(...)
    //- преобразует день месяца (число,месяц и год задаются в качестве параметров)
    //в порядковый день года(возвращаемое значение)
    //2. ... DayOfMonth(...) - функция преобразует порядковый день года в день месяца
    // (принимает год и порядковый день года в качестве параметров и должна сформировать
    // день месяца и номер месяца и каким-то образом сообщить эти значения вызывающей процедуре)

    //Проверьте работоспособность обеих функций с помощью следующего фрагмента:


    //В процессе вычислений Вам придется учитывать "високосный - невисокосный" год.
    //Для этого предлагается в каждую функцию в качестве одного из параметров передавать
    //данные приведенного ниже двухмерного массива nDayTab

    int nDayTab[2][12] = {
            {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, //невисокосный год
            {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};    //високосный год

    testTask4(nDayTab, 2018);
    testTask4(nDayTab, 2000);
}

inline
void testTask4(int nDayTab[2][12], int testYear) {
    int isLeap = __isleap(testYear) ? 1 : 0;
    int dayOfYear;
    int dayOfMonth;
    int month;
    int &rDayOfMonth = dayOfMonth;
    int &rMonth = month;
    printf("The year (%d) is leap - %d test: \n", testYear, isLeap);
    for (int i = 0, monthNum = 1; i < 12; i++, monthNum++) {
        //Вызов функции DayOfYear
        dayOfYear = DayOfYear(testYear, monthNum, nDayTab[isLeap][i]);
        printf("DayOfYear(%d, %2d, %2d) = %d\n", testYear, monthNum, nDayTab[isLeap][i], dayOfYear);

        //Проверка результата обратной функцией DayOfMonth
        DayOfMonth(testYear, dayOfYear, rDayOfMonth, rMonth);
        printf("DayOfMonth(%d, %d, rDayOfMonth, rMonth): dayOfMonth = %d, month - %d\t",
               testYear, dayOfYear, rDayOfMonth, rMonth);
        printf("Initial days in the %d month = %d\n", monthNum, nDayTab[isLeap][i]);
    }
}

int DayOfYear(unsigned int year, int month, int day) {

    switch (month) {
        case 12:
            day += 30;
        case 11:
            day += 31;
        case 10:
            day += 30;
        case 9:
            day += 31;
        case 8:
            day += 31;
        case 7:
            day += 30;
        case 6:
            day += 31;
        case 5:
            day += 30;
        case 4:
            day += 31;
        case 3:
            day += __isleap(year) ? 29 : 28;
        case 2:
            day += 31;
    }
    return day;
}

void DayOfMonth(const int &year, const int &dayOfYear, int &dayOfMonth, int &month) {
// функция преобразует порядковый день года в день месяца
// (принимает год и порядковый день года в качестве параметров и должна сформировать
// день месяца и номер месяца и каким-то образом сообщить эти значения вызывающей процедуре)
    month = 0;
    int currentMonthsDays;
    dayOfMonth = dayOfYear;
    do {
        currentMonthsDays = daysInMonth(year, ++month);
    } while (dayOfMonth > currentMonthsDays && (dayOfMonth -= currentMonthsDays));
}

inline
int daysInMonth(const int &year, const int &month) {
    switch (month) {
        case 2:
            return __isleap(year) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}
