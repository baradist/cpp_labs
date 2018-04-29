//#include "other.h"

///////////////////////////////////////////////////

void Sort(char* pcFirst, int nNumber, int size,
	 void (*Swap)(void*, void*), int (*Compare)(void*, void*) )
{
	int i;
	for(i=1; i<nNumber; i++)
		for(int j=nNumber-1; j>=i; j--)
		{
			char* pCurrent = pcFirst+j*size;
			char* pPrevious = pcFirst+(j-1)*size;
			if((*Compare)( pPrevious, pCurrent ) > 0)//���������
												//�����������
				(*Swap)( pPrevious, pCurrent );
		}
}

void SwapInt(void* p1, void* p2)
{
    int t = *static_cast<int *>(p1);
    *static_cast<int *>(p1) = *static_cast<int *>(p2);
    *static_cast<int *>(p2) = t;
}

int CmpInt(void* p1, void* p2)
{
    return *static_cast<int *>(p1) - *static_cast<int *>(p2);
}
