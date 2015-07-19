#include "gmock/gmock.h"
using namespace testing;

extern "C"
{
#include "fraction.h"
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
