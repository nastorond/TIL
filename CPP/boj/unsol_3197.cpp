#include <iostream>
#include <queue>
#include <string>
#define MAX_LEN 1501

using namespace std;

int n, m, x, y;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int map[MAX_LEN][MAX_LEN];
int visited[MAX_LEN][MAX_LEN];

int dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(x, y));
    visited[x][y] = 0;
    while (!pq.empty()) {
        x = pq.top().first;
        y = pq.top().second;
        pq.pop();
        if (map[x][y] == 2) {
            return visited[x][y];
        }
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0<=nx && nx<n && 0<=ny && ny<m) {
                if (map[nx][ny] == 1 && visited[x][y] + 1 < visited[nx][ny]) {
                    visited[nx][ny] += 1;
                }
                pq.push(make_pair(nx, ny));
                visited[nx][ny] = min(visited[x][y], visited[nx][ny]);
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    
    cin >> n >> m;

    string inp;
    for (int i=0; i<n; i++){
        cin >> inp;
        int cnt=0;
        cout << "test" << "\n";
        for (char c: inp) {
            if (c == ".") {
                map[i][cnt] = 0;
            } else if (c == 'X') {
                map[i][cnt] = 1;
            } else if (c == 'L') {
                map[i][cnt] = 2;
                x = i;
                y = cnt;
            } else {
                cout << "check" << "\n";
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