#include "fraction.h"
#include "gcd.h"
#include <limits.h>

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
