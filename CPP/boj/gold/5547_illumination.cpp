#include <iostream>
#include <queue>
#define MAXW 105

using namespace std;

int fld[MAXW][MAXW] = {0, };
int W, H, ret=0;
int even_dir[6][2] = { {1,-1},{1,0},{-1,-1},{-1,0},{0,-1},{0,1} };
int odd_dir[6][2] = { {1,0},{1,1},{-1,0},{-1,1},{0,-1},{0,1} };

bool boundary_condition (int x, int y) {
    return 0 <= x && x <= H+1 && 0<= y && y<=W+1;
}

void solution () {
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    fld[0][0] = -1;
    
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i=0; i<6; i++) {
            int nx = cur_x + (cur_x%2 == 0 ? even_dir[i][0] : odd_dir[i][0]);
            int ny = cur_y + (cur_x%2 == 0 ? even_dir[i][1] : odd_dir[i][1]);
            if (boundary_condition(nx, ny)) {
                if (fld[nx][ny] == 1) {
                    ret++; continue;
                }
                if (fld[nx][ny] == 0) {
                    q.push(make_pair(nx, ny));
                    fld[nx][ny] = -1;
                }   
            }
        }
    }
    
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> W >> H;
    
    int tmp;
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            cin >> tmp;
            fld[i][j] = tmp;
        }
    }


    solution();
    
    cout << ret << "\n";

    return 0;
}