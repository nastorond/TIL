#include<iostream>
typedef unsigned long ULONG;
using namespace std;

typedef struct Matrix_2x2{
    ULONG f[2][2];
}Matrix2x2;
Maxtrix2x2 multiply(Matrix2x2 A, Matrix2x2 B){
    Matrix2x2 C;
    C.f[0][0] = A.f[0][0]*B.f[0][0] + A[0][1]*B[1][0];
    C.f[0][1] = A.f[0][0]*B.f[0][1] + A[0][1]*B[1][1];
    C.f[1][0] = A.f[1][0]*B.f[0][0] + A[1][1]*B[1][0];
    C.f[1][1] = A.f[1][0]*B.f[0][1] + A[1][1]*B[1][1];

    return C;
}
Matrix2x2 Matrix_Power(Matrix2x2 A, int n){
    if (n > 1){
        A = Matrix_Power(A, n/2);
        A = multiply(A, A);

        if (n & 1){
            Matrix2x2 F1 = { 1,1,1,0 };
            A = multiply(A, F1);
        }
    }
    return A;
}

int main(){
    int n;
    cin >> n;
    Matrix2x2 F1 = { 1,1,1,0 }
    F1 = Matrix_Power(F1, n);
    cout << F1.f[0][1] << endl;
}