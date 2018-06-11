#include <cstdio>
#include <cstring>

#include "big_integer.h"

void printBigInteger(unsigned char * op, size_t size) {
    for (size_t i = 0; i < size; i++)
    {
        printf(" %0*x", 2, op[i]);
    }
    printf("\n");
}

unsigned char* multiply(unsigned char *op1, size_t size1, unsigned char *op2, size_t size2) {

    unsigned char *result = new unsigned char[size1 + size2];
    for (int k = 0; k < size1 + size2; ++k) {
        result[k] = 0;
    }

    for (int i = 0; i < size2 * 8; ++i) {
        for (int j = 0; j < size1 * 8; ++j) {
            if((op1[j / 8] & (1 << (j % 8))) && (op2[i / 8] & (1 << (i % 8))) && result[(i + j) / 8] & (1 << (i + j) % 8)) {
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
    return result;
}

int main() {
    unsigned char op1[] = {0x3, 0x3};
    unsigned char op2[] = {0x2};

    printBigInteger(op1, 2);
    printBigInteger(op2, 1);
    printBigInteger(multiply(op1, 2, op2, 1), 3);

    return 0;
}
