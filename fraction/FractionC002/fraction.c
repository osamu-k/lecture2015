#include "fraction.h"
#include "gcd.h"
#include <stdbool.h>
#include <limits.h>

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
)
{
    if( (denominator1 == 0) || (denominator2 == 0) )
        return FRACTION_DENOMINATOR_IS_ZERO;

    if( (numerator1 == 0) || (numerator2 == 0) ){
        *sign3 = +1;
        *numerator3 = 0u;
        *denominator3 = 1u;
        return FRACTION_OK;
    }

    reduce( &numerator1, &denominator1 );
    reduce( &numerator2, &denominator2 );
    reduce( &numerator1, &denominator2 );
    reduce( &numerator2, &denominator1 );

    if( will_multiply_overflow(denominator1,denominator2) )
        return FRACTION_DENOMINATOR_OVERFLOW;
    if( will_multiply_overflow(numerator1,numerator2) )
        return FRACTION_NUMERATOR_OVERFLOW;

    *numerator3 = numerator1 * numerator2;
    *sign3 = sign1 * sign2;
    *numerator3 = numerator1 * numerator2;
    *denominator3 = denominator1 * denominator2;
    return FRACTION_OK;
}
