#include "gmock/gmock.h"
#include "gcd.h"

using namespace testing;

enum FractionStatus {
    FRACTION_OK,
    FRACTION_DENOMINATOR_IS_ZERO,
    FRACTION_DENOMINATOR_OVERFLOW,
    FRACTION_NUMERATOR_OVERFLOW
};

class Fraction
{
public:
    Fraction( int size, unsigned int numerator, unsigned int denominator );
    Fraction();
    ~Fraction();
    int sign() const;
    unsigned int numerator() const;
    unsigned int denominator() const;
    Fraction multiply( const Fraction &other ) const;
    Fraction operator*( const Fraction &other ) const;
private:
    static void reduce( unsigned int &x, unsigned int &y );
    static bool will_multiply_overflow( unsigned int x, unsigned int y );
    int m_sign;
    unsigned int m_numerator;
    unsigned int m_denominator;
};

class FractionException
{
public:
    FractionException( FractionStatus status );
    FractionStatus status() const;
private:
    FractionStatus m_status;
};


Fraction::Fraction( int sign, unsigned int numerator, unsigned int denominator )
    : m_sign(sign)
    , m_numerator(numerator)
    , m_denominator(denominator)
{
    if( denominator == 0 )
        throw FractionException( FRACTION_DENOMINATOR_IS_ZERO );
    if( numerator == 0 ){
        m_sign = +1;
        m_denominator = 1u;
    }
    else{
        unsigned int gcdval = gcd(numerator,denominator);
        m_numerator /= gcdval;
        m_denominator /= gcdval;
    }
}

Fraction::Fraction()
    : m_sign(+1)
    , m_numerator(0u)
    , m_denominator(1u)
{
}

Fraction::~Fraction()
{
}

int Fraction::sign() const
{
    return m_sign;
}

unsigned int Fraction::numerator() const
{
    return m_numerator;
}

unsigned int Fraction::denominator() const
{
    return m_denominator;
}

Fraction Fraction::multiply( const Fraction &other ) const
{
    unsigned int n1 = numerator();
    unsigned int d1 = denominator();
    unsigned int n2 = other.numerator();
    unsigned int d2 = other.denominator();

    if( (n1 == 0) || (n2 == 0) ){
        return Fraction();
    }

    reduce( n1, d2 );
    reduce( n2, d1 );

    if( will_multiply_overflow(d1,d2) ){
        throw FractionException( FRACTION_DENOMINATOR_OVERFLOW );
    }
    if( will_multiply_overflow(n1,n2) ){
        throw FractionException( FRACTION_NUMERATOR_OVERFLOW );
    }

    int s = sign() * other.sign();
    unsigned int n = n1 * n2;
    unsigned int d = d1 * d2;
    return Fraction(s,n,d);
}

Fraction Fraction::operator*( const Fraction &other ) const
{
    return multiply( other );
}

void Fraction::reduce( unsigned int &x, unsigned int &y )
{
    unsigned int gcdval = gcd( x, y );
    x /= gcdval;
    y /= gcdval;
}

bool Fraction::will_multiply_overflow( unsigned int x, unsigned int y )
{
    if( x == 0 )
        return false;
    return (UINT_MAX / x) < y;
}

FractionException::FractionException( FractionStatus status )
    : m_status(status)
{
}

FractionStatus FractionException::status() const
{
    return m_status;
}


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

