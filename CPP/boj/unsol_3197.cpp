#include <iostream>
#include <queue>
#include <vector>
#define MAX_LEN 1501

using namespace std;

int n, m, x, y;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int map[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
bool flg = false;

queue<pair<int, int>> bfs(queue<pair<int, int>> &tmp) {
    queue<pair<int, int>> res;

    while (!tmp.empty()) {
        x = tmp.front().first;
        y = tmp.front().second;
        tmp.pop();

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0<=nx && nx<n && 0<=ny && ny<m && !visited[nx][ny]) {
                switch (map[nx][ny])
                {
                case 0:
                    tmp.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                    break;
                case 1:
                    res.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                    break;
                case 2:
                    flg=true;
                    return res;
                }
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    
    cin >> n >> m;

    vector<pair<int, int>> start_point;
    string inp;
    char condition1 = '.';
    char condition2 = 'X';
    char condition3 = 'L';
    for (int i=0; i<n; i++){
        cin >> inp;
        int cnt=0;
        for (char c: inp) {
            if (c == condition1) {
                map[i][cnt] = 0;
            } else if (c == condition2) {
                map[i][cnt] = 1;
            } else if (c == condition3) {
                map[i][cnt] = 2;
                x = i;
                y = cnt;
            }
            visited[i][cnt] = false;
            cnt++;
        }
    }

    int cnt=0;
    queue<pair<int,int>> tmp;
    visited[x][y] = true;
    tmp.push(make_pair(x, y));

    while(true) {
        tmp = bfs(tmp);
        if (!flg) cnt++;
        else break;
    }

    cout << cnt/2 + cnt%2 << "\n";

    return 0;
}