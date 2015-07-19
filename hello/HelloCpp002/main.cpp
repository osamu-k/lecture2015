#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if( argc > 1 ){
        cout << "Hello " << argv[1] << "!" << endl;
    }
    else{
        cout << "Hello World!" << endl;
    }
    cout << "I'm " << argv[0] << endl;
    return 0;
}

