#include <cstring>

#include "big_integer.h"

int main() {
    BigInteger *op1 = new BigInteger{new unsigned char[2]{0x0, 0x3}, 2};
    BigInteger *op2 = new BigInteger{new unsigned char[1]{0x2}, 1};

    printBigInteger(*op1);
    printBigInteger(*op2);
    printBigInteger(*multiply(*op1, *op2));

    return 0;
}
