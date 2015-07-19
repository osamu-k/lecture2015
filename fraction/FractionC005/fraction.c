#include "fraction.h"

#include "gcd.h"
#include <stdbool.h>
#include <limits.h>

static enum fraction_status status = FRACTION_OK;

enum fraction_status fraction_get_status()
{
    return status;
}

void fraction_clear_status()
{
    status = FRACTION_OK;
}

static void reduce( unsigned int *x, unsigned int *y )
{
    unsigned int gcdval = gcd( *x, *y );
    *x /= gcdval;
    *y /= gcdval;
}

static bool will_multiply_overflow( unsigned int x, unsigned int y )
{
    if( x == 0 )
        return false;
    return (UINT_MAX / x) < y;
}

struct fraction fraction_multiply(
    struct fraction fraction1,
    struct fraction fraction2
)
{
    struct fraction fraction3 = {+1,0u,1u};

    if( status != FRACTION_OK )
        return fraction3;

    if( (fraction1.denominator == 0) || (fraction2.denominator == 0) ){
        status = FRACTION_DENOMINATOR_IS_ZERO;
        return fraction3;
    }

    if( (fraction1.numerator == 0) || (fraction2.numerator == 0) ){
        return fraction3;
    }

    reduce( &fraction1.numerator, &fraction1.denominator );
    reduce( &fraction2.numerator, &fraction2.denominator );
    reduce( &fraction1.numerator, &fraction2.denominator );
    reduce( &fraction2.numerator, &fraction1.denominator );

    if( will_multiply_overflow(fraction1.denominator,fraction2.denominator) ){
        status = FRACTION_DENOMINATOR_OVERFLOW;
        return fraction3;
    }
    if( will_multiply_overflow(fraction1.numerator,fraction2.numerator) ){
        status = FRACTION_NUMERATOR_OVERFLOW;
        return fraction3;
    }

    fraction3.numerator = fraction1.numerator * fraction2.numerator;
    fraction3.sign = fraction1.sign * fraction2.sign;
    fraction3.numerator = fraction1.numerator * fraction2.numerator;
    fraction3.denominator = fraction1.denominator * fraction2.denominator;
    return fraction3;
}
