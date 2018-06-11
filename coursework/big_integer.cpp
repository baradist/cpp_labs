#include <cstdio>

#include "big_integer.h"

void printBigInteger(BigInteger &value) {
    for (size_t i = 0; i < value.n; i++) {
        printf(" %0*x", 2, value.p[i]);
    }
    printf("\n");
}

BigInteger *multiply(BigInteger &val1, BigInteger &val2) {
    unsigned char *op1 = val1.p;
    size_t size1 = val1.n;
    unsigned char *op2 = val2.p;
    size_t size2 = val2.n;
    size_t newSize = size1 + size2;
    unsigned char *result = new unsigned char[newSize];
    for (int k = 0; k < newSize; ++k) {
        result[k] = 0;
    }

    for (int i = 0; i < size2 * 8; ++i) {
        for (int j = 0; j < size1 * 8; ++j) {
            if ((op1[j / 8] & (1 << (j % 8))) && (op2[i / 8] & (1 << (i % 8))) &&
                result[(i + j) / 8] & (1 << (i + j) % 8)) {
                int caret = i + j;
                while (result[caret / 8] & (1 << (caret % 8))) {
                    result[caret / 8] ^= (1 << (caret % 8));
                    caret++;
                }
                result[caret / 8] |= (1 << (caret % 8));
            } else if ((op1[j / 8] & (1 << (j % 8))) && (op2[i / 8] & (1 << (i % 8)))) {
                result[(i + j) / 8] |= (1 << (i + j) % 8);
            }
        }
    }
    return new BigInteger{result, newSize};
}
