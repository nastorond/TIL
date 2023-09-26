#include <iostream>

using namespace std;

int house[16][16];
int n;

int dfs(int y, int x, int j, int i){
    if(x == n-1 && y==n-1) return 1;

    int res = 0;

    if (y == j && x-1 == i){
        if (x+1 < n && house[y][x+1] != 1){
            res += dfs(y, x+1, y, x);
        }
        if (y+1 < n && x+1 < n){
            if(house[y][x+1] != 1 && house[y+1][x+1] != 1 && house[y+1][x] != 1){
                res += dfs(y+1, x+1, y, x);
            }
       }
    }

    if (y == j+1 && x==i){
        if(y+1<n && house[y+1][x] != 1){
            res += dfs(y+1, x, y, x);
        }

        if(y+1<n && x+1<n){
            if(house[y+1][x] != 1 && house[y+1][x+1] != 1 && house[y][x+1] !=1){
                res += dfs(y+1, x+1, y, x);
            }
        }
    }

    if (y==j+1 && x==i+1){
        if (x+1 < n && house[y][x+1] != 1){
            res += dfs(y, x+1, y, x);
        }
        if(y+1<n && house[y+1][x] != 1){
            res += dfs(y+1, x, y, x);
        }
        if(y+1<n && x+1<n){
            if(house[y+1][x] != 1 && house[y+1][x+1] != 1 && house[y][x+1] !=1){
                res += dfs(y+1, x+1, y, x);
            }
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> house[i][j];
        }
    }

    int res;

    res = dfs(0, 1, 0, 0);

    cout << res << "\n";
}
