void task1();

void task2();

int IncByValue(int val);

void IncByPointer(int *pInt);

void IncByReference(int &val);

template<typename T>
void Swap(T *pInt, T *pInt1);

template<typename T>
void Swap(T &val, T &val1);

void task3();

const size_t N = 2;
const size_t M = 4;

int Min(const int pInt[][M], size_t X);

template<typename T>
int Min(T **ppT, size_t X, size_t Y);

int MyStrCmp(const char *s1, const char *s2);

template<typename T>
void printArray(T **arr, size_t X, size_t Y);

void task4();

int isLeapYear(unsigned int year);

int DayOfYear(unsigned int year, int month, int day);

int daysInMonth(const int &year, const int &month);

void DayOfMonth(const int &year, const int &dayOfYear, int &dayOfMonth, int &month);

void testTask4(int nDayTab[2][12], int testYear);

void task5();

template <typename T>
bool addUnique(T **pVal, size_t *pSize, T val);

template<typename T>
bool myEqual(T t, T t1);

template<typename T>
void printArray(const T *pVal, size_t size);

void task6();

int sequenceSum(int n);

void task7();

void VarArgs1(int arg1,...);

void task8();

int *MyMin(int *pInt, size_t size);
