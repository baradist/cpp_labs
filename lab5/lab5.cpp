
/*************************************************************
	������������ ������� �5. 
	"������" ��������� ������� ����������� ����������
	��������� �� �������
	���������
*************************************************************/
//#define __CRT_SECURE_NO_WARNINGS
//#include <tchar.h>
#include <iostream>
//#include <cstdio>
#include "other.h"

void task1();

int main()
{
	task1();






	//������� 2. ��������� �� ������� � �������� ���������.
	//���� ��������� ������� ���������� ����� �������� - Sort.
	//������� ��������� ��������� ���������:
	//1) ��������� �� ������ ����������� �������
	//2) ���������� ����������� ���������
	//3) ������ �������� � ������
	//4) ��������� �� ������� ������������ ���������
	//5) ��������� �� ������� ��������� ���������

	//2a. �������� ������� ������������ ���� ����� �������� -
	// SwapInt, ������� ��������� ��� void ��������� �
	//������ �������� �������

	//�������� ������� ��������� ���� ����� �������� -
	// CmpInt, ������� ��������� ��� void ��������� �
	//���������� int ��������� ���������:
	//<0 - ������ ������� ������, ��� ������
	//=0 - �����
	//>0 - ������ ������� ������, ��� ������
/*
	int nAr[]=...	//������ ��� ����������

	//������ ��������� �������



	//����� ����������
	int nTotal=...			//���������� ��������� � �������
	Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(int), SwapInt, CmpInt);

	//������ ����������� ����������

	stop
*/
/*
	//������� 2�. �� �������� � 8� �������� ���������������
	//������� - SwapDouble � CmpDouble � �������� ������� Sort
	//��� ���������� ������� ������������ ��������.
*/
/*
	//������� 2�*. �� �������� � 8� �������� ���������������
	//������� - SwapStr � CmpStr � �������� ������� Sort
	//��� ���������� ������� ���������� �� ������.
	char s[] = "QWERTY";
	char* arStr[] = {"WWW", "SDF", "ABC", s, ...};

*/

/*
	//������� 3. ������� ���������� �� �������.
	//�������� ��������� ������� ����
	//const char* GetString1();
	//const char* GetString2();
	//		...., ������ �� ������� ���������� ��������� �� ���� ������
	//(��������� - ����� ����� �� ������ ����� ���������� �� �������)


	//�������� � ������������������ ������ ���������� �� �������
	//GetString1,GetString2...



	//������� ����� �������, ������� �� ������ �������:
	int n;



    //�������� �������



	//������������ ���������


*/
//////////////////////////////////////////////////////////////////////////////////////

	//����. ��������� �.
	//������� 1. �������� ��������� BOOK, ����������� �����
	//(�����, ��������, ��� �������, ����, ����������).
	//���������: ������ ���� ����� ���� ���� ���������.
	//���������: ���������� ��������� ������������� ��������
	//� ������������ ����.




	//������� 2. �������� ������� ��������� (����������, ���������, �����������,
	//������������) ���������� (�������) ���� BOOK (��� �������������).
	//���������� - ������� ������ ������� ���������� ��� ������
	//����� ������. ��� ���������������� (��� �� ����������������) ����
	//���������. ���������: �� ���� ������� ����� ���������� ������?



	//������� 3. ��������� ���� ��������� ��������.
	//���������: ���� ��� �������� ������ ������������ ������, ����������
	//������������� "������" �� ������ �� ������� �������.



	//������� 4. �������� �������, ��������� �� ����� ��������� �����.
	//���������: ��� ����������� ���������� ��������� BOOK � �������.
	//��� ������ �� ������� ����������� ������� ����������� ����������
	//printf



	//������� 5. �������� ������� ��� ������������ ����� ���������.
	//��� ����� ����������� ������� ����������� ���������� scanf
	//���������: ������� �������� � ����� ������� ����������� ��������
	//������������ ���������� ��������, ��������, ��� ������� �� ����� ����
	//�����, ���... (��� ��������� ������������), ��������� �����������
	//������ �������� �� ������������, ���� �� ����� ���� �������������...


	return 0;
}

void task1() {
    //���� "������" ��������� ������� ����������� ����������
    //������� 1. � ������� ������� scanf ����������� ��� ������������: A,B,C
    int A = 0;
    int B = 0;
    int C = 0;
    printf("Enter A, B and C: ");
//	scanf_s("%d %d %d", &A, &B, &C);
    scanf("%d %d %d", &A, &B, &C);
    //������� 2. �������� (�������!) ������� �������� y=A*x*x + B*x + C
    //��� ��������� x � ��������� -2 �� +2 � ����� 0.5
    printf("y = A*x*x + B*x + C\n");
    for (double x = -2; x <= 2; x += 0.5)
    {
        printf("x = %e => y = %e\n", x, A*x*x + B*x + C);
    }

    ///////////////////////////////////////////////////////////////////
    //���� ��������� �� �������

    //������� 1. ��������� �� �������. "�����������".
    //�������� �������:
    //1)Sum - ��������� ��� �������� double � ���������� �����
    //���� ��������
    //2)Sub- ��������� ��� �������� double � ���������� ��������
    //���� ��������
    //3)Mul - *
    //4)Div - /
    //5)� ��� ���������� � ������� ������ ������������ ������� ����������� ����������
    //		- pow(). ��������� 1: �������� ������� ��������� � <cmath>.
    //		��������� 2: ����������� ���������� ������������� ��������� �������������
    //		��������� ���� �������, � ��� ����������� ������������ ��������� ��
    //		double pow(double, double);

    //������������ ������������	��������� �����������:
    //���� ������������ ����� ������������ �������� ������ ������������,
    //�� ����� ������� ��� �������� � ���� ��������
    //� �� �������� ���������. ��������� ��������� ����������� ������
    //��������������� ����� ������� �� ���������.
    //������������� ����������� ����� ������������������ ����� ��������


}
