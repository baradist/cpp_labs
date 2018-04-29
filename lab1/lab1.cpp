/*
	� ���������� ���������� ������ ������ ��������� �������� ����� ������ �� �����������
	��� ���������� ������ �������, ������� ������� ��������� ��� ������������������ 
	������������������ ������, ������� ��������� ��������������� �����������������, 
	�������  ��� ���� �� ������������ �������.

	��������� ������������������ �������� ��� ������� �������:
	1. �������� (���������, ���������������� ������ ��������) �������� ����� ���������;
	2. �������������� (Build/Compile  ***.cpp ��� Ctrl+F7)
		���������: ���� ���� ���� �������� �������������, �� ������� ��� ����������� 
			������������, �.�. ��������� ������� ������ (errors) � ��������������
			(warnings), ����������� ��� ���������� ������� ����������� �����;
	3. ����������� ������(Build/Build ***.exe ��� F7)
		��������� 1: ���� ���� ���� ������������, �� ������������ �����������, �.�. 
			��������� ����������������� ������ ���������� ����� � � ������ ����������
			������ ������ ������� ���������� �� ���������� ������������ ���������;
		��������� 2: ����� ���, ��� ������� ������, ������� ���������  � ���, ��� 
			����������� ��� ����� ��������� ���������� ��� ��������� - 
				(Build/Configuration Manager.../Configuration - Debug - ��� ������ �������);
	4. ��������� �� ������������ ��� ������� ��������� ���� ��������(breakpoints) - F9 ��� 
		������ �������� ����� ������� �� ����� ����� ������ ���� ��������������; 
	5. ��������� ��������� � ������ ������� 
		(Debug/Start... ���  F5);

  ���������: ��� ������������� ���� �������� ��������� ���������� ������ � ��������������� 
		������ ����, ������ �� ������ ������� ������� ������� �� �� ����� ����� ������� � 
		������� ������ �� Tool Bar, � ��� ��������� ����� ��������� ��������������.

*/

#include  <iostream>		//��� ������������� ������� �����/������

int nTwin=1;			//���������� ����������
namespace TwinSpace{ int nTwin=2;}	//���������� ��������� �
						//������������ ���� - TwinSpace

#define	  stop __asm nop	//� ������� ���������������� ������ "������" �������.
							//��� ���������������� ����� ������ ��� ����, �����
							//����� ���� ��������� �� ���� ������ ����� ��������.

