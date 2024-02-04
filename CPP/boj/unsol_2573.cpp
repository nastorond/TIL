// 2573 빙산
#include <iostream>
#include <queue>
#define endl "\n"
#define MAX_VAL 303

using namespace std;

int ocean[MAX_VAL][MAX_VAL] = {};
int visited[MAX_VAL][MAX_VAL] = {};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m, cnt, ans;

void graph_travel(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0<=nx && nx<n && 0<=ny && ny<m && ocean[nx][ny] > 0 && visited[nx][ny] == cnt) {
                // 주변이 얼음일 경우 체크해야함
                // 주변의 맞닿는 바다의 면적에 따라 얼음이 녹음 <-- 이거 체크 안해서 틀림
                int numOcean = 0;
                for (int j=0; j<4; j++) {
                    numOcean += ocean[nx+dx[j]][ny+dy[j]] == 0 ? 1 : 0;
                }
                cout << numOcean << endl;
                ocean[nx][ny]-= numOcean;
                visited[nx][ny]++;
                q.push(make_pair(nx, ny));
            }
        }
    }
    return ;
}

void solution () {
    while (true) {
        // 전부 0일 경우 확인용
        bool flg = true;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (ocean[i][j] > 0 && visited[i][j] == cnt) {
                    graph_travel(i, j);
                    flg = false;
                } else if (ocean[i][j] > 0 && visited[i][j] < cnt) {
                    ans = cnt;
                    return ;
                }
            }
        }
        cnt++;
        if (flg) {
            ans = 0;
            return ;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> ocean[i][j];
        }
    }

    cnt = 0;

    solution();

    // check
    // cout << endl;
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         cout << ocean[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << ans << endl;

    return 0;
}