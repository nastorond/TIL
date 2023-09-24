#include <iostream>

using namespace std;

int house[16][16];
int res = 0;

void dfs(int i, int j, int x, int y, int n, bool flg){
    if(x==n-1 && y==n-1){
        res++;
        return ;
    }
    if(i >= n || j >= n || x >= n || y >= n) return ;
    if(house[i][j] == 1 || house[x][y]) return ;
    if(flg == true){
        if (house[x-1][y] == 1 || house[x][y-1] == 1) return ;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> house[i][j];
        }
    }

    dfs(0, 0, 0, 1, n, false);

    cout << res << "\n";
}