int main()
{

 //**********************************************************
	//������� 1. ������ � ����������. ������� ���� ������. �������� ��������� �� �����, 
	//������� �� ���������� ���������� � ��������������� ��������� (�������, ��� 
	//���������� ������, ��������� ��� int, �������-��������).
	//�������� �������� �� ������ ������������� ���������� signed � unsigned ����� ����� 
	//������, � ����� �� ���������� ������������� ������������� ����� �����.

	
	char cByte = 'A';
	cByte    = 0x42; 
	cByte    = 66;  
	cByte    = -1;   

	unsigned char ucByte = 0x41; 
	ucByte   = 'B';
	ucByte   =	-1; 

	int iInt =  0xffffffff; 

	unsigned int uiInt = 0xffffffff; 

	float fFloat = 1.f;  
	double dDouble = 1.; 

	// ��������� ��������, ����������� �����. � ������������ ��������,
	// ��� ������� ��������� � ����������. ��������� ������� ����� ���� 
	// ��������� � ���������������.

	double d = 0.1234567890123456789123456789; 
	float  f = 0.1234567890123456789123456789; 

	d	=	1.; //
	d	=	0.999999999999999999999999999999999; 

	stop
	
	// � ������������ �������� ���������, ������������ ���������� sizeof ���
	// ���������� ���� wchar_t (�� ������)
	wchar_t cw = L'�';
	size_t n = sizeof(cw); //

	stop


// **************************************************************
	//������� 2a. ������� ���������� ����� ������.
	//��������� ������� ���������� ��� ���������� (1) � (2):
	//�������� ���� (�������� � ����) ��������������, ������� ������ ��������� ����������

	iInt=1;
	double dDouble1=iInt/3;		// (1)
	double dDouble2=iInt/3.;	// (2)


	// ��������������� ����������.
	// ��������� ����� C ��������� "����������" ������������
	// (��� � ������� (1) � (2)). ��������� ���������� ���������� ����� (1) � (2)
	// (�������� ���������� dDouble, fFloat, nInt, sShort, cByte), ���������� ������� 
	// ��������� ������������ ��� ���������� ������ � ��������� ���������.
	// ��������� ������, ���� ������������ ������� ����������, ��� ��� ������ �� ����������.
	// ��������� (� ������������) �������������� (warnings) �����������.

	short sShort;
	dDouble=fFloat=iInt=sShort=cByte=3.3/3;			// (1)
	
	cByte=sShort=iInt=fFloat=dDouble=3.3/3;			// (2)

	//���� ��� ��� ������ "����������" ������������� �������� ���������� �����, ��� ����� 
	// �������� � ������������� ����������� - ��������� (� ������������), � �����?
	// �������� ���� ��������������, ������� ������ ��������� ����������

	iInt	=	257;
	cByte	=	iInt; //

	unsigned char cN1=255, cN2=2, cSum;
	cSum = cN1 + cN2; //

	//�������� ���������� ������� � ����������� ����. ��������� (� ������������),
	//������ � ��������� ������ �� ���������� ����� �� ��������� �����
	// �������� ���� ��������������, ������� ������ ��������� ����������
	int iSum = cN1+cN2; //

	//��������, ������ ��� �������� ���������� �������� (���������� � �������� �������) 
	// � ������� (1) � (2) ���������� ������ ����������
	// �������� ���� ��������������, ������� ������ ��������� ���������� � ���������,
	// ��� ��� ���� ����������
	char c1=0xff, c2=2;
	unsigned char uc1=0xff, uc2=2;
	int iSum1= c1 + c2;   //(1)
	int iSum2= uc1 + uc2; //(2)

	stop

	
// ***********************************************************
	//������� 2b. ����� ���������� ����� ������.
	//������������������ ��������� (�������� ���������� dDouble) � ������ (3)
	// �������� ���� ��������������, ������� ������ ��������� ����������
	int nTmp=100, nn=3;
	dDouble=3.3 + nTmp / nn; // (3)

	//�������� ��������� ��� ������ �������� � ������� ��������� ������
	//���������� ����

	//double dDouble3=...
		


	stop


// *******************************************************
	// ������� 3. ������� ��������, ������� ��������� �
	//				����� ������������� ����������

	//   � ���� ��������� ���������� ������ ���������� � ����� � ��� �� ������ 
	// nTwin - ���� ����������, ������ ���������� � ����� ������������ ����, 
	// (���������� ���� � ������ ������) ������ - ��������� ������ ������� main(), 
	// ��������� - ��������� ��������� ������ �����. 
	//   � ������ ������� ��������� � ���������� ������ ��������� ����������, � ����� 
	// �� ������� ���������� ���� ���������, � ����� ���� ������������� � ��������� 
	// ��� ���� �������, �������� ����������� � ������� ������� 
	//	��� ���������� ������� ������������� ������������ ������ "Locals" � "Watches"
	// ���������: - � ���� "Watches" ����� ��������� ��� nTwin
	//			��� � ::nTwin, ������� ��� � TwinSpace::nTwin
	

	nTwin=100;
	TwinSpace::nTwin = 300;
	nTwin++;
	// �������� �������� �� ��������� "����" ���������. ���� ��������� ���������� nTwin
	// �� ��������� ������ ��� �� ���������� (� ��������� ���� �� ����������), �� �����
	// ��� ��� � ����� ������� main ��� �������� (� ��� �����). ���� ������ �  ���� 
	// "Watches" ��������� ������ nTwin, �� �������� ����� ���������� �������� ����, ��� 
	// �� ����������� ��������� ���������� (���-�� ����� -858993460 ��� 0xcccccccc), 
	// ���� ������ ��������� ���������� �������� ���������� ����������, ����������� �����.
	// ���������� ��� ���� ��� ��������� �����.
	// ���� ���� ������� ������ �������� ���������� ����������, �� ���� ���� ������� � ����
	// "Watches" ���������� ������� ���������, �.�. �������� ��� ::nTwin.
	// ����������: ��� ��� ���� �������� �� ��, ����� �� ��������� ��������� ����.
	int nTwin;
	nTwin=200;	
	::nTwin++;  
	{
		int nTwin;
		nTwin=-1;
		::nTwin++;
		TwinSpace::nTwin++;
	}

	nTwin--;


// *******************************************************
	// ������� 4. ������������ ������ ������ - static
	// �) ��� ������ �������� ����� �������� �������� ��������� nLocal# � nStatic#.
	// �) ��������, ����� ����������� ������������� ����� ����������?
	// �) �������� (� �����������) ������� ����� �������� ������������� 
	//     ���������� nStatic1 � nStatic2 � �������� �������� ������, 
	//     �������� �� ���������� nLocal2.

	for (int i=0; i<3; i++)
	{
		static int nStatic1 = 100;
		int nLocal1 = 100;
		int nLocal2 = 200;
		static int nStatic2 = nLocal2++ * 2;
		nStatic1++;
		nStatic2++;
		nLocal1++;
		stop

	}
	// ��������:
	//   �) ��� ���������� ��������� ��������� nStatic1?
	//   �) ��� ��� ���������� ���������������� ?
	for (int i=0; i<3; i++)
	{
		static int nStatic1;
		nStatic1 = 100;
		int nLocal1 = 100;
		nStatic1++;
		nLocal1++;
		stop

	}



// *******************************************************
	// ������� 5. ������������ - enum
	// �������� �������� �� ����� � ������� ������������� ��������
	// �������� ������� �� �����, ������� �� ����������, �������
	// ��������� ���������� myColors


	enum eColors
	{
		BLACK,
		BLUE,
		GREEN,
		RED=5,
		YELLOW,
		WHITE=RED+4
	};
	
	eColors   myColors;	//���������� ���������� ���� eColors 
	myColors=BLACK;
	myColors=BLUE;
	myColors=GREEN;
	myColors=RED;
	myColors=YELLOW;
	myColors=WHITE;

	int nnn = BLACK; //����� ������������� ���������� ����� ���������
					 //�������� �� ������ ���������������� ��������

	//����������� ��������� ����� ������������ � ����������:
	nnn = BLUE | YELLOW;

	//���������������� ��������� ������ � ��������
	//�������� ��  ������ ��� ���������� 
//	myColors = 1;	//������������� ��������� ����� �������, ����� ���������� �� ������� ������

	// ��������� ��������� ������������ �� ����� ������������ � ��� ���������� myColors?
//	myColors = 123;
	stop


// *******************************************************
	// ������� 6.1 ���������� ��� bool
	// �������� ������� �� �����, ������� �� ����������
	// ���������� b � ��������������� ���������. �������� ��� �������� � ������������

	int nNumber = 1;
	bool b = (nNumber != 0); //
	b = (nNumber == 0); //
	b = (nNumber > 0); //
	b = (nNumber > 1); //
	b = 5; //

	//�� ������ ������ ������������� ���������� �������� � ������
	//���� ��� ���������� ����� ��� ������� �������������� (������)
	//�������� ��������: ��� �������������� �������� ���������� ���������� ����������?
	int tmp =  b + 1; //

	//������� 6.2 � ������������� ��������� (������� �� ��� ����������) ���������� ���
	// ������������ �� ���������� ���������: ���������� �������� ������ ��������� ���,
	// �� ������ ����� ���������� �� ��������, ��� ���� ������ 400-� ��� ��� ���� 
	// ����������. �.�. 1823 - �� ����������, 1824 - ����������, 1900 - �� ����������,
	// 2000 - ����������.
	// �������� �������� ����, ����� ���:
	// ���������� ���������� isLeapYear ��������� �������� true, ���� ���, ��������
	// ���������� year - ����������.
	// ����������: �� ���� ������������ ����������� if-else, ��������� ���������� � switch
	//             ���� �������� ���������� ��������� � ���� ������.
	{
		//������� ������� ���� ��� ��������:  1823, 1900 - �� ����������, 1824, 2000 - ����������

		//��������� �������� 
		//bool isLeapYear = 
		// ��������� �������� � ���������
		stop
	}

// *******************************************************
	// ������� 7. ����������� const � ����������

	{
		//���������������� ��������� ��� ������� � ��������� (� ������������)
		//������ ��� ���������� 

		//	const int nN; //
		//	nN = 1; //
	}



// ********************************************************
	//������� 8. ���������� �������� ��������� � ��������� ���������.

	//������� 8.1 �������� �������� ����, ������� ��������� ��� �������, 
	//���������� � ���������� ch � ��������������� �������.
	//��������� ������������� �������� ��������, ����� ������������ ���� �����
	//��� ����� ������ �������, ������� ������ �� �������������
	//���������: �������� ������ � ��������� ����������� ��������, ��� �������� � �������
	// ����� ASCII ��� ������ ����� ������� �������� �� 0x20 ������ ���� 
	// ��������������� ����� �������� ��������.
	{
		// ����������� �������� ���������� ch � ������� ������ �����
		char ch ;
		
		//... �������� �������
		// ����� ��������� � ��������� �������� ��� ������ "���" �� �����
		stop
	}


	//������� 8.2 �������� �������� ����, ������� ��������� � ������� if (if/else)
	//��������� ������: ���� x ������ ��� ����� 0, y=0
	//���� x ������ 0 �� ������ 1, �� y=x,
	//���� x ������ ��� ����� 1, �� y=1
	//���������: ������ ���� ������ ��� ����� ���� x � y?
	{
	}

	//������� 8.3 �������� �������� ����, ������� ��������� � ������� switch
	//��������� ������: � ���������� cInput ���� char ���� �������� �������,
	//���������� ����� ��������.
	//���� ������ ������ 'y' (�.�. yes) � ����� ��������, �� ���������
	//���������� � �������� ���������� x
	//���� ������ ������ 'n' (�.�. no) � ����� ��������, �� ���������
	//���������� � �������� (x * 2)
	//���� ����� ������ �����, �� ������� ��������� �� ������
	{
		char ch;
		//������������ ��������
		//switch
	}
	// ********************************************************
	//������� 9. �����.

	//������� 9.1 �������� �������� ����, ������� ��������� � ������� for
	//��������� ������: ����� ����� ��������� ��������� ����� �����.
	//������� ������� � ������� ������ ����� ��� � ������� ������� �������.
	//������������� ������ �� ����� ������ ������� ������, ��� �������.
	{
		
		//������������ ������� ���������

		//��������� ������������ ��������
		
		// ��������� �����
		// ��������� � ��������� ��������
		stop
	}


	//������� 9.2 �������� �������� ����, ������� ��������� � ������� do-while
	//��������� ������: �� ������ �������� ����� ������ � ������� ����� ��������
	// � �������� ����, ���� �������� ������������� �������: 
	// �������� ������ ��� ����� 10 � ������.
	//���������: �������� �� �������� � �������������� �������� ������� �� �������
	//������ ���������� ����� ������������� ���. ���������� ����������� ��������������
	//�������.
	
	{

	}

	//������� 9.3 �������� �������� ����, ������� ��������� � ������� while
	//��������� ������: ������� int x = 0; 
	//�� ������ �������� x=x+1, sum=sum+1/x
	//����� �������� x, ��� ������� sum>1.7
	{

	}
	return 0;//��� ���������� ����������
}	// ����� ������� main()

