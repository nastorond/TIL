#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

queue<int> extraNum;
vector<vector<int>> ruin(5, vector<int>(5, 0));
int mv[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void rotate90 (int x, int y, vector<vector<int>>& tmpRuin) {
    tmpRuin[x-1][y-1] = ruin[x+1][y-1];
    tmpRuin[x-1][y] = ruin[x][y-1];
    tmpRuin[x-1][y+1] = ruin[x-1][y-1];
    tmpRuin[x][y-1] = ruin[x+1][y];
    tmpRuin[x][y+1] = ruin[x-1][y];
    tmpRuin[x+1][y-1] = ruin[x+1][y+1];
    tmpRuin[x+1][y] = ruin[x][y+1];
    tmpRuin[x+1][y+1] = ruin[x-1][y+1];

    return ;
}

void rotate180 (int x, int y, vector<vector<int>>& tmpRuin) {
    tmpRuin[x-1][y-1] = ruin[x+1][y+1];
    tmpRuin[x-1][y] = ruin[x+1][y];
    tmpRuin[x-1][y+1] = ruin[x+1][y-1];
    tmpRuin[x][y-1] = ruin[x][y+1];
    tmpRuin[x][y+1] = ruin[x][y-1];
    tmpRuin[x+1][y-1] = ruin[x-1][y+1];
    tmpRuin[x+1][y] = ruin[x-1][y];
    tmpRuin[x+1][y+1] = ruin[x-1][y-1];

    return ;
}

void rotate270 (int x, int y, vector<vector<int>>& tmpRuin) {
    tmpRuin[x-1][y-1] = ruin[x-1][y+1];
    tmpRuin[x-1][y] = ruin[x][y+1];
    tmpRuin[x-1][y+1] = ruin[x+1][y+1];
    tmpRuin[x][y-1] = ruin[x-1][y];
    tmpRuin[x][y+1] = ruin[x+1][y];
    tmpRuin[x+1][y-1] = ruin[x-1][y-1];
    tmpRuin[x+1][y] = ruin[x][y-1];
    tmpRuin[x+1][y+1] = ruin[x+1][y-1];

    return ;
}

int bfs(int x, int y, int value, vector<vector<int>>& tmpRuin, vector<vector<bool>>& visit) {
    queue<pair<int, int>> q;
    int cnt = 1;

    q.push(make_pair(x, y));
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second; q.pop();
        for (int i=0; i<4; i++) {
            int dx = x + mv[i][0];
            int dy = y + mv[i][1];
            if (dx < 0 || dx > 4 || dy < 0 || dy > 4) continue;
            if (tmpRuin[dx][dy] != value || visit[dx][dy]) continue;
            q.push(make_pair(dx, dy));
            cnt++; visit[dx][dy] = true;
        }
    }

    if (cnt < 3) return 0;

    return cnt;
}

int exploration(vector<vector<int>>& tmpRuin) {
    vector<vector<bool>> visit(5, vector<bool>(5, false));
    int res = 0;
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (visit[i][j] || tmpRuin[i][j] < 1) continue;
            visit[i][j] = true;
            res += bfs(i, j, tmpRuin[i][j], tmpRuin, visit);
        }
    }
    return res;
}

void step1 () {
    // value, rotateDegree, y, x
    priority_queue<tuple<int, int, int, int>> pq;
    vector<vector<int>> tmpRuin = ruin;
    int tmpValue;

    for (int i=1; i<4; i++) {
        for (int j=1; j<4; j++) {
            for (int k = 1; k<4; k++) {
                switch (k) {
                    case 1:
                        rotate90(i, j, tmpRuin);
                        break;
                    case 2:
                        rotate180(i, j, tmpRuin);
                        break;
                    case 3:
                        rotate270(i, j, tmpRuin);
                        break;
                }
                tmpValue = exploration(tmpRuin);
                pq.push(make_tuple(tmpValue, -k*90, -j, -i));
                tmpRuin = ruin;
            }
        }
    }

    int x = -get<3>(pq.top());
    int y = -get<2>(pq.top());
    switch (get<1>(pq.top())) {
        case -90:
            rotate90(x, y, tmpRuin);
            break;
        case -180:
            rotate180(x, y, tmpRuin);
            break;
        case -270:
            rotate270(x, y, tmpRuin);
            break;
    }
    ruin = tmpRuin;

    return ;
}

void dfs (int x, int y, int value, vector<vector<bool>>& visit, vector<pair<int, int>>& loc) {
    visit[x][y] = true;
    loc.push_back(make_pair(x, y));

    for (int i=0; i<4; i++) {
        int dx = x + mv[i][0];
        int dy = y + mv[i][1];
        if (dx < 0 || dx > 4 || dy < 0 || dy > 4) continue;
        if (ruin[dx][dy] != value || visit[dx][dy]) continue;

        dfs(dx, dy, value, visit, loc);
    }
}

int getArtifact () {
    vector<vector<bool>> visit(5, vector<bool>(5, false));
    int res = 0;

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (visit[i][j] || ruin[i][j] < 1) continue;

            vector<pair<int, int>> loc;
            dfs(i, j, ruin[i][j], visit, loc);

            if (loc.size() < 3) continue;
            for (auto p : loc) {
                ruin[p.first][p.second] = 0;
            }

            res += loc.size();
        }
    }

    return res;
}

void fillRuin () {
    if (extraNum.empty()) return ;
    for (int j=0; j<5; j++) {
        for (int i=4; i>=0; i--) {
            if (ruin[i][j] > 0) continue;
            ruin[i][j] = extraNum.front(); extraNum.pop();
            if (extraNum.empty()) return ;
        }
    }
    return ;
} 

int step2 () {
    int value = 0;
    value += getArtifact();
    if (value == 0) return 0;

    int cnt = 1;
    while (cnt > 0) {
        fillRuin();
        cnt = getArtifact();
        value += cnt;
    }
    
    return value;
}

int simulation() {
    int res = 0, tmp = 0;

    step1();
    res = step2();

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int tmp, K, M;;

    // input part
    cin >> K >> M;
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin >> ruin[i][j];
        }
    }
    for (int i=0; i<M; i++) {
        cin >> tmp;
        extraNum.push(tmp);
    }

    for (int i=0; i<K; i++) {
        tmp = simulation();
        if (tmp == 0) return 0;
        
        cout << tmp << " ";
    }

    return 0;
}