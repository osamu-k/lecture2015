#include "gmock/gmock.h"
#include "fraction.h"

using namespace testing;

TEST( fraction_test, can_create_fraction_instance )
{
    Fraction f( +1, 2u, 3u );

    ASSERT_THAT( f.sign(), Eq(+1) );
    ASSERT_THAT( f.numerator(), Eq(2u) );
    ASSERT_THAT( f.denominator(), Eq(3u) );
}

TEST( fraction_test, can_create_fraction_instance_2 )
{
    Fraction f( -1, 2u, UINT_MAX );

    ASSERT_THAT( f.sign(), Eq(-1) );
    ASSERT_THAT( f.numerator(), Eq(2u) );
    ASSERT_THAT( f.denominator(), Eq(UINT_MAX) );
}

TEST( fraction_test, can_create_fraction_instance_3 )
{
    Fraction f( -1, UINT_MAX, 2u );

    ASSERT_THAT( f.sign(), Eq(-1) );
    ASSERT_THAT( f.numerator(), Eq(UINT_MAX) );
    ASSERT_THAT( f.denominator(), Eq(2u) );
}

TEST( fraction_test, fraction_is_reduced_in_constructor ){
    Fraction f( -1, 2u*3u*5u*7u, 3u*7u*11u );

    ASSERT_THAT( f.sign(), Eq(-1) );
    ASSERT_THAT( f.numerator(), Eq(2u*5u) );
    ASSERT_THAT( f.denominator(), Eq(11u) );
}

TEST( fraction_test, fraction_of_zero_numerator ){
    Fraction f( -1, 0u, 12345u );

    ASSERT_THAT( f.sign(), Eq(+1) );
    ASSERT_THAT( f.numerator(), Eq(0u) );
    ASSERT_THAT( f.denominator(), Eq(1u) );
}

TEST( fraction_test, multiply_1_1_by_1_1_is_1_1 )
{
    Fraction f1( +1, 1u, 1u );
    Fraction f2( +1, 1u, 1u );

//    Fraction f3 = f1.multiply( f2 );
    Fraction f3 = f1 * f2;

    ASSERT_THAT( f3.sign(), Eq(+1) );
    ASSERT_THAT( f3.numerator(), Eq(1u) );
    ASSERT_THAT( f3.denominator(), Eq(1u) );
}

TEST( fraction_test, multiply_fraction_with_no_GCD )
{
    Fraction f1( +1, 2u, 3u );
    Fraction f2( -1, 5u, 7u );

//    Fraction f3 = f1.multiply( f2 );
    Fraction f3 = f1 * f2;

    ASSERT_THAT( f3.sign(), Eq(-1) );
    ASSERT_THAT( f3.numerator(), Eq(2u*5u) );
    ASSERT_THAT( f3.denominator(), Eq(3u*7u) );
}

TEST( fraction_test, multiply_fraction_with_GCD )
{
    Fraction f1( +1, 2u, 3u );
    Fraction f2( -1, 3u, 5u );

//    Fraction f3 = f1.multiply( f2 );
    Fraction f3 = f1 * f2;

    ASSERT_THAT( f3.sign(), Eq(-1) );
    ASSERT_THAT( f3.numerator(), Eq(2u) );
    ASSERT_THAT( f3.denominator(), Eq(5u) );
}

TEST( fraction_test, multiply_fraction_with_zero_denominator )
{
    try{
        Fraction f1( +1, 1u, 0u );
        Fraction f2( -1, 2u, 3u );

    //    Fraction f3 = f1.multiply( f2 );
        Fraction f3 = f1 * f2;
        FAIL();
    }
    catch( FractionException ex ){
        ASSERT_THAT( ex.status(), Eq(FRACTION_DENOMINATOR_IS_ZERO) );
    }
}

TEST( fraction_test, multiply_fraction_with_zero_numerator )
{
    Fraction f1( +1, 0u, 2u );
    Fraction f2( -1, 1u, 3u );

//    Fraction f3 = f1.multiply( f2 );
    Fraction f3 = f1 * f2;

    ASSERT_THAT( f3.sign(), Eq(+1) );
    ASSERT_THAT( f3.numerator(), Eq(0u) );
    ASSERT_THAT( f3.denominator(), Eq(1u) );
}

