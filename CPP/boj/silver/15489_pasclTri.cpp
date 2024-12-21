#include <iostream>

using namespace std;

int pascalTri[32][32] = {0, };
int R, C, W;

void fillTri() {
    pascalTri[0][0] = 1;
    for (int i=0; i<32; i++) pascalTri[i][0] = 1;

    for (int i=1; i<31; i++) {
        for (int j=1;j<=i; j++) {
            pascalTri[i][j] = pascalTri[i-1][j-1] + pascalTri[i-1][j];
        }
    }
    return ;
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> R >> C >> W;
    R--; C--;

    fillTri();

    int ret = 0, cnt=1;
    for (int i=R; i<=R+W; i++) {
        for (int j=C; j<C+cnt; j++) {
            // cout << i << " " << j << " " << pascalTri[i][j] << "\n"; 
            ret += pascalTri[i][j];
        }
        cnt++;
        if (cnt > W) {
            cout << ret << "\n";
            return 0;
        }
    }

    return 0;
}