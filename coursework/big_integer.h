#pragma once

struct BigInteger {
    unsigned char *p;
    size_t n;
};

void printBigInteger(BigInteger &value);

BigInteger *multiply(BigInteger &val1, BigInteger &val2);
