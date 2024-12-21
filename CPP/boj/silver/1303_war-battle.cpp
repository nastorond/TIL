// 1303 전쟁 - 전투
// 그래프 탐색 문제
#include <iostream>
#include <string>
#include <queue>
#define MAX_VALUE 103
#define endl "\n"

using namespace std;

int N, M;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int field[MAX_VALUE][MAX_VALUE];
bool visited[MAX_VALUE][MAX_VALUE] = {};

int bfs(int x, int y, int character) {
    int tmp_res = 1;
    queue<pair<int, int>> q;

    visited[x][y] = true;
    q.push(make_pair(x, y));

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0<=nx && nx<N && 0<=ny && ny<M && !visited[nx][ny]) {
                if (field[nx][ny] == character) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                    tmp_res++;
                }
            }
        }
    }

    // cout << tmp_res * tmp_res << "\n";

    return tmp_res*tmp_res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string input_value;
    int res1=0, res2=0;

    cin >> M >> N;

    for (int i=0; i<N; i++) { // input soldier's distribution
        cin >> input_value;
        int cnt = 0;
        for (char c: input_value) {
            field[i][cnt] = c - 65; // A's ASCII 65 B is will be 1
            // cout << field[i][cnt] << " ";
            cnt++;
        }
        // cout << endl;
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (!visited[i][j]) {
                if (field[i][j] == 1) res1 += bfs(i, j, field[i][j]);
                else res2 += bfs(i, j, field[i][j]);
            }
        }
    }

    cout << res2 << " " << res1 << endl;

    return 0;
}