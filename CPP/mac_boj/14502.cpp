// 연구소
#include <iostream>
#define MAX_VAL 9

using namespace std;

int n, m;
int gp[MAX_VAL][MAX_VAL];

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> gp[i][j];
        }
    }
    
    return 0;
}