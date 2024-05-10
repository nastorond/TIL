#include <iostream>
#include <time.h>
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

    time_t statrTime = 0, check1=0, check2=0;

    statrTime=clock();
    for (int i=0; i<100; i++) int arr[100000][2];
    
    check1 = clock() - statrTime;

    statrTime=clock();
    int arr2[2][100000];
    check2=clock() - statrTime;
    cout << check1 << endl;
    cout << check2 << endl;

    return 0;
}