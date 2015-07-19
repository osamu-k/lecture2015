#ifndef FRACTION_H
#define FRACTION_H

enum fraction_status {
    FRACTION_OK,
    FRACTION_DENOMINATOR_IS_ZERO,
    FRACTION_DENOMINATOR_OVERFLOW,
    FRACTION_NUMERATOR_OVERFLOW
};

enum fraction_status fraction_get_status();
void fraction_clear_status();

struct fraction {
    int sign;
    unsigned int numerator;
    unsigned int denominator;
};

struct fraction fraction_multiply(
    struct fraction fraction1,
    struct fraction fraction2
);

#endif // FRACTION_H
