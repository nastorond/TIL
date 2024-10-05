#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 26179

struct golem {
    int loc;
    int dir;
};

vector<vector<int>> fld;
int R, C, cnt=2;
int mv[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void init() {
    cnt=2;
    for (int i=0; i<R-1; i++) {
        for (int j=1; j<C-1; j++) fld[i][j]=0;
    }
}

bool condition1(int x, int y) {
    return (fld[x+2][y] + fld[x+1][y-1] + fld[x+1][y+1]) == 0;
}
bool condition2(int x, int y) {
    return (fld[x-1][y-1] + fld[x][y-2] + fld[x+1][y-2] + fld[x+1][y-1] + fld[x+2][y-1]) == 0;
}
bool condition3(int x, int y) {
    return (fld[x-1][y+1] + fld[x][y+2] + fld[x+1][y+1] + fld[x+1][y+2] + fld[x+2][y+1]) == 0;
}

void setGolem(golem gol, int x) {
    int y = gol.loc;
    cnt += 2;
    fld[x-1][y] = cnt; fld[x][y] = cnt; fld[x][y-1] = cnt;
    fld[x][y+1] = cnt; fld[x+1][y] = cnt;

    // 출구는 홀수로 표기
    switch (gol.dir) {
        case 0: // 북
            fld[x-1][y] = cnt+1;
            break;
        case 1: // 동
            fld[x][y+1] = cnt+1;
            break;
        case 2: // 남
            fld[x+1][y] = cnt+1;
            break;
        case 3: // 서
            fld[x][y-1] = cnt+1;
            break;
    }
    return ;
}

int bfs(int x, int y) {
    int res = 0;
    queue<pair<int, int>> q;
    vector<vector<bool>> visit(R, vector<bool>(C, false));
    q.push(make_pair(x, y)); visit[x][y] = true;
    
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second; q.pop();
        for (int i=0; i<4; i++) {
            int dx = x + mv[i][0];
            int dy = y + mv[i][1];
            // if (dx < 1 || dx >= R || dy < 1 || dy >= C) continue;
            if (fld[dx][dy] < 4 || visit[dx][dy]) continue;

            // 출구일 경우 골렘의 몸 어디로든 이동 가능
            if (fld[x][y]%2 == 1) {
                visit[dx][dy] = true;
                q.push(make_pair(dx, dy));
                res = max(res, dx);
            }
            else if (fld[x][y] == fld[dx][dy] || fld[x][y] + 1 == fld[dx][dy]) {
                visit[dx][dy] = true;
                q.push(make_pair(dx, dy));
                res = max(res, dx);
            }
        }
    }
    return res;
}

int simulation(golem gol) {
    // moving
    int x=1, y=gol.loc;
    while (true) {
        if (condition1(x, y)) {
            x += 1;
        }
        else if (condition2(x, y)) {
            x += 1;
            y += -1;
            gol.dir = gol.dir - 1 < 0 ? 3 : gol.dir-1;
        }
        else if (condition3(x, y)) {
            x += 1;
            y += 1;
            gol.dir = gol.dir + 1 > 3 ? 0 : gol.dir+1;
        }
        else break;
    }
    if (x < 4) {
        init();
        return 0;
    }
    gol.loc = y;
    setGolem(gol, x);

    return bfs(x, gol.loc) - 2;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int K, ret=0;
    vector<golem> golems;

    cin >> R >> C >> K;
    R += 4; C += 2;
    fld.resize(R, vector<int>(C, 1));
    init();

    for (int i=0; i<K; i++) {
        golem gol;
        cin >> gol.loc >> gol.dir;
        golems.push_back(gol);
    }

    for (golem g : golems) {
        ret += simulation(g);
        // for (auto v: fld) {
        //     for (int num : v) cout << num << " ";
        //     cout << "\n";
        // }
        // cout << ret << "\n";
    }

    cout << ret << "\n";
    return 0;
}