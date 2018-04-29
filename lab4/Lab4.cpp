
/*************************************************************
	������������ ������� �3. �������.
	����������, �����������, �����.
	�������� ����������. ����������� ��������.
	��������� �� �������
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

	//������� 5. �������� ���������� ������ (����������� ����������� � ��������
	//���������� ���������), ��������� ��� ����������.
	//�������� �������, ������� ��������� � ������ ����� �������� ������ ���
	//�������, ��� ������ �������� � ������� ��� ���. ���������: ��� ���� ������
	//������� ������ �����������! ������� �� ������ ������ ����������.

    //��� �������� �������� �������, ������� ������� �������� ���� ��������� �� �����


/*
	//������� 6. ����������� �������. �������� ����������� ������� ����������
	//����� ������ N ����������� �����.



*/
/*
	//������� 7�. ������� � ���������� ������ ����������.
	//�������� ������� (���� ��������� VarArgs, �� ������������
	// �������), ������� ��������� ���������� ����� ����������
	// ���� int � ������� �� ������ ����� �������� ���������� �
	// �� ��������.
	// ��������� ����� ������ �������� ������� ��������.
	
	int nN1=5, nN2=11, nN3=4, nN4=7, nN5=-1;
	VarArgs(nN1,0);	
	VarArgs(nN1,nN2,0);	
	VarArgs(nN1,nN2,nN3,nN4,nN5,0);	
	stop


	//������� 7�. ������������� ������� 5� � ������� ��������
	// va_start, va_arg, va_end
*/




    //������� 8. ����������� ������.
    //�������� �������, ������� ������� ����������� �������� � �������,
    // ����� �������, ����� �� ����� ����� ���� ������������ ����� �� �����
    // ���������: *MyMin(���������) = 0;



    return 0;
}

void task1() {
    cout << "task1" << endl;

    /////////////////////////////////////////////////////////////////////////////
    // ������� 1. ������.
    //�������� ������ �� ��� double. ����������� ������ �������� ��������
    double val = 42;
    double &rVal = val;
    cout << val << endl;
    rVal += 1;
    cout << val << endl;

    //���������������� ��� ��������� �������. ��� ������� �������, �����
    //linker �� ������� ������ ��� �������� exe-����� ���������: ������ ref
    //������ ���� �������
    extern int ref;
    ref++;

    //���������������� ��������� ������. ��� ������� �������, �����
    //���������� �� ������� ������
    const int &ref1 = 1;

    //����� ���������:
    char c = 'A';
    char *pc = &c;
    //�������� ������ �� ���������.
    char *&rpc = pc;
    cout << rpc << endl;
    // ����������� ������ ��������
    //�) �������� �� ������
    *rpc = 'B';
    cout << rpc << endl;
    //�) ��� �����
    rpc++;
    cout << rpc << endl;
}

void task2() {

    //������� 2. ������� ��� �������� ���������� �) �� ��������,
    // �) �� ������, �) �� ���������
    //�������� � ���������� ��� ������� , ������� ����������� ��������
    //� ������� ��������� �������� �� 1 ( �) - IncByValue(),
    // �) - IncByPointer(), �) - IncByReference() ).
    //��������� ������������ � ������� ���������.
    //
    //���������: ���������� ������� ������� �������� � ������������ ����
    int val = 1;//�������� ���� ���������� ������ ���� ��������� � �������
    //������ �� ������� �� �������
    printf("Initial val = %d\n", val);
    IncByValue(val); // it should be like: val = IncByValue(val); otherwise, it doesn't work
    printf("After IncByValue, val = %d\n", val);
    IncByPointer(&val);
    printf("After IncByPointer, val = %d\n", val);
    IncByReference(val);
    printf("After IncByReference, val = %d\n", val);


    //������� 2�. �������� ���������� c ������� ��������� � �� ������.
    //������������� ����� �������.
    //�������� ������� (�������) Swap(), ������� ������ ��������
    //���������� nX � nY �������.
    // �)������� ������ ��������� ��� ��������� �� int, �������� �
    //�������� ������ �������� ���������� � ���������� ���������
    // �)������� ������ ��������� ��� ������ �� int
    //��������� ������������ � ������� ������������ ���� ���������.

    int nX = 1;
    int nY = -1;
    printf("nX = %d, nY = %d\n", nX, nY);
    Swap(&nX, &nY);    //�������� ������� �������� nX � nY �
    //������� ���������� �� nX � nY
    printf("nX = %d, nY = %d\n", nX, nY);
    Swap(nX, nY);    //� ������ ������� � ������� ������ �� nX � nY
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

    //������� 3. ��������� �� ������� � �������� ����������.
    //3a.�������� ��� �������� ������� ������ ������������ ��������
    //1. �� ���������� ���������� �������

    //1.��������:
    int ar[N][M] = {{1, 2, 3, 5},
                    {5, 6, 7, 8}};
    //��������� - ��� � ��� ������ ���� ������ N � M
    int res = Min(ar);
    printf("The minimum is %d\n", res);

    //2. � ������������ ���������� ������� (��� ����������� �����������)
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

    //3b. �������� ������� ��������� ���� ����� - MyStrCmp():
    //������� ������ ��������� ��� ��������� �� ������������
    //������ (�������� �� ������ ������� �����������, ��� �������
    //�� ����� ����� �������������� ���������� �����)
    //������� ������ ���������� ������������� ��������, ����
    //������ ������ ��������������� ������ ������, 0 - ����
    //��� ����� � ������������� ��������, ���� ������ ������
    //������ ������.
    //���������, ��� ��������� ����� ������ �������� ������� ����.
    //�������� ��� ������ ��� ���������:
    char *string1 = new char[21];
    char *string2 = new char[21];
    printf("Enter the first string (max 20 chars):");
    cin >> string1;
    printf("Enter the second string (max 20 chars):");
    cin >> string2;

    //�������� ������� ���������
    res = MyStrCmp(string1, string2);
    //�������� ��������� ��������� � ������� cout:
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

    //������� 4.������ � �������� ����������. �������� ��������� �� ����������
    //������ � �������� ��������� �������.
    //�������� ��� ����������������� ���� ����� �������:
    //1.  ... DayOfYear(...)
    //- ����������� ���� ������ (�����,����� � ��� �������� � �������� ����������)
    //� ���������� ���� ����(������������ ��������)
    //2. ... DayOfMonth(...) - ������� ����������� ���������� ���� ���� � ���� ������
    // (��������� ��� � ���������� ���� ���� � �������� ���������� � ������ ������������
    // ���� ������ � ����� ������ � �����-�� ������� �������� ��� �������� ���������� ���������)

    //��������� ����������������� ����� ������� � ������� ���������� ���������:


    //� �������� ���������� ��� �������� ��������� "���������� - ������������" ���.
    //��� ����� ������������ � ������ ������� � �������� ������ �� ���������� ����������
    //������ ������������ ���� ����������� ������� nDayTab

    int nDayTab[2][12] = {
            {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, //������������ ���
            {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};    //���������� ���

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
        //����� ������� DayOfYear
        dayOfYear = DayOfYear(testYear, monthNum, nDayTab[isLeap][i]);
        printf("DayOfYear(%d, %2d, %2d) = %d\n", testYear, monthNum, nDayTab[isLeap][i], dayOfYear);

        //�������� ���������� �������� �������� DayOfMonth
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
// ������� ����������� ���������� ���� ���� � ���� ������
// (��������� ��� � ���������� ���� ���� � �������� ���������� � ������ ������������
// ���� ������ � ����� ������ � �����-�� ������� �������� ��� �������� ���������� ���������)
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
