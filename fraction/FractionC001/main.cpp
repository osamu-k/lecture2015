#include "gmock/gmock.h"
using namespace testing;

extern "C"
{
#include "gcd.h"

enum fraction_status {
    FRACTION_OK,
    FRACTION_DENOMINATOR_IS_ZERO,
    FRACTION_DENOMINATOR_OVERFLOW,
    FRACTION_NUMERATOR_OVERFLOW
};

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

}


TEST( fraction, multiply_1_1_by_1_1_is_1_1 )
{
    int sign1 = +1;
    unsigned int numerator1 = 1;
    unsigned int denominator1 = 1;

    int sign2 = +1;
    unsigned int numerator2 = 1;
    unsigned int denominator2 = 1;

    int sign3 = 0;
    unsigned int numerator3 = 0;
    unsigned int denominator3 = 0;

    enum fraction_status status = fraction_multiply(
        sign1, numerator1, denominator1,
        sign2, numerator2, denominator2,
        &sign3, &numerator3, &denominator3
    );

    ASSERT_THAT( status, Eq(FRACTION_OK) );
    ASSERT_THAT( sign3, Eq(+1) );
    ASSERT_THAT( numerator3, Eq(1u) );
    ASSERT_THAT( denominator3, Eq(1u) );
}

TEST( fraction, multiply_fraction_with_no_GCD )
{
    int sign = 0;
    unsigned int numerator = 0;
    unsigned int denominator = 0;

    enum fraction_status status = fraction_multiply(
        +1, 2u, 3u,
        -1, 5u, 7u,
        &sign, &numerator, &denominator
    );

    ASSERT_THAT( status, Eq(FRACTION_OK) );
    ASSERT_THAT( sign, Eq(-1) );
    ASSERT_THAT( numerator, Eq(2u*5u) );
    ASSERT_THAT( denominator, Eq(3u*7u) );
}

TEST( fraction, multiply_fraction_with_GCD )
{
    int sign = 0;
    unsigned int numerator = 0;
    unsigned int denominator = 0;

    enum fraction_status status = fraction_multiply(
        +1, 2u, 3u,
        -1, 3u, 5u,
        &sign, &numerator, &denominator
    );

    ASSERT_THAT( status, Eq(FRACTION_OK) );
    ASSERT_THAT( sign, Eq(-1) );
    ASSERT_THAT( numerator, Eq(2u) );
    ASSERT_THAT( denominator, Eq(5u) );
}

TEST( fraction, multiply_fraction_with_zero_denominator )
{
    int sign = 0;
    unsigned int numerator = 0;
    unsigned int denominator = 0;

    enum fraction_status status = fraction_multiply(
        +1, 1u, 0u,
        -1, 2u, 3u,
        &sign, &numerator, &denominator
    );

    ASSERT_THAT( status, Eq(FRACTION_DENOMINATOR_IS_ZERO) );
}

TEST( fraction, multiply_fraction_with_zero_numerator )
{
    int sign = 0;
    unsigned int numerator = 0;
    unsigned int denominator = 0;

    enum fraction_status status = fraction_multiply(
        +1, 0u, 2u,
        -1, 1u, 3u,
        &sign, &numerator, &denominator
    );

    ASSERT_THAT( status, Eq(FRACTION_OK) );
    ASSERT_THAT( sign, Eq(+1) );
    ASSERT_THAT( numerator, Eq(0u) );
    ASSERT_THAT( denominator, Eq(1u) );
}

TEST( fraction, multiply_fraction_with_denominator_overflow )
{
    int sign = 0;
    unsigned int numerator = 0;
    unsigned int denominator = 0;

    enum fraction_status status = fraction_multiply(
        +1, 1u, UINT_MAX,
        -1, 1u, 2u,
        &sign, &numerator, &denominator
    );

    ASSERT_THAT( status, Eq(FRACTION_DENOMINATOR_OVERFLOW) );
}

TEST( fraction, multiply_fraction_with_numerator_overflow )
{
    int sign = 0;
    unsigned int numerator = 0;
    unsigned int denominator = 0;

    enum fraction_status status = fraction_multiply(
        +1, UINT_MAX, 1u,
        -1, 2u, 1u,
        &sign, &numerator, &denominator
    );

    ASSERT_THAT( status, Eq(FRACTION_NUMERATOR_OVERFLOW) );
}

TEST( fraction, multiply_fractions_with_large_gcd_1 )
{
    int sign = 0;
    unsigned int numerator = 0;
    unsigned int denominator = 0;

    enum fraction_status status = fraction_multiply(
        +1, UINT_MAX, UINT_MAX,
        -1, 1u, 2u,
        &sign, &numerator, &denominator
    );

    ASSERT_THAT( status, Eq(FRACTION_OK) );
    ASSERT_THAT( sign, Eq(-1) );
    ASSERT_THAT( numerator, Eq(1u) );
    ASSERT_THAT( denominator, Eq(2u) );
}

TEST( fraction, multiply_fractions_with_large_gcd_2 )
{
    int sign = 0;
    unsigned int numerator = 0;
    unsigned int denominator = 0;

    enum fraction_status status = fraction_multiply(
        -1, 1u, 2u,
        +1, UINT_MAX, UINT_MAX,
        &sign, &numerator, &denominator
    );

    ASSERT_THAT( status, Eq(FRACTION_OK) );
    ASSERT_THAT( sign, Eq(-1) );
    ASSERT_THAT( numerator, Eq(1u) );
    ASSERT_THAT( denominator, Eq(2u) );
}

TEST( fraction, multiply_fractions_with_large_gcd_3 )
{
    int sign = 0;
    unsigned int numerator = 0;
    unsigned int denominator = 0;

    enum fraction_status status = fraction_multiply(
        +1, 1u, UINT_MAX,
        -1, UINT_MAX, 2u,
        &sign, &numerator, &denominator
    );

    ASSERT_THAT( status, Eq(FRACTION_OK) );
    ASSERT_THAT( sign, Eq(-1) );
    ASSERT_THAT( numerator, Eq(1u) );
    ASSERT_THAT( denominator, Eq(2u) );
}

TEST( fraction, multiply_fractions_with_large_gcd_4 )
{
    int sign = 0;
    unsigned int numerator = 0;
    unsigned int denominator = 0;

    enum fraction_status status = fraction_multiply(
        -1, UINT_MAX, 2u,
        +1, 1u, UINT_MAX,
        &sign, &numerator, &denominator
    );

    ASSERT_THAT( status, Eq(FRACTION_OK) );
    ASSERT_THAT( sign, Eq(-1) );
    ASSERT_THAT( numerator, Eq(1u) );
    ASSERT_THAT( denominator, Eq(2u) );
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleMock(&argc,argv);
    return RUN_ALL_TESTS();
}
