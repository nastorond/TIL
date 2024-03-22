#include <iostream>
#include <queue>
#include <tuple>
#define MAX_LEN 1501

using namespace std;

int n, m, x, y;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int map[MAX_LEN][MAX_LEN];
int visited[MAX_LEN][MAX_LEN];

int dijkstra() {
    priority_queue<tuple<int, int, int>> pq;
    pq.push(make_tuple(0, x, y));
    visited[x][y] = 0;
    while (!pq.empty()) {
        x = get<1>(pq.top());
        y = get<2>(pq.top());
        int dist = -get<0>(pq.top());
        pq.pop();
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0<=nx && nx<n && 0<=ny && ny<m) {
                if (map[nx][ny] == 2) {
                    return visited[x][y];
                } else if (map[nx][ny] == 1 && dist + 1 < visited[nx][ny]) {
                    visited[nx][ny] = dist + 1;
                    pq.push(make_tuple(-(dist + 1), nx, ny));
                } else {
                    visited[nx][ny] = min(visited[x][y], visited[nx][ny]);
                    pq.push(make_tuple(dist, nx, ny));
                }
            }
        }
    }
    return 10;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    
    cin >> n >> m;

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
            visited[i][cnt] = 1e9;
            cnt++;
        }
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }

    int res = dijkstra();

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }

    cout << res/2 + res%2 << "\n";

    return 0;
}