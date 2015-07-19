#include "gmock/gmock.h"
#include <iostream>
#include <limits.h>

using namespace testing;
using namespace std;

template<class T>
T gcd( T x, T y );

template<class T>
T gcd_body( T x, T y );

static void print_log( unsigned int x, unsigned int y )
{
    cout << "type=unsigned int x=" << x << " y=" << y << endl;
}

static void print_log( int x, int y )
{
    cout << "type=int x=" << x << " y=" << y << endl;
}

static void print_log( unsigned long x, unsigned long y )
{
    cout << "type=unsigned long x=" << x << " y=" << y << endl;
}

static void print_log( long x, long y )
{
    cout << "type=long x=" << x << " y=" << y << endl;
}

template<class T>
static void print_log( T x, T y )
{
    cout << "type=other x=" << x << " y=" << y << endl;
}

template<class T>
T gcd( T x, T y )
{
    if( x <= 0 ){
        return 0;
    }
    if( y <= 0 ){
        return 0;
    }
    return gcd_body(x,y);
}

template<class T>
T gcd_body( T x, T y)
{
//    print_log(x,y);
    T m = y % x;
    if( m == 0 ){
        return x;
    }
    else{
        return gcd_body( m, x );
    }
}

TEST( GCD, GCD_of_1_and_1_is_1 )
{
    unsigned int answer = gcd( 1, 1 );
    ASSERT_THAT( answer, Eq(1) );
}

TEST( GCD, GCD_of_2_and_2_is_2 )
{
    unsigned int answer = gcd( 2, 2 );
    ASSERT_THAT( answer, Eq(2) );
}

TEST( GCD, GCD_of_2x3_and_3x5_is_3 )
{
    unsigned int answer = gcd( 2*3, 3*5 );
    ASSERT_THAT( answer, Eq(3) );
}

TEST( GCD, GCD_of_3x5_and_2x3_is_3 )
{
    unsigned int answer = gcd( 3*5, 2*3 );
    ASSERT_THAT( answer, Eq(3) );
}

TEST( GCD, GCD_of_2x3x5_and_3x5x7_is_3x5 )
{
    unsigned int answer = gcd( 2*3*5, 3*5*7 );
    ASSERT_THAT( answer, Eq(3*5) );
}

TEST( GCD, GCD_of_3x5x7_and_2x3x5_is_3x5 )
{
    unsigned int answer = gcd( 3*5*7, 2*3*5 );
    ASSERT_THAT( answer, Eq(3*5) );
}

TEST( GCD, GCD_of_0_and_0_is_0 )
{
    unsigned int answer = gcd( 0, 0 );
    ASSERT_THAT( answer, Eq(0) );
}

TEST( GCD, GCD_of_0_and_positive_is_0 )
{
    unsigned int answer = gcd( 0, 5 );
    ASSERT_THAT( answer, Eq(0) );
}

TEST( GCD, GCD_of_positive_and_0_is_0 )
{
    unsigned int answer = gcd( 5, 0 );
    ASSERT_THAT( answer, Eq(0) );
}

TEST( GCD, GCD_of_maximum_values )
{
    unsigned int answer = gcd( UINT_MAX, UINT_MAX -1 );
    ASSERT_THAT( answer, Ne(0) );
}

TEST( GCD, GCD_of_unsigned_int )
{
    unsigned int answer = gcd( UINT_MAX, UINT_MAX );
    ASSERT_THAT( answer, Eq(UINT_MAX) );
}

TEST( GCD, GCD_of_unsigned_long )
{
    unsigned long answer = gcd( ULONG_MAX, ULONG_MAX );
    ASSERT_THAT( answer, Eq(ULONG_MAX) );
}

TEST( GCD, GCD_of_unsigned_char )
{
    unsigned char answer = gcd( UCHAR_MAX, UCHAR_MAX );
    ASSERT_THAT( answer, Eq(UCHAR_MAX) );
}

TEST( GCD, GCD_of_long )
{
    long answer = gcd( LONG_MAX, LONG_MAX );
    ASSERT_THAT( answer, Eq(LONG_MAX) );
}

//TEST( GCD, GCD_of_double )
//{
//    double answer = gcd( double(6.00), double(15.0)  );
//    ASSERT_THAT( answer, Eq(double(3.0)) );
//}

int main(int argc, char **argv)
{
    ::testing::InitGoogleMock(&argc,argv);
    return RUN_ALL_TESTS();
}
