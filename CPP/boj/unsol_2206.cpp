#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define MAX_LEN 1020

using namespace std;

int n, m, maps[MAX_LEN][MAX_LEN];
vector<pair<int, int>> walls;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int bfs() {
    int visited[n][m];
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == n && y == m) {
            return visited[x][y];
        }
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0<=nx && nx<n && 0<=ny && ny<m) {
                if (visited[nx][ny]==0 && maps[nx][ny] == 0) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return 1e9;
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string tmp;
        int cnt = 0;

        cin >> tmp;

        for (char j:tmp) {
            maps[i][cnt] = (int)j;
            if(j=='1') walls.push_back(make_pair(i, cnt));
            cnt++; 
        }
    }

    int res = bfs();

    for (auto it: walls) {
        maps[it.first][it.second] = 1;
        res = min(res, bfs());
        maps[it.first][it.second] = 0;
    }

    if (res >= 1e9) cout << -1 << "\n";
    else cout << res << "\n";

    return 0;
}