/*
Gold 3

Map 에서 0은 이동할 수 있는 곳. 1은 이동할 수 없는 벽.
0,0 에서부터 N, M 까지 최단거리 이동
1회까지 벽을 부술 수 있음.

Q 기반의 BFS 탐색하며 최단거리 알고리즘

1. Map의 인자를 두 개 사용.
- Map의 각 좌표당 데이터를 두개씩 할당하여, 사용
    - 두번째 도달까지 점검하는 알고리즘.
    - 원래의 BFS 알고리즘은 Q 기반으로 이동하는 곳의 좌표를 Q에 넣고 해당 위치까지의 거리를 Field에 기록하는 형태
    - 해당 위치에 이전에 벽을 부쉈는지 체크하는 Bool을 하나 추가.
        - 예외 케이스가 있을 듯.
        - 벽을 부수지 않고 해당 좌표에 도달하는 케이스가 최소인지, 벽을 부수고 해당 좌표에 도달하는 케이스가 최소인지 구별 불가.

2. Q에 좌표를 넣을 떼 이전에 벽을 부수고 이동했는지 기록.
- Q를 구성할 때 3개의 데이터를 넣을 수 있게한다
    - int, int, bool 로 구성하여 현재 위치와 벽 부순 여부 저장
- 특정 위치에 도달했을 때, 벽을 부수지 않고 도달한 케이스를 우선순위로 하여 저장하면 될듯
    - 같은 가중치로 특정 위치에 도달했을 경우, 벽을 부수지 않고 도착한 케이스를 우선순위로.
        - 그러려면 좌표 x, y, 벽뿌여부 뿐만 아니라, 현재까지 도달하는데 걸린 거리 dist도 기록이 필요해보임.
        - 기존의 Visited 배열에 저장되어 있는 것은 가중치만 있기 때문.
            - vi[x][y] = vi[x-1][y-1] + 1 으로 하는 것이 아닌.
            - vi[x][y] = preDist + 1 이런식으로 가야할듯.
    - vi는 1e9 정도로 초기화 화면 될듯.
*/

// 벽 부수고 이동하기 
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
                    if (visited[x][y][1] == 1) visited[nx][ny][1] = 1;
                    visited[nx][ny][0] = visited[x][y][0] + 1;
                    q.push(make_pair(nx, ny));
                } else if (visited[x][y][1] == 0 && maps[nx][ny] == 1) {
                    visited[nx][ny][0] = visited[x][y][0] + 1;
                    visited[nx][ny][1] = 1;
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
            maps[i][cnt] = j-'0';
            cnt++;
        }
    }


    int res = bfs();

    if (res >= 1e9) cout << -1 << "\n";
    else cout << res << "\n";

    return 0;
}