#pragma once

#include <iostream>
//��������� ������������ � ������ ������� �������:

void Sort(char* pcFirst, int nNumber, int size,
	 void (*Swap)(void*, void*), int (*Compare)(void*, void*) );
void SwapInt(void* p1, void* p2);
int CmpInt(void* p1, void* p2);

template <typename T>
void printArray(T arr[], int size);
