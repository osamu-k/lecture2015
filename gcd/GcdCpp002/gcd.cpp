#include "gcd.h"
#include <iostream>
using namespace std;

static unsigned int gcd_body( unsigned int x, unsigned int y );

unsigned int gcd( unsigned int x, unsigned int y )
{
    if( x <= 0 ){
        return 0;
    }
    if( y <= 0 ){
        return 0;
    }
    return gcd_body(x,y);
}

static unsigned int gcd_body( unsigned int x, unsigned int y)
{
//    cout << "x=" << x << " y=" << y << endl;
    unsigned int m = y % x;
    if( m == 0 ){
        return x;
    }
    else{
        return gcd_body( m, x );
    }
}
