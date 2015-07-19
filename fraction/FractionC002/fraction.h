#ifndef FRACTION_H
#define FRACTION_H

enum fraction_status {
    FRACTION_OK,
    FRACTION_DENOMINATOR_IS_ZERO,
    FRACTION_DENOMINATOR_OVERFLOW,
    FRACTION_NUMERATOR_OVERFLOW
};

enum fraction_status fraction_multiply(
    int sign1,
    unsigned int numerator1,
    unsigned int denominator1,
    int sign2,
    unsigned int numerator2,
    unsigned int denominator2,
    int *sign3,
    unsigned int *numerator3,
    unsigned int *denominator3
);

#endif // FRACTION_H
