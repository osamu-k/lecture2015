#include "gcd.h"

#include <stdio.h>

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
//    printf( "x=%u y=%u\n", x, y );
    unsigned int m = y % x;
    if( m == 0 ){
        return x;
    }
    else{
        return gcd_body( m, x );
    }
}
