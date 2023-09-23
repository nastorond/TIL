#include <iostream>
#include <cstring>

#define n 4
#define r 3

using namespace std;

int pArr[r] = { 0, };
bool check[n+1] = { false, };

void permutation(int depth){
    if (depth == r){
        for(int i=0; i<r; i++){
            cout << pArr[i] << ' ';
        }
        cout << "\n";
        return ;
    }

    for(int i = 1; i<=n; i++){
        if(!check[i]){
            check[i] = true;
            pArr[depth] = i;
            permutation(depth + 1);
            check[i] = false;
        }
    }
}

void combination(int depth, int next){
    if (depth == r){
        for(int i=0; i<r; i++){
            cout << pArr[i] << ' ';
        }
        cout << "\n";
        return ;
    }

    for(int i=next; i<=n; i++){
        pArr[depth] = i;
        combination(depth + 1, i + 1);
    }
}

int main(){
    permutation(0);
    cout << "\n";
    combination(0, 1);
    return 0;
}