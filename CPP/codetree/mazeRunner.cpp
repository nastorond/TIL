#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <tuple>

using namespace std;

struct runnerInfo {
    int r, c;
    bool isEscape;

    runnerInfo() : r(0), c(0), isEscape(false) {}
};  

vector<vector<int>> maze;
unordered_map<int, runnerInfo> runners;
int N, ret = 0;
int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pair<int, int> mazeExit;

bool checkBoundary(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= N;
}

int calDistance (int x, int y, int r, int c) {
    return abs(x - r) + abs(y - c);
}

bool isInBoundary (int x, int y, int sx, int sy, int len) {
    return sx <= x && x < sx+len && sy <= y && y < sy+len;
}

void rotate90Clockwise(int len, int x, int y) {
    vector<vector<int>> tmp = maze;

    for (int i=0; i<len; i++) {
        for (int j=0; j<len; j++) {
            tmp[x+j][y+len-i-1] = maze[x+i][y+j];
            if (tmp[x+j][y+len-i-1] > 0) tmp[x+j][y+len-i-1]--;
        }
    }
    
    for (auto p: runners) {

        if (!p.second.isEscape && isInBoundary(p.second.r, p.second.c, x, y, len)) {      
            int ox = p.second.r - x, oy = p.second.c - y;
            int i = oy + x;
            int j = len - ox - 1 + y;

            runners[p.first].r = i;
            runners[p.first].c = j;
        }
    }

    int ox = mazeExit.first - x, oy = mazeExit.second - y;

    int i = oy + x;
    int j = len - ox - 1 + y;

    mazeExit.first = i;
    mazeExit.second = j;

    cout << "rotateInfo : " << len << " " << x << " " << y << "\n";
    cout << "mazeExit info : " << mazeExit.first << " " << mazeExit.second << "\n";
    for (auto p : runners) {
        if (p.second.isEscape) continue;
        cout << "runners Info : " << p.second.r << " " << p.second.c << "\n";
    }
    cout << "\n";
    for (auto v: tmp) {
        for (int num : v) cout << num << " ";
        cout << "\n";
    }
    cout << "\n";
    maze = tmp;
}

tuple<int, int, int> findSubArryForRotate() {

    for (int len=2; len<=N; len++) {
        for (int i=0; i<N-len+1; i++) {
            for (int j=0; j<N-len+1; j++) {
                if (!isInBoundary(mazeExit.first, mazeExit.second, i, j, len)) continue;

                for (auto p: runners) {
                    if (p.second.isEscape) continue;
                    if (isInBoundary(p.second.r, p.second.c, i, j, len)) {
                        return make_tuple(len, i, j);
                    }
                }
            }
        }
    }
    
    return make_tuple(0, 0, 0);
}

void runnerMoving() {
    cout << "after running" << "\n";

    for (auto p: runners) {
        if (p.second.isEscape) continue;
        pair<int, int> res;

        int x = p.second.r;
        int y = p.second.c;
        res.first = calDistance(x, y, mazeExit.first, mazeExit.second);
        res.second = 5;

        for (int i=0; i<4; i++) {
            int dx = x + mv[i][0];
            int dy = y + mv[i][1];
            if (checkBoundary(dx, dy) || maze[dx][dy] > 0) continue;
            int dist = calDistance(dx, dy, mazeExit.first, mazeExit.second);
            if (res.first > dist) {
                res.first = dist;
                res.second = i;
            }
        }

        if (res.second == 5) continue;

        runners[p.first].r += mv[res.second][0];
        runners[p.first].c += mv[res.second][1];
        ret++;
        if (runners[p.first].r == mazeExit.first && runners[p.first].c == mazeExit.second)
            runners[p.first].isEscape = true;
        
        cout << runners[p.first].r << " " <<runners[p.first].c << " " << res.second << "\n";
    }
    cout << " \n";
    return ;
}

bool rotateMaze() {
    tuple<int, int, int> tp;
    tp = findSubArryForRotate();

    if (!get<0>(tp)) return false;

    rotate90Clockwise(get<0>(tp), get<1>(tp), get<2>(tp));

    return true;
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int M, K, r, c;
    cin >> N >> M >> K;
    maze.resize(N, vector<int>(N, 0));

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> maze[i][j];
        }
    }
    
    for (int i=1; i<=M; i++) {
        runnerInfo tmp;
        cin >> tmp.r >> tmp.c;
        tmp.r--;
        tmp.c--;
        runners[i] = tmp;
    }
    cin >> mazeExit.first >> mazeExit.second;
    mazeExit.first--;
    mazeExit.second--;

    for (int i=0; i<K; i++) {
        runnerMoving();
        if (!rotateMaze()) break;
    }

    cout << ret << "\n";
    cout << mazeExit.first << " " << mazeExit.second << "\n";

    return 0;   
}