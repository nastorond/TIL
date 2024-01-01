#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#define INF 1e9

using namespace std;

int n, m;
int visited[101][101];
int maps[101][101];

void dijkstra(){
    priority_queue<tuple<int, int, int>> pq;
    int dist, x, y, nx, ny;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    pq.push(make_tuple(0, 0, 0));
    visited[0][0] = 0;

    while (!pq.empty()) {
        tie(dist, x, y) = pq.top();
        pq.pop();
        dist = -dist;

        if (visited[x][y] < dist) continue;

        for (int i=0; i<4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (0<=nx && nx<n && 0<=ny && ny<m) {
                if (visited[nx][ny] > (dist + maps[nx][ny])) {
                    visited[nx][ny] = dist + maps[nx][ny];
                    pq.push(make_tuple(-visited[nx][ny], nx, ny));
                }
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string str_inp;

    cin >> m >> n;

    int cnt;
    for (int i=0; i<n; i++) {
        cin >> str_inp;
        cnt=0;
        for (char c:str_inp){
            maps[i][cnt] = c-48;
            visited[i][cnt] = INF;
            cnt++;
        }
    }

    dijkstra();

    cout << visited[n-1][m-1] << "\n";

    return 0;
}