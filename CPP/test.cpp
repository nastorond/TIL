#include <iostream>
#define endl "\n"

using namespace std;

int main () {

    int cache[10][10] = {};

    int &a = cache[0][0];
    int b = cache[0][0];
    int *c = &a;
    int &d = *c;

    cache[0][0] = 1;

    cout << "a" << " " << a << " size " << sizeof(a) << endl;
    cout << "b" << " " << b << " size " << sizeof(b) << endl;
    cout << "c" << " " << c << " size " << sizeof(c) << endl;
    cout << "d" << " " << d << " size " << sizeof(d) << endl;

    return 0;
}