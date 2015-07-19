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
static enum fraction_status status = FRACTION_OK;

enum fraction_status fraction_get_status()
{
    return status;
}

void fraction_clear_status()
{
    status = FRACTION_OK;
}

struct fraction {
    int sign;
    unsigned int numerator;
    unsigned int denominator;
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

}

class fraction_test : public Test
{
public:
    fraction_test(){}
    ~fraction_test(){}

    void SetUp()
    {
        fraction_clear_status();
    }

    void TearDown()
    {

    }
};

TEST_F( fraction_test, multiply_1_1_by_1_1_is_1_1 )
{
    struct fraction f1 = { +1, 1u, 1u };
    struct fraction f2 = { +1, 1u, 1u };

    struct fraction f3 = fraction_multiply( f1, f2 );

    ASSERT_THAT( fraction_get_status(), Eq(FRACTION_OK) );
    ASSERT_THAT( f3.sign, Eq(+1) );
    ASSERT_THAT( f3.numerator, Eq(1u) );
    ASSERT_THAT( f3.denominator, Eq(1u) );
}

TEST_F( fraction_test, multiply_fraction_with_no_GCD )
{
    struct fraction f1 = { +1, 2u, 3u };
    struct fraction f2 = { -1, 5u, 7u };

    struct fraction f3 = fraction_multiply( f1, f2 );

    ASSERT_THAT( fraction_get_status(), Eq(FRACTION_OK) );
    ASSERT_THAT( f3.sign, Eq(-1) );
    ASSERT_THAT( f3.numerator, Eq(2u*5u) );
    ASSERT_THAT( f3.denominator, Eq(3u*7u) );
}

TEST_F( fraction_test, multiply_fraction_with_GCD )
{
    struct fraction f1 = { +1, 2u, 3u };
    struct fraction f2 = { -1, 3u, 5u };

    struct fraction f3 = fraction_multiply( f1, f2 );

    ASSERT_THAT( fraction_get_status(), Eq(FRACTION_OK) );
    ASSERT_THAT( f3.sign, Eq(-1) );
    ASSERT_THAT( f3.numerator, Eq(2u) );
    ASSERT_THAT( f3.denominator, Eq(5u) );
}

TEST_F( fraction_test, multiply_fraction_with_zero_denominator )
{
    struct fraction f1 = { +1, 1u, 0u };
    struct fraction f2 = { -1, 2u, 3u };

    struct fraction f3 = fraction_multiply( f1, f2 );

    ASSERT_THAT( fraction_get_status(), Eq(FRACTION_DENOMINATOR_IS_ZERO) );
}

TEST_F( fraction_test, multiply_fraction_with_zero_numerator )
{
    struct fraction f1 = { +1, 0u, 2u };
    struct fraction f2 = { -1, 1u, 3u };

    struct fraction f3 = fraction_multiply( f1, f2 );

    ASSERT_THAT( fraction_get_status(), Eq(FRACTION_OK) );
    ASSERT_THAT( f3.sign, Eq(+1) );
    ASSERT_THAT( f3.numerator, Eq(0u) );
    ASSERT_THAT( f3.denominator, Eq(1u) );
}

TEST_F( fraction_test, multiply_fraction_with_denominator_overflow )
{
    struct fraction f1 = { +1, 1u, UINT_MAX };
    struct fraction f2 = { -1, 1u, 2u };

    struct fraction f3 = fraction_multiply( f1, f2 );

    ASSERT_THAT( fraction_get_status(), Eq(FRACTION_DENOMINATOR_OVERFLOW) );
}

TEST_F( fraction_test, multiply_fraction_with_numerator_overflow )
{
    struct fraction f1 = { +1, UINT_MAX, 1u };
    struct fraction f2 = { -1, 2u, 1u };

    struct fraction f3 = fraction_multiply( f1, f2 );

    ASSERT_THAT( fraction_get_status(), Eq(FRACTION_NUMERATOR_OVERFLOW) );
}

TEST_F( fraction_test, multiply_fractions_with_large_gcd_1 )
{
    struct fraction f1 = { +1, UINT_MAX, UINT_MAX };
    struct fraction f2 = { -1, 1u, 2u };

    struct fraction f3 = fraction_multiply( f1, f2 );

    ASSERT_THAT( fraction_get_status(), Eq(FRACTION_OK) );
    ASSERT_THAT( f3.sign, Eq(-1) );
    ASSERT_THAT( f3.numerator, Eq(1u) );
    ASSERT_THAT( f3.denominator, Eq(2u) );
}

TEST_F( fraction_test, multiply_fractions_with_large_gcd_2 )
{
    struct fraction f1 = { -1, 1u, 2u };
    struct fraction f2 = { +1, UINT_MAX, UINT_MAX };

    struct fraction f3 = fraction_multiply( f1, f2 );

    ASSERT_THAT( fraction_get_status(), Eq(FRACTION_OK) );
    ASSERT_THAT( f3.sign, Eq(-1) );
    ASSERT_THAT( f3.numerator, Eq(1u) );
    ASSERT_THAT( f3.denominator, Eq(2u) );
}

TEST_F( fraction_test, multiply_fractions_with_large_gcd_3 )
{
    struct fraction f1 = { +1, 1u, UINT_MAX };
    struct fraction f2 = { -1, UINT_MAX, 2u };

    struct fraction f3 = fraction_multiply( f1, f2 );

    ASSERT_THAT( fraction_get_status(), Eq(FRACTION_OK) );
    ASSERT_THAT( f3.sign, Eq(-1) );
    ASSERT_THAT( f3.numerator, Eq(1u) );
    ASSERT_THAT( f3.denominator, Eq(2u) );
}

TEST_F( fraction_test, multiply_fractions_with_large_gcd_4 )
{
    struct fraction f1 = { -1, UINT_MAX, 2u };
    struct fraction f2 = { +1, 1u, UINT_MAX };

    struct fraction f3 = fraction_multiply( f1, f2 );

    ASSERT_THAT( fraction_get_status(), Eq(FRACTION_OK) );
    ASSERT_THAT( f3.sign, Eq(-1) );
    ASSERT_THAT( f3.numerator, Eq(1u) );
    ASSERT_THAT( f3.denominator, Eq(2u) );
}

TEST_F( fraction_test, multiply_many_fractions )
{
    struct fraction f1 = { +1, 1u, 2u };
    struct fraction f2 = { -1, 3u, 5u };
    struct fraction f3 = { +1, 7u, 11u };

    struct fraction f4 = fraction_multiply( fraction_multiply( f1, f2 ), f3 );

    ASSERT_THAT( fraction_get_status(), Eq(FRACTION_OK) );
    ASSERT_THAT( f4.sign, Eq( (+1)*(-1)*(+1) ) );
    ASSERT_THAT( f4.numerator, Eq(1u*3u*7u) );
    ASSERT_THAT( f4.denominator, Eq(2u*5u*11u) );
}

TEST_F( fraction_test, multiply_many_fractions_with_zero_denominator )
{
    struct fraction f1 = { +1, 1u, 2u };
    struct fraction f2 = { -1, 3u, 0u };
    struct fraction f3 = { +1, 7u, 11u };

    struct fraction f4 = fraction_multiply( fraction_multiply( f1, f2 ), f3 );

    ASSERT_THAT( fraction_get_status(), Eq(FRACTION_DENOMINATOR_IS_ZERO) );
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleMock(&argc,argv);
    return RUN_ALL_TESTS();
}
