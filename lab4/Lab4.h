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

int Min(const int pInt[N][M]);

template<typename T>
int Min(T **ppT, size_t X, size_t Y);

int MyStrCmp(const char *s1, const char *s2);

template<typename T>
void printArray(T **arr, size_t X, size_t Y);
