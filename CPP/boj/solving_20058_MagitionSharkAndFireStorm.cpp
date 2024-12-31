/*
N, Q
2^(N+2) 크기 격자판 최대 64*64
Q limit 1000
L rotate array size 2^L 기준 모든 격자 회전

padding 줘서 boundary condition 체크 안해도 되게 64 * 64니까 별로 안큼
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> icePlate;
int N, Q, ret=0, maxSize=0;

void dfs (int x, int y, int tmpSize, int tmpCnt) {

}

void melting () {

}

void rotateArray90Clockwise (int rn) {

}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int L, boundarySize;
    cin >> N >> Q;
    boundarySize = pow(2, N);

    icePlate.resize(boundarySize+2, vector<int>(boundarySize+2, 0));

    for (int i=1; i<boundarySize+1; i++) {
        for (int j=1; j<boundarySize+1; j++) {
            cin >> icePlate[i][j];
        }
    }

    while (Q--) {
        cin >> L;

        if (L != 0) {

        }



    }

    cout << ret << "\n";

    return 0;
}