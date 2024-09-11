// 14502 연구소
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, res=0;
vector<vector<int>> gp;
vector<pair<int, int>> emptySpace, virus;

int bfs () {
    int mv[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> tmpMap = gp;
    int ret = 0;

    queue<pair<int, int>> q;
    for (auto loc : virus) {
        q.push(loc);
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second; q.pop();
        for (int i=0; i<4; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];
            if (nx<0 || nx>=n || ny<0 || ny>=m || tmpMap[nx][ny]==1 || tmpMap[nx][ny]==2) continue;
            tmpMap[nx][ny] = 2;
            q.push(make_pair(nx, ny));
        }
    }

    for (auto v: tmpMap) {
        for (int num : v) {
            if (num == 0) ret++;
        }
    }

    return ret;
}

void dfs (int cur, int cnt, vector<bool>& ck) {
    if (cnt == 3) {
        res = max(res, bfs());
        return ;
    }

    for (int i=cur; i<emptySpace.size(); i++) {
        if (ck[i]) continue;
        ck[i] = true;
        pair<int, int> idx = emptySpace[i];
        gp[idx.first][idx.second] = 1;
        dfs(i, cnt+1, ck);
        gp[idx.first][idx.second] = 0;
        ck[i] = false;
    }
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m;
    gp.resize(n, vector<int>(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> gp[i][j];
            if (gp[i][j] == 0) emptySpace.push_back(make_pair(i, j));
            if (gp[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }
    vector<bool> visit(emptySpace.size(), false);
    dfs(0, 0, visit);

    cout << res << "\n";
    
    return 0;
}