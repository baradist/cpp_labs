void task1();

void task2();

int IncByValue(int val);

void IncByPointer(int *pInt);

void IncByReference(int &val);

template<typename T>
void Swap(T *pInt, T *pInt1);

template<typename T>
void Swap(T &val, T &val1);