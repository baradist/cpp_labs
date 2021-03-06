/*************************************************************
	Практическое занятие №2. Побитовые операторы.
							Директивы препроцессора.
							Указатели.
*************************************************************/
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <tchar.h>

#define	  stop __asm nop	//с помощью директивы препроцессора задаем
							//макроподстановку


void printBits(int value, bool printAll);
void printBits(short value);

int _tmain()
{
	using namespace std; // я знаю, что так лучше не писать
// ********************************************************
	//Задание 1. Побитовая арифметика (and, or, xor, not), сдвиги.
	//1.1
	{
		int y;//Задайте значение y, например, с помощью потока ввода
		y = 192; // cin >> y;
		cout << y << endl;
		//С помощью побитовых операторов и операторов сдвига выведите значение "y"
		//на консоль в двоичном виде, например:
		//если y==9, то
		// а) 0 0 0 0 ...   0 0 1 0 0 1 (всего 32 двоичных цифры)
		printBits(y, false);
		// б) пропустите незначащие нули -  1 0 0 1
		cout << endl;
		printBits(y, true);
	}
	

	//1.2 Дана целая переменная
	{
		int y;//Задайте значение y, например, с помощью потока ввода
		y = 205; // cin >> y;
#ifdef _DEBUG
		printBits(y, true);
#endif
		//"Сдвиньте" все единицы в сформированном значении вправо, например:
		//было:   0100 1111 0000 0000 0110 1111 0000 0010
		//стало:  0000 0000 0000 0000 0000 1111 1111 1111
		//Реализовать задачу посредством одного цикла!
		int currentBitMask = 1;
		int size = sizeof(y) * 8;
		for (int i = 0, offset = 0; i < size; i++) {
			if ((y & currentBitMask) >> offset) {
				offset++;
				currentBitMask = currentBitMask << 1;
			}
			else {
				int mask = (1 << offset) - 1; // number of ones equals offset
				int right = y & mask;
				int revertedMask = ((-1) ^ mask); // number of zeroes equals offset
				int left = (y & revertedMask) >> 1;
#ifdef _DEBUG
				cout << "Left:" << endl;
				printBits(left, true);
				cout << "Right:" << endl;
				printBits(right, true);
#endif
				y = right | left;
			}
#ifdef _DEBUG
			cout << "offset = " << offset << endl;
			printBits(y, true);
#endif
		}
		cout << "Result:" << endl;
		printBits(y, true);
		stop
	}


	//1.3 Какие операции следует применить к заданному ниже операнду sNum для
	//того, чтобы переменная sRes приняла требуемое значение?
	//Замечание 1: значения подобраны таким образом, что в каждом случае достаточно
	//использовать один оператор (и при необходимости маску) 
	//Замечание 2: посредством оператора xor (подобрав соответствующую маску)
	//можно получить любое значение => этот оператор предполагается использовать
	//в том случае, когда все остальные уже "не спасают" 
	{
	short sNum = 0x8008; // 10000000 00001000
	short sRes;
	printBits(sNum);
	//0x7ff7
	//printBits(0x7ff7);
	printBits(sRes = (-1) ^ sNum);
	//0x8ff8
	//printBits(0x8ff8); // 10001111 11111000
	printBits(sRes = 0x8ff8); // ???
	//0x0008
	//printBits(0x0008);
	printBits(sRes = sRes & 8);
	//0x7f08
	//printBits(0x7f08);
	printBits(sRes = sRes | 0x7f00);
	//0xf001
	//printBits(0xf001);
	printBits(sRes = sRes ^ 0x8f09);
	//0x0010
	//printBits(0x0010);
	printBits(sRes = sRes ^ 0xf011);
	stop
	}

	stop
// ********************************************************
	//Задание 2. Директивы препроцессора

	//2.1. Использование "математических" макросов стандартной библиотеки:
	//в заголовочном файле <cmath> (который в свою очередь включает старый
	//файл math.h) определены часто используемые математические
	//константы, например M_PI. Воспользуйтесь этой константой для
	//вычисления длины окружности.
	//Обратите внимание: определения констант в свою очередь тоже заключены
	//в директивы условной трансляции. Что еще, кроме подключения заголовочного
	//файла, требуется сделать???



	
	//2.2.Макросы с параметрами.
	//2.2.1 Напишите свою макроподстановку LENGTH которая вычисляет длину окружности.
	// протестируйте написанный макрос для следующих ситуаций:
	{
		#define LENGTH(x) sizeof(x)
		float l1 = LENGTH(1 + 2); // должно быть 18.8495...
		float l2 = 1 / LENGTH(2); // должно быть 0.07957...
	}

	//2.2.2 определите макрос MAX(A, B)  для вычисления б'ольшего
	//значения из двух.
	
	//Используйте макрос следующим образом. Следите за изменением
	//значений переменных k, i, j. Объясните результат.
	//Постарайтесь убрать побочные эффекты.
	//Отметьте случаи, когда избежать побочных эффектов невозможно

	#define MAX(x, y) ((x) < (y) ? (y) : (x))
	int i = 10, j = 12, k;
	k = MAX(i, j);
	k = MAX(j, i) * 2;
	k = MAX(j, i+3);
	k = MAX(i--, j++);

	//2.2.3 определите макрос EXCHANGE(X, Y)  для перестановки
	//двух объектов типа int в памяти местами. Проверьте для приведенного
	//фрагмента. Подумайте, что будет делать макроподстановка, если
	//переставляемые значения разного типа???

	#define EXCHANGE(x, y) { int t = x; x = y; y = t; }
	int x1=1, y1=-1;
	EXCHANGE(x1,y1);

	int x2=100, y2=-100;
	EXCHANGE(x2,y2);


	//2.3. Директивы условной трансляции
	//Выполняя следующий фрагмент, посмотрите, какое
	//значение принимает переменная iNN. Что нужно сделать
	//для того, чтобы результат был равен 0? 1? 2?

	int iNN;
	#define NNN
	#define MMM

	#if defined NNN && defined MMM
		iNN = 0;
	#elif defined MMM
		iNN = 1;
	#elif defined NNN 
		iNN = 2;

	#else
		iNN = -1;
	#endif
		stop

			//Задание 2.4. Загляните в Project/Properties -> диалоговая панель
			//- Property Pages/C\C++/Preprocessor/Preprocessor definitions.
			//В опциях командной строки в зависимости от мишени сборки проекта
			//(Debug или Release) может быть определено с помощью ключа /D
			//имя _DEBUG. С помощью директив условной
			//трансляции напишите фрагмент кода, который в зависимости от типа
			//мишени выводит с помощью cout разный текст на консоль. Проверьте
			//при разных мишенях сборки.

			//Пусть
			//для мишени Debug в процессе выполнения данного участка
			//кода на экран выводится информация об
			//имени файла, номере строки с функцией вывода, дате и времени 
			//компиляции файла, содержащего данную функцию вывода,
			//а также имя функции, содержащей данную строку.

			//Для мишени Release должна быть просто выведена строка
			//"Release configuration!"

			//Подсказка: для получения нужной информации введите в инструментальном
			//окне 'Index' справочной системы следующую ключевую фразу:	Predefined Macros

			//Подсказка: мишень сборки проекта можно
			//поменять следующим образом - Build/Configuration Manager/Configuration

#ifdef _DEBUG
			cout << __FUNCTION__ << " " << __DATE__ << endl;
#else
			cout << "Release configuration!" << endl;
#endif // _DEBUG

	//Задание 2.5. Управляя определенностью идентификатора _UNICODE и используя
	//возможности заголовочного <tchar.h>, объявите и проинициализируйте переменную,
	//которая может становиться как однобайтовой, так и расширенной без 
	//изменения исходного текста.
	//С помощью отладчика проверьте результат.

	TCHAR ch = __T('ф'); // code is 0
	size_t size = sizeof(ch);

// ********************************************************
	//Задание 3.Заголовочные файлы. Директива #include
	//3.1.Создайте и подключите к проекту два заголовочных файла 1.h и 2.h
	//В каждом заголовочном файле объявите перечисление с одинаковыми именами
	//констант, но сопоставьте именованным константам разные значения, например:
	//1.h - enum MyEnum{My1, My2, My3};  . 2.h - enum MyEnum{My1, My2, My3};
	//С помощью директив условной трансляции в DEBUG-версии пользуйтесь значениями
	//констант из 1.h, а в RELEASE-версии значениями констант из 2.h

#ifdef _DEBUG
#include "1.h"
#else
#include "2.h"
#endif // _DEBUG

#ifdef _DEBUG
	MyEnum myEnum = My1;
#else
	MyEnum myEnum = My1;
#endif // _DEBUG

// ********************************************************

	//Задание 4. Указатели
    //Определите объекты разных типов и с разным временем жизни 
    //(локальные, глобальные, статические...) и проинициализируйте их или присвойте им значения
    //Определите указатели соответствующих типов и проинициализируйте их
    //адресами заданных объектов.
    //Выполняя задание, с помощью отладчика посмотрите, какие значения
    //будут присвоены переменным-указателям и на что эти указатели
    //"указывают"

	int intGlobal = 7;
	static int intStaticGlobal = 8;
	int* pIntLocal;
	{
		int intLocal = 9;
		pIntLocal = &intLocal;
	}
	int* pInteger = &intGlobal;
	pInteger = &intStaticGlobal;

	//Задание 4а. Определите указатель на тип char и проинициализируйте
	//его адресом строкового литерала. Присвойте переменной типа char значение
	//любого элемента строки.
	//Проверьте - возможно ли присвоить какое-либо значение по адресу,
	//задаваемому указателем?
	char hello [] = "Hello";
	char* pChar = hello;
	*pChar = 'a';

	stop


	//Задание 5. Арифметика указателей. Операция разыменования указателя.
	//Выполняя задание, следите за изменением значений
	//указателей и значений объектов, на которые они указывают.
	//Интерпретируте наблюдаемые результаты
	{
		int nAr[3] = {1,3};
		int* pn = &nAr[0];
		(*pn)++;	
		pn++;	

		char cAr[]={'A','B','C','D'};
		char* pc = &cAr[0];
		(*pc)=(*pc)+5;	
		pc=pc+3;	
	
		double dAr[3]={1.0,2.0};
		double* pd1 = &dAr[0];
		double* pd2 = pd1;
		(*pd2)+=2;
		pd2+=2;

		//Объясните результат выполнения операции
		//вычитания двух указателей
		pd1 = &dAr[0];
		pd2 = &dAr[1];
		int nNumber=pd2 - pd1; // результат вычитания для указателей - "расстояние" между ними

		//Сравните указатели pd2 и pd1 и с помощью cout
		//выведите результаты сравнения.
		cout << (pd2 > pd1) << endl; // true
		stop
	}


	//Задание 6. Явное преобразование указателя. Иногда возникает
	//необходимость одни и те же данные интерпретировать по-разному,
	//например, целое можно представить как совокупность четырех
	//байтов и работать с каждым байтом по отдельности. Для этого
	//нужно иметь возможность "указывать" как на целое, так и на байт. 
	//Следовательно, возникает необходимость явного преобразования
	//указателя. 
	//Подсказка: для правильной интерпретации этого задания воспользуйтесь
	//возможностями отладчика представлять данные в интересующем
	//Вас виде (в данном случае - в шестнадцатеричном) - для
	//этого используйте правую клавишу мыши,находясь в окне
	//переменных и изменяйте пункт - Hexadecimal display !!!!!

    unsigned int nObject5 = 0x55667788;
	unsigned int* pnObject5 = &nObject5;

	//Раскомментировав следующую строчку кода, обратите внимание
	//на сообщение компилятора - он не считает преобразование 
	//"легальным" (безопасным)
	unsigned char* pucObject5;
	//pucObject5=static_cast<unsigned char*>(pnObject5);	//(1)
	pucObject5=reinterpret_cast<unsigned char*>(pnObject5);	//а такое
				//преобразование - целиком на совести программиста.
				//Его можно применять, только четко представляя себе
				//результат преобразования (2)

	//Откомментируйте следующие строчки сс==..., p - изменился? *p=...
	char cc = *(pucObject5++);
	cc = (*pucObject5)++;// w

	cc = ++*(pucObject5); // y
	cc = *(++pucObject5);
	stop

	//Задание 7. Void-указатель. 
	//Выполняя задание, посмотрите - какие значения присваиваются
	//void-указателю. Обратите внимание: средствами отладчика Вы
	//не можете посмотреть значения, на которые "указывает"
	//void-указатель
	void*	pVoid;	//объявление void-указателя
	int	nObject3=5;
	char cObject3='A';
	int*	pInt = &nObject3;	
	pVoid=&nObject3;
	pVoid=&cObject3;
	pVoid=pInt;
	
	//Прежде, чем раскомментировать следующую строчку, вспомните:
	//что нужно сделать, чтобы выражение стало корректным 	
	pInt = static_cast<int*>(pVoid);

	//Что нужно сделать для того, чтобы следующее закомментированное выражение
	//стало корректным?
	{
		const int n = 1;
		const void* pVoid = &n;//????объявить слева void-указатель
	}



	//7a. При выполнении следующего фрагмента посмотрите, какие неприятности
	//могут Вас ожидать при явном приведении типа void-указателя,
	//который в момент времени (1) указывает на double, к типу 
	//указателя на int (2) 

	double dObject3 = 33.33;
	pVoid = &dObject3;	//(1)

	int nTmp = *(static_cast<int*>(pVoid) ); //(2) мусор
	stop
	{
		//Задание 8. Модификатор const. В каждом из заданий
		//объявите указатель требуемого вида. Посредством каждого
		//указателя попробуйте:
		//получить значение по адресу
		//записать новое значение по адресу
		//модифицировать указатель

		//Задание 8a. Указатель является константой. 
	int value = 42;
	int* const pConstPointerValue = &value;
	cout << "8a: " << *pConstPointerValue << endl;
	*pConstPointerValue = 43;

	stop

		//Задание 8б. Указываемое значение является константой.
	value = 42;
	const int* pConstValue = &value;
	cout << "8б: " << *pConstValue << endl;
	//*pConstValue = 43; // expression must be a modifiable lvalue

	stop

		//Задание 8в. И указатель, и указываемое значение
		//являются константами. 
	value = 42;
	const int* const pConstPointerConstValue = &value;
	cout << "8в: " << *pConstPointerConstValue << endl;
	//*pConstPointerConstValue = 43; // expression must be a modifiable value

	stop

		//Задание 8г. Указатель на переменную, объявленную с
		//ключевым словом const. 
	const int nN = 1;
	//Объявите указатель и проинициализируйте его выражением - &nN	
	const int* pConstValue1 = &nN; // doesn't work without const
	cout << "8г: " << *pConstValue1 << endl;
	//*pConstValue1 = 43; // expression must be a modifiable value
	
	stop
	}

	//Задание 9.При выполнении задания обратите внимание на то,
	//как наглядно отладчик "раскрывает" конструкции типа
	//"указатель на указатель" и на способы получения конечного
	//объекта по таким "иерархическим" указателям
	int	n1=1;

    //Объявите указатель pn и проинициализируйте его так, чтобы он
	//"указывал" на n1
	int* pn = &n1;

    //Объявите указатель ppn и проинициализируйте его так, чтобы он
	//"указывал" на pn
	int** ppn = &pn;

    //Объявите указатель pppn и проинициализируйте его так, чтобы он
	//"указывал" на ppn
	int*** pppn = &ppn;
  
	//С помощью указателей pn, ppn и ppn получите значение объекта n1
	//и присвойте его n2

	int n2 = *pn;
	n2 = **ppn;
	n2 = ***pppn;
  
	stop

	return 0;
}//end main

void printBits(int value, bool printAll) {
	using namespace std;
	if (printAll) {
		cout << "All bits of value " << value << ":" << endl;
	}
	else {
		cout << "Bits of value " << value << " (skip first zeroes):" << endl;
	}
	int length = 8 * sizeof(value);
	bool skip = true;
	for (int i = length - 1; i >= 0; i--) {
		bool nextVal = ((value >> i) & 1);
		if (skip && nextVal) {
			skip = false;
		}
		if (printAll || !skip) {
			cout << nextVal;
			if (!(i % 8)) {
				cout << ' ';
			}
		}

	}
	cout << endl;
}

void printBits(short value) {
	using namespace std;
		cout << "All bits of value " << value << ":" << endl;
	int length = 8 * sizeof(value);
	
	for (int i = length - 1; i >= 0; i--) 
	{
		cout << ((value >> i) & 1);
		if (!(i % 8)) {
			cout << ' ';
		}
	}
	cout << endl;
}
