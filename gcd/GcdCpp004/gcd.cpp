#include "gcd.h"
#include <iostream>
using namespace std;

void print_log( unsigned int x, unsigned int y )
{
    cout << "type=unsigned int x=" << x << " y=" << y << endl;
}

void print_log( int x, int y )
{
    cout << "type=int x=" << x << " y=" << y << endl;
}

void print_log( unsigned long x, unsigned long y )
{
    cout << "type=unsigned long x=" << x << " y=" << y << endl;
}

void print_log( long x, long y )
{
    cout << "type=long x=" << x << " y=" << y << endl;
}