TEST( fraction_test, multiply_fraction_with_denominator_overflow )
{
    try{
        Fraction f1( +1, 1u, UINT_MAX );
        Fraction f2( -1, 1u, 2u );

    //    Fraction f3 = f1.multiply( f2 );
        Fraction f3 = f1 * f2;
        FAIL();
    }
    catch( FractionException ex ){
        ASSERT_THAT( ex.status(), Eq(FRACTION_DENOMINATOR_OVERFLOW) );
    }
}

TEST( fraction_test, multiply_fraction_with_numerator_overflow )
{
    try{
        Fraction f1( +1, UINT_MAX, 1u );
        Fraction f2( -1, 2u, 1u );

    //    Fraction f3 = f1.multiply( f2 );
        Fraction f3 = f1 * f2;
        FAIL();
    }
    catch( FractionException ex ){
        ASSERT_THAT( ex.status(), Eq(FRACTION_NUMERATOR_OVERFLOW) );
    }
}

TEST( fraction_test, multiply_fractions_with_large_gcd_1 )
{
    Fraction f1( +1, UINT_MAX, UINT_MAX );
    Fraction f2( -1, 1u, 2u );

//    Fraction f3 = f1.multiply( f2 );
    Fraction f3 = f1 * f2;

    ASSERT_THAT( f3.sign(), Eq(-1) );
    ASSERT_THAT( f3.numerator(), Eq(1u) );
    ASSERT_THAT( f3.denominator(), Eq(2u) );
}

TEST( fraction_test, multiply_fractions_with_large_gcd_2 )
{
    Fraction f1( -1, 1u, 2u );
    Fraction f2( +1, UINT_MAX, UINT_MAX );

//    Fraction f3 = f1.multiply( f2 );
    Fraction f3 = f1 * f2;

    ASSERT_THAT( f3.sign(), Eq(-1) );
    ASSERT_THAT( f3.numerator(), Eq(1u) );
    ASSERT_THAT( f3.denominator(), Eq(2u) );
}

TEST( fraction_test, multiply_fractions_with_large_gcd_3 )
{
    Fraction f1( +1, 1u, UINT_MAX );
    Fraction f2( -1, UINT_MAX, 2u );

//    Fraction f3 = f1.multiply( f2 );
    Fraction f3 = f1 * f2;

    ASSERT_THAT( f3.sign(), Eq(-1) );
    ASSERT_THAT( f3.numerator(), Eq(1u) );
    ASSERT_THAT( f3.denominator(), Eq(2u) );
}

TEST( fraction_test, multiply_fractions_with_large_gcd_4 )
{
    Fraction f1( -1, UINT_MAX, 2u );
    Fraction f2( +1, 1u, UINT_MAX );

//    Fraction f3 = f1.multiply( f2 );
    Fraction f3 = f1 * f2;

    ASSERT_THAT( f3.sign(), Eq(-1) );
    ASSERT_THAT( f3.numerator(), Eq(1u) );
    ASSERT_THAT( f3.denominator(), Eq(2u) );
}

TEST( fraction_test, multiply_many_fractions )
{
    Fraction f1( +1, 1u, 2u );
    Fraction f2( -1, 3u, 5u );
    Fraction f3( +1, 7u, 11u );

    Fraction f4 = f1 * f2 * f3;

    ASSERT_THAT( f4.sign(), Eq( (+1)*(-1)*(+1) ) );
    ASSERT_THAT( f4.numerator(), Eq(1u*3u*7u) );
    ASSERT_THAT( f4.denominator(), Eq(2u*5u*11u) );
}

TEST( fraction_test, multiply_many_fractions_with_denominator_overflow )
{
    try{
        Fraction f1( +1, 1u, 2u );
        Fraction f2( -1, 1u, UINT_MAX );
        Fraction f3( +1, 1u, 3u );

        Fraction f4 = f1 * f2 * f3;
        FAIL();
    }
    catch( FractionException ex ){
        ASSERT_THAT( ex.status(), Eq(FRACTION_DENOMINATOR_OVERFLOW) );
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleMock(&argc,argv);
    return RUN_ALL_TESTS();
}

