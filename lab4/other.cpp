#include "other.h"
#include <iostream>
///////////////////////////////////////////////////
int valueadfadf = 42;
int& reff = valueadfadf;
//���������-��������� ��� ������� 5�
//��� ������������� ��������

void VarArgs(int arg1, ...) {
    int number = 0;    //������� ���������
    //�������� ��������� �� int � ��������������� ��� �������
    //������� ���������
    int *p = &arg1;
    //���� �� ��������� ����� ������:
    while (*p != '\0') {
        // �) ������ �������� ���������� ���������
        std::cout << *p << "\t";
        // �) ����������� ��������� (�� ������ ��������� ��
        //��������� �������� ������)
        p++;
        // �) ��������� ������� ���������
        number++;
    }
    //������ ����� ���������
	std::cout << "Args amount = " << number << std::endl;
}
