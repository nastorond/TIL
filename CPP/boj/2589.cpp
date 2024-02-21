// 2589 보물섬 
// 다익스트라로 구현해야 할듯함
#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#include <string.h>
#define endl "\n"
#define MAX_SIZE 51 // MAX SIZE of map

using namespace std;

int field[MAX_SIZE][MAX_SIZE];
int L, W; // input valuable
int res = 0;  // result
int dx[] = {1, 0, -1, 0}; // list for searching array
int dy[] = {0, 1, 0, -1};

void bfs(int x, int y) {
    int visited[L][W];
    for (int i=0; i<L; i++) {
        for (int j=0; j<W; j++) {
            visited[i][j] = 1e9;
            // cout << visited[i][j] << " ";
        }
        // cout << endl;
    }
    // memset(visited, 63, sizeof(visited)); // init to false 63 == max value in memset
    visited[x][y] = 0;
    

    priority_queue<tuple<int, int, int>> pq; // make tuple for checking distance
    int record = 0; // recording distance, init 0

    pq.push(make_tuple(record, x, y));

    while(!pq.empty()) {
        x = get<1>(pq.top());
        y = get<2>(pq.top());
        int distance = -get<0>(pq.top());
        pq.pop();
        // cout << distance << " "; // check cur distance

        for (int i=0; i<4; i++) { // searching 4 dirs
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0<=nx && nx<L && 0<=ny && ny<W && field[nx][ny] == 1 && visited[nx][ny] >= 1e9) {
                if (visited[nx][ny] > distance + 1) {
                    visited[nx][ny] = distance + 1;
                    pq.push(make_tuple(-(distance + 1), nx, ny));
                    record = max(record, distance + 1);
                }
            }
        }
    }

    // cout << endl;

    res = max(record, res); // compare record & now res value
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string mp_line; // input valuable for map's each line

    cin >> L >> W;

    for (int i=0; i<L; i++) {
        cin >> mp_line;
        int cnt = 0;
        for (char c: mp_line) {
            field[i][cnt] = c - 75; // L's Ascii == 76
            cnt++;
        }
    }

    int cnt = 0;
    for (int i=0; i<L; i++) {
        for (int j=0; j<W; j++) {
            // cout << cnt << " ";
            if (field[i][j] == 1) {
                bfs(i, j);
            }
        }
    }

    cout << res << endl;

    return 0;
}
