#ifndef GCD_H
#define GCD_H

#include <iostream>
using namespace std;

template<class T>
T gcd( T x, T y );

template<class T>
T gcd_body( T x, T y );

void print_log( unsigned int x, unsigned int y );

void print_log( int x, int y );

void print_log( unsigned long x, unsigned long y );

void print_log( long x, long y );

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

#endif // GCD_H
