#include <cstring>

#include "big_integer.h"

int main() {
    BigInteger *op1 = valueOf(4, 0xff, 0x2, 0x3, 0x4);
    BigInteger *op2 = valueOf(2, 0xff, 0x0);

    printBigInteger(op1);
    printBigInteger(op2);
    BigInteger *result = multiply(op1, op2);
    printBigInteger(result);

    deleteBigInteger(op1);
    deleteBigInteger(op2);
    deleteBigInteger(result);
    return 0;
}
