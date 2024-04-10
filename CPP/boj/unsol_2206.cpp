#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define MAX_LEN 1020

using namespace std;

int n, m, maps[MAX_LEN][MAX_LEN], visited[MAX_LEN][MAX_LEN][2];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void init() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            visited[i][j][0] = 0;
            visited[i][j][1] = 0;
        }
    }
}

int bfs() {
    init();

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == n-1 && y == m-1) {
            return visited[x][y][0];
        }
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0<=nx && nx<n && 0<=ny && ny<m && visited[nx][ny][0]==0) {
                if (maps[nx][ny]==0) {
                    visited[nx][ny][0] = visited[x][y][0] + 1;
                    q.push(make_pair(nx, ny));
                } else if (visited[x][y][1] == 0 && maps[nx][ny] == 1) {
                    visited[nx][ny][0] = visited[x][y][0] + 1;
                    visited[nx][ny][1] = 1;
                    q.push(make_pair(nx, ny));
                }
                if (visited[x][y][1] == 1) visited[nx][ny][1] = 1;
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
            maps[i][cnt] = j-'0';
            cnt++;
        }
    }


    int res = bfs();

    if (res >= 1e9) cout << -1 << "\n";
    else cout << res << "\n";

    return 0;
}