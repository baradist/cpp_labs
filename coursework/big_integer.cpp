#include <cstdio>
#include <cstdarg>

#include "big_integer.h"

void printBigInteger(const BigInteger *value) {
    for (int i = value->n - 1; i >= 0; i--) {
        printf(" %0*x", 2, value->p[i]);
    }
    printf("\n");
}

inline int index(int x) {
    return x / 8;
}

inline int bit(int x) {
    return x % 8;
}

BigInteger *multiply(const BigInteger *val1, const BigInteger *val2) {
    unsigned char *op1 = val1->p;
    size_t size1 = val1->n;
    unsigned char *op2 = val2->p;
    size_t size2 = val2->n;
    size_t newSize = size1 + size2;
    unsigned char *result = new unsigned char[newSize];
    for (int k = 0; k < newSize; ++k) {
        result[k] = 0;
    }

    for (int i = 0; i < size2 * 8; ++i) {
        for (int j = 0; j < size1 * 8; ++j) {
            if ((op1[index(j)] & (1 << bit(j))) && (op2[index(i)] & (1 << bit(i))) &&
                result[index(i + j)] & (1 << bit(i + j))) {
                int caret = i + j;
                while (result[index(caret)] & (1 << bit(caret))) {
                    result[index(caret)] ^= (1 << bit(caret));
                    caret++;
                }
                result[index(caret)] |= (1 << bit(caret));
            } else if ((op1[index(j)] & (1 << bit(j))) && (op2[index(i)] & (1 << bit(i)))) {
                result[index(i + j)] |= (1 << bit(i + j));
            }
        }
    }
    if (result[newSize - 1] == 0x00) {
        newSize--;
    }
    return new BigInteger{result, newSize};
}

BigInteger *valueOf(size_t size, unsigned char first, ...) {
    BigInteger *result = new BigInteger{new unsigned char[size], size};
    unsigned char val = first;
    va_list p;
    va_start(p, first);
    for (int i = size - 1; i >= 0; --i, val = va_arg(p, int)) { // TODO ???
        result->p[i] = val;
    }
    va_end(p);
    return result;
}

void deleteBigInteger(BigInteger *pInteger) {
    delete[] pInteger->p;
    delete pInteger;
}
