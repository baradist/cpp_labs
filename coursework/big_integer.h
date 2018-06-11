#pragma once

struct BigInteger {
    unsigned char *p;
    size_t n;
};

void printBigInteger(const BigInteger *value);

void printBits(const BigInteger *bigInteger);

BigInteger *multiply(const BigInteger *val1, const BigInteger *val2);

void deleteBigInteger(BigInteger *pInteger);

BigInteger *valueOf(size_t size, unsigned char first, ...);
