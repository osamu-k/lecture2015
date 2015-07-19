#ifndef FRACTION_H
#define FRACTION_H

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

#endif // FRACTION_H
