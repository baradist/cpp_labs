/*************************************************************
	������������ ������� �3. ���������� �������.
							������������ ��������� ������.
							���������� ��������� ���������� � ������.
							������� ���������.
							������.
*************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <ctime>

//#define	  stop __asm nop
using namespace std;

static const int DIM_SIZE = 3;
static const size_t ROWS = 10;
static const size_t COLUMNS = 10;

template<typename T>
void printArray_(T arr[][DIM_SIZE][DIM_SIZE], size_t size = DIM_SIZE);

void printArray(const char arr[][ROWS], size_t columns);

template<typename T>
void printArray(T ***arr, size_t X = DIM_SIZE, size_t Y = DIM_SIZE, size_t Z = DIM_SIZE);

void printArray(int **arr, size_t X, size_t Y);

template<typename T>
void printArray(const T *arr, size_t X);

template<typename T>
void selectionSort(T arr[], size_t size);

bool contains(const int arr[], size_t size, int value);

void task1();

void task2();

void task3();

void task4();

void task5();
void task5_with_string();

void task6();
void task6_();

void task7();

double avg(int *pDouble, size_t size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(pDouble++);
    }
    return static_cast<double>(sum) / size;
}

int main() {
    //task1();
    //task2();
    //task3();
    //task4();
    //task5();
    task6();
    //task7();

    return 0;
}

void task1() {
    ///////////////////////////////////////////////////////////////
    //			���������� �������                               //
    ///////////////////////////////////////////////////////////////

    // ������� 1. �������� ���������� ������ � ����������� ���������
    //�������� ��������� ��������� �������:
    printf("Task 1: \n");
    //a) ������������������ ������ ��� ����������
    printf("a) initialize an array during declaration:  \n");
    int arr[][DIM_SIZE][DIM_SIZE] = {{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
                                     {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}},
                                     {{3, 3, 3}, {3, 3, 3}, {3, 3, 3}}};
    printArray_(arr);
    //�) �������� �������������������� ������ � ��������� �������� ���������
    //	� ������� ����
    //					 |--------|
    //				   / |3  3  3 |
    //    			 |---------|3 |
    //			   / | 2  2  2 |3 |
    //			  |---------|2 |__|
    //			  | 1  1  1 |2 | /
    //			  | 1  1  1 |__|
    //			  | 1  1  1 | /
    //			  |_________|
    //���������� ��������� ��������� ������������ ������ �������.
    printf("b) declare not initialized array... : \n");
    int arr1[DIM_SIZE][DIM_SIZE][DIM_SIZE];
    int size1 = sizeof(arr1) / sizeof(***arr);
    int *pArr1 = **arr1;
    for (int i = 0; i < size1; i++) {
        *(pArr1++) = (i / (DIM_SIZE * DIM_SIZE)) + 1;
    }
    //�) ������� ����� ��������� �������
    pArr1 = **arr1;
    int sum = 0;
    for (int i = 0; i < size1; i++) {
        sum += *(pArr1++);
    }
    printArray_(arr1);
    printf("c) calculate sum: %d\n", sum);

    //�) ������������������ ������ ��� ����������:
    //					 |--------|
    //				   / |3  0  0 |
    //    			 |---------|0 |
    //			   / | 2  0  0 |0 |
    //			  |---------|0 |__|
    //			  | 1  0  0 |0 | /
    //			  | 0  0  0 |__|
    //			  | 0  0  0 | /
    //			  |_________|

    int arr2[DIM_SIZE][DIM_SIZE][DIM_SIZE] = {{{1}},
                                              {{2}},
                                              {{3}}};
    printArray_(arr2);
    //�) ������������� �������� ���������� ����������:
    //�������� � ������������������ ���������� ���������� ��� �������:
    //���������� ������ � ������ ����������. �������� ������� � �������������
    //��������� ����� ��������.
    char arrChar[][4] = {"ABC", "DEF"};
    arrChar[0][1] = 'b';
    const char *arrChar1[] = {"GHI", "JKL"};
    //arrChar1[0][1] = 'h'; // expression must be a modifiable lvalue
}

void task2() {
    ///////////////////////////////////////////////////////////////
    //			������������ ��������� ������                    //
    ///////////////////////////////////////////////////////////////

    // �������2. �������� ������������ ���������� ������ � �������������,
    //������������ � �������� ���������� ��������� - N*M.
    printf("Task 2. Create a dinamic 2d array\n");

#include <cstdlib>

    {
        size_t sizeX = 4;
        size_t sizeY = 2; // TODO: it should be entered by user
        int **ppInt = new int *[sizeY];
        for (int i = 0; i < sizeY; i++) {
            ppInt[i] = new int[sizeX];
        }
        //������� �������� ��������� ������� ���������� ��������� �����.
        //srand(time(0));
        int ppIntSize = sizeX * sizeY;
        for (int y = 0; y < sizeY; y++) {
            for (int x = 0; x < sizeX; x++) {
                ppInt[y][x] = rand() % 10;
            }
        }
        printArray(ppInt, sizeX, sizeY);
        //�������  ����� ���������.
        {
            int sum = 0;
            for (int y = 0; y < sizeY; y++) {
                for (int x = 0; x < sizeX; x++) {
                    sum += ppInt[y][x];
                }
            }
            printf("Task 2: sum = %d\n", sum);
        }
        //��������� 1: ��� ��������� ��������� ����� ����������� �������
        //����������� ���������� - rand() (<cstdlib>)
        //��������� 2: �� ����� ���� �� ��������, ������� ��������� ����������� ���������
        //����� �������� �����������������, �� ���� ��� ���� ���������������� ��������
        //���������� �� ��������� ��� ���������� ������������������ ��������.
        //��� ���� ����� ������������ "���������" �������� ���� ������� ��� ������
        //������� ���������� ����������� ������� ����������� ���������� srand() (<cstdlib>)
        //� time() (<ctime>).
        //������� srand() ������������ ��������� ������ ��������� � ���������� � �������� ��������� ��������.
        //������� time() ������ ��� ����� �������, �������� ������� �����

        //srand( time( 0 ) );

        //�������2�. � �������������� ������� ������������ ������ ������ ��
        //�������� ��������. ����������� ���������� "�������"
        for (int i = 0; i < sizeY; i++) {
            selectionSort(ppInt[i], sizeX);
        }
        printf("2a: \n");
        printArray(ppInt, sizeX, sizeY);

        //�������2�. �������� ���������� ������ ������������ N.
        //����������� �������� i-��� �������� ����������� �������
        //������ �������� �������� ��������� i-�� ������
        //����������� �������
        double *pSum = new double[sizeY];
        for (int i = 0; i < sizeY; i++) {
            pSum[i] = avg(ppInt[i], sizeX);
        }
        printArray(pSum, sizeY);
        //��������� - �� �������� ���������� ������!
        for (int i = 0; i < sizeY; i++) {
            delete[] ppInt[i];
        }
        delete[] ppInt;
        ppInt = nullptr;
        delete[] pSum;
        pSum = nullptr;
    }
}

void task3() {
/////////////////////////////////////////////////////////////////////
    //������� 3. �) �������� �������� ����, ������� ������ NN ����� ����� � �������
    //������ ����� � ����������� ���� ���������� ���������� ������, ������ ���
    //������������ ���������� �������� �� �����������

    //{
    //    printf("Task 3\n");
    //    printf("Enter an amount of numbers: \n");
    //    size_t amount;
    //    cin >> amount;
    //    int *pInt = new int[amount];
    //    for (int i = 0; i < amount;) {
    //        i++;
    //        printf("Enter a value number %d: ", i);
    //        int value;
    //        cin >> value;
    //        printf("\n");
    //        pInt[i - 1] = value;
    //        selectionSort(pInt, i);
    //        printArray(pInt, i);
    //    }
    //}
    //�) ������� �����.
    //������������� ���������� ������� ��������� �������: ��������� ��������
    //�������� � ������ ������ ��� �������, ��� ��� ��� ������ ��� (�� ����
    //����� ������������
    {
        printf("Task 3b (only unique values)\n");
        printf("Enter an amount of numbers: \n");
        size_t amount;
        cin >> amount;
        int *pInt = new int[amount];
        for (int lastIndex = 0; lastIndex < amount;) {
            printf("Enter a value number %d: ", (lastIndex + 1));
            int value;
            cin >> value;
            if (contains(pInt, amount, value)) {
                printf("The list of values already contains %d enter a value number %d again: \n", value, (lastIndex + 1));
                continue;
            }
            int insertInto;
			for (insertInto = 0; (insertInto < lastIndex && pInt[insertInto] <= value); insertInto++) {}
			for (int j = lastIndex; j > insertInto; --j) {
				pInt[j] = pInt[j - 1];
			}
            pInt[insertInto] = value;
            //selectionSort(pInt, lastIndex);
			lastIndex++;
			printArray(pInt, lastIndex);
        }
		delete[] pInt;
		pInt = nullptr;
    }
}

void task4() {
    ///////////////////////////////////////////////////////////////////////////
    //������� 4.� ������� ������ ��������� �������� ���������,
    //�������:
    //������ ������ � ���������� � ������� cin>>...
    //� ����������� ���� ���������� ���������� ������ 5*80 ��������� ���� char;
    //��������� ����� ����� �������� ������ * (�� ���� ������ - "*") ���
    //���������� ������� (������ ��������� ����� ���);
    //���������� ����� � ���������� �������. ���������: ������
    //�� ������������� ��� ���������� ������� �������� ���������
    //���������� �� � ������. ������� ����������� ������� ������
    //���������� �� ��������������� ������ � ���������� ������
    //���������.

    //���������: ��� ����������������� ��������� ����� �����������
    //�������� ����������� ���������� strcmp(...), ������������ ���� <string>.
    cout << "Task 4" << endl;

    //���������� ����������� �������� ��� ���������
    const char *STOP_STRING = "*";    //������� "���������� ����"
    const size_t M = 80;    //������������ ������ ����� ������
    const size_t N = 10;    //������������ ���������� ����� � �������

    //�������� ���������� ������ � ������ cBuffer ���� char �
    // ������������ N*M
    char cBuffer[N][M];

    //�������� ������ (� ������ cPointers) ���������� �� ������
    //������������ N
    char *cPointers[N];

    //���� ����� �����:
    //�) �������� ����������� ��� �����
    printf("Enter %d strings, please (enter '%s' to break): \n", N, STOP_STRING);
    //�) ���� �� ������� ������ STOP_STRING ��� �� �������� ���� ������
    int count;
    for (count = 0; count < N; count++) {
        //���� ������ � ������ cBuffer:
        cin >> cBuffer[count];
        //���� ������� ������ - ������� ���������, �� ����� �� �����
        if (!strcmp(cBuffer[count], STOP_STRING)) {
            break;
        }
        //��������� �������� ������� cPointers � �������� nIndex
        //��������� �� ������ � ������� nIndex � ������� cBuffer
        cPointers[count] = cBuffer[count];
    }
    //������ ����������� � ���, ��� ����� ����� ��������.
    printf("Enough...\n");
    //������ ��������� ������:

    //���� ���������� ����� �� ������ "������������ ��������" �
    //������� �����������. �� ������ �������� - ������������� ������
    //��������������� �����
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(cPointers[j], cPointers[j + 1]) > 0) {
                swap(cPointers[j], cPointers[j + 1]);
            }
        }
    }
    printf("Sorted lines:\n");
    for (int nIndex = 0; nIndex < count; nIndex++) {
        printf("%s\n", cPointers[nIndex]);
    }
    printf("\n");
}

void task5() {
    cout << "Task 5" << endl;
    //������� 5. ���������� ������� �4, ��������� �� ����������,
    //� ������������ ������� (������?). ��� ��� ������ ����� ���� ������ �����,
    //����������� �������� ���� �� �������� ��� ������ ������ ����� ������� ������,
    //������� ��������� ��� �� ��������.
    //��� ���� ����������� ��������� (���������� �����
    // ����������� � ������� ������ �����

    const char *STOP_STRING = "*";    //������� "���������� ����"

    cout << "Enter max amount of strings: ";
    size_t maxAmount;    //������������ ���������� ����� � �������
    cin >> maxAmount;
    cout << endl;
    char **ppChar = new char *[maxAmount];
    //���� ����� �����:
    //�) �������� ����������� ��� �����
    cout << "Enter " << maxAmount << " strings, please (enter '" << STOP_STRING << "' to break): " << endl;
	
	
	//�) ���� �� ������� ������ STOP_STRING ��� �� �������� ���� ������
    int nStringNumber;
	char* pBuffer = new char[80];
    for (nStringNumber = 0; nStringNumber < maxAmount; nStringNumber++) {
		cin >> pBuffer;
		size_t length = 1;
		char* pointer = pBuffer;
		while (*(pointer++)) {
			length++;
		}
		
		//���� ������ � ������ ppChar:

        //���� ������� ������ - ������� ���������, �� ����� �� �����

        if (!strcmp(pBuffer, STOP_STRING)) {
            break;
        }
		char* str = new char[length];
		pointer = pBuffer;
		char* strPointer = str;
		while (*(strPointer++) = *(pointer++)) {}
		
        ppChar[nStringNumber] = str;
    }
	delete[] pBuffer;
    //������ ����������� � ���, ��� ����� ����� ��������.
    cout << "Enough..." << endl;

    //���� ���������� ����� ������� "������������ ��������" �
    //������� ����������� ���� ������� �������
    for (int i = 0; i < nStringNumber - 1; i++) {
        for (int j = 0; j < nStringNumber - i - 1; j++) {
            if (strcmp(ppChar[j], ppChar[j + 1]) > 0) {
                char *tmp = ppChar[j];
                ppChar[j] = ppChar[j + 1];
                ppChar[j + 1] = tmp;
            }
        }
    }
    printf("Sorted lines:\n");
    for (int nIndex = 0; nIndex < nStringNumber; nIndex++) {
        printf("%s \n", ppChar[nIndex]);
    }
    printf("\n");

    //������������ ������� ������:
    for (int i = 0; i < nStringNumber; i++) {
        delete[] ppChar[i];
    }
    delete[] ppChar;
}

void task5_with_string() {
	cout << "Task 5" << endl;
	//������� 5. ���������� ������� �4, ��������� �� ����������,
	//� ������������ ������� (������?). ��� ��� ������ ����� ���� ������ �����,
	//����������� �������� ���� �� �������� ��� ������ ������ ����� ������� ������,
	//������� ��������� ��� �� ��������.
	//��� ���� ����������� ��������� (���������� �����
	// ����������� � ������� ������ �����

	const char *STOP_STRING = "*";    //������� "���������� ����"

	cout << "Enter max amount of strings: ";
	size_t maxAmount;    //������������ ���������� ����� � �������
	cin >> maxAmount;
	cout << endl;
	char **ppChar = new char *[maxAmount];
	//���� ����� �����:
	//�) �������� ����������� ��� �����
	cout << "Enter " << maxAmount << " strings, please (enter '" << STOP_STRING << "' to break): " << endl;
	string str;
	getline(cin, str); // ???
					   //�) ���� �� ������� ������ STOP_STRING ��� �� �������� ���� ������
	int nStringNumber;
	for (nStringNumber = 0; nStringNumber < maxAmount; nStringNumber++) {
		//���� ������ � ������ ppChar:

		// I know it's weird, but I decided to use string just in order
		// not to guess the length of a future message
		// If we didn't have to use char-arrays, it would be more efficient
		// to use string-arrays
		getline(cin, str);

		//���� ������� ������ - ������� ���������, �� ����� �� �����
		if (!strcmp(str.c_str(), STOP_STRING)) {
			break;
		}
		char *pChar = new char[str.length()];
		strcpy(pChar, str.c_str());
		ppChar[nStringNumber] = pChar;
	}
	//������ ����������� � ���, ��� ����� ����� ��������.
	cout << "Enough..." << endl;

	//���� ���������� ����� ������� "������������ ��������" �
	//������� ����������� ���� ������� �������
	for (int i = 0; i < nStringNumber - 1; i++) {
		for (int j = 0; j < nStringNumber - i - 1; j++) {
			if (strcmp(ppChar[j], ppChar[j + 1]) > 0) {
				char *tmp = ppChar[j];
				ppChar[j] = ppChar[j + 1];
				ppChar[j + 1] = tmp;
			}
		}
	}
	printf("Sorted lines:\n");
	for (int nIndex = 0; nIndex < nStringNumber; nIndex++) {
		printf("%s \n", ppChar[nIndex]);
	}
	printf("\n");

	//������������ ������� ������:
	for (int i = 0; i < nStringNumber; i++) {
		delete[] ppChar[i];
	}
	delete[] ppChar;
}

void task6() {
    //������� 6. ���������� � ������������� ���������� �� �����������
    // �������. ������������������ ���������� ������
    //double dArray[4][3][3] ���, ��� �������� �� ������� � �������� ��������
    //����, ������� ������ ������� �������� ��������� ������
    //� �������� �����:
    //	����:			     |--------|
    //  				   / |4  4  4 |
    //					 |--------|	4 |
    //				   / |3  3  3 |	4 |
    //    			 |---------|3 |   |
    //			   / | 2  2  2 |3 | /
    //			  |---------|2 |__|
    //			  | 1  1  1 |2 | /
    //			  | 1  1  1 |__|
    //			  | 1  1  1 | /
    //			  |_________|

    //	�����:			     |--------|
    //  				   / |3  3  3 |
    //					 |--------|	3 |
    //				   / |4  4  4 |	3 |
    //    			 |---------|4 |   |
    //			   / | 1  1  1 |4 | /
    //			  |---------|1 |__|
    //			  | 2  2  2 |1 | /
    //			  | 2  2  2 |__|
    //			  | 2  2  2 | /
    //			  |_________|

    double dArray[][3][3] = {{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
                          {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}},
                          {{3, 3, 3}, {3, 3, 3}, {3, 3, 3}},
                          {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}}};
	size_t sizeZ = sizeof(dArray) / sizeof(*dArray);
    printArray_(dArray, sizeZ);
    for (int i = 0; i < sizeZ; i += 2) {
		//size_t sizeXY = sizeof(*dArray) / sizeof(***dArray);
		//double *pointer = *dArray[i];
		//for (int j = 0; j < sizeXY; j++) {
		//for ()
		//	//���������: �� ����� �������������� ��������� ������ �� ����� ���������!!!
			double (*t1)[3] = dArray[i];
			double (*t2)[3] = dArray[i + 1];
		//	dArray[i + 1] = t;
		//	//������������ ������� �������� i-���� � i+1-��� �����
		//}
    }
    printArray_(dArray, sizeZ);
 //   for (int z = 0; z < sizeZ; z++) {
 //       for (int y = 0; y < sizeY; y++) {
 //           delete[] dArray[z][y];
 //       }
 //       delete[] dArray[z];
 //   }
    delete[] dArray;

}

void task6_() {
	//������� 6. ���������� � ������������� ���������� �� �����������
	// �������. ������������������ ���������� ������
	//double dArray[4][3][3] ���, ��� �������� �� ������� � �������� ��������
	//����, ������� ������ ������� �������� ��������� ������
	//� �������� �����:
	//	����:			     |--------|
	//  				   / |4  4  4 |
	//					 |--------|	4 |
	//				   / |3  3  3 |	4 |
	//    			 |---------|3 |   |
	//			   / | 2  2  2 |3 | /
	//			  |---------|2 |__|
	//			  | 1  1  1 |2 | /
	//			  | 1  1  1 |__|
	//			  | 1  1  1 | /
	//			  |_________|

	//	�����:			     |--------|
	//  				   / |3  3  3 |
	//					 |--------|	3 |
	//				   / |4  4  4 |	3 |
	//    			 |---------|4 |   |
	//			   / | 1  1  1 |4 | /
	//			  |---------|1 |__|
	//			  | 2  2  2 |1 | /
	//			  | 2  2  2 |__|
	//			  | 2  2  2 | /
	//			  |_________|

	//    double dArray[][3][3] = {{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
	//                          {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}},
	//                          {{3, 3, 3}, {3, 3, 3}, {3, 3, 3}},
	//                          {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}}};
	const size_t sizeX = 3;
	const size_t sizeY = 3;
	const size_t sizeZ = 4;

	double ***dArray = new double **[sizeZ];
	for (int z = 0; z < sizeZ; z++) {
		dArray[z] = new double *[sizeY];
		for (int y = 0; y < sizeY; y++) {
			dArray[z][y] = new double[sizeX];
			for (int x = 0; x < sizeX; x++) {
				dArray[z][y][x] = z;
			}
		}
	}
	printArray(dArray, sizeX, sizeY, sizeZ);
	for (int i = 0; i < sizeof(dArray); i += 2) {
		//���������: �� ����� �������������� ��������� ������ �� ����� ���������!!!
		double **t = dArray[i];
		dArray[i] = dArray[i + 1];
		dArray[i + 1] = t;
		//������������ ������� �������� i-���� � i+1-��� �����
	}
	printArray(dArray, sizeX, sizeY, sizeZ);
	for (int z = 0; z < sizeZ; z++) {
		for (int y = 0; y < sizeY; y++) {
			delete[] dArray[z][y];
		}
		delete[] dArray[z];
	}
	delete[] dArray;
}

void task7() {
    ///////////////////////////////////////////////////////////////////////////
    //������� 7�. �������� ���������� ���������� ������ ��������� ���� char.
    //����������� �������� ��������� ������� � ������� ���������� ���������
    //����� ����� �������, ����� � ������� ���� ������ ������� '*' � '_'


    //� ������ ������ "�������� ���������" � ������ ������, ��������:
    //���� - '*' '_' '_' '*' '*' '_' '*' '_' '*' '_'
    //�����: '*' '*' '*' '*' '*' '_' '_' '_' '_' '_'
    //� ������������ ������ �� ������� - "��������� �������������"

//    char array[][ROWS] = *char [COLUMNS][ROWS];
//    char *p = *array;
//    for (int i = 0; i < ROWS * COLUMNS; i++) {
//        *p = (rand() % 2) ? '*' : '_';
//    }
//    printArray(array, COLUMNS);
//    for (int i = 0; i < ROWS; i++) {
//        selectionSort(array[i], COLUMNS);
//
//    }

    // 7�. ������������� ���������� ������� ��������� ��������:
    //����� ���������� ������� � ������� ���������� ��������� �����
    //"��������" ��������� �� �������� ���� � ������������ ����������
    //"�������������"


}

template<typename T>
void printArray_(T arr[][DIM_SIZE][DIM_SIZE], size_t size) {
    for (int z = 0; z < size; z++) {
        for (int y = 0; y < DIM_SIZE; y++) {
            for (int x = 0; x < DIM_SIZE; x++) {
                cout << arr[z][y][x] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
}

void printArray(const char arr[][ROWS], size_t columns) {
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < columns; x++) {
            printf("%s", arr[y][x]);
        }
        printf("\n");
    }
}

template<typename T>
void printArray(T ***arr, size_t X, size_t Y, size_t Z) {
    for (int z = 0; z < Z; z++) {
        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                cout << arr[z][y][x] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
}

void printArray(int **arr, size_t X, size_t Y) {
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            cout << arr[y][x] << ' ';
        }
        cout << endl;
    }
}

template<typename T>
void printArray(const T *arr, size_t X) {
    for (int x = 0; x < X; x++) {
        cout << arr[x] << ' ';
    }
    cout << endl;
}

template<typename T>
void selectionSort(T arr[], size_t size) {
    if (size < 2) {
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        // find min value
        int minIndex = i;
        T min = arr[minIndex];
        for (int j = i; j < size; j++) {
            if (arr[j] < min) {
                min = arr[j];
                minIndex = j;
            }
        }
        // swap with first not sorted
        if (minIndex != i) {
            T t = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = t;
        }
    }
}

bool contains(const int arr[], size_t size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}
