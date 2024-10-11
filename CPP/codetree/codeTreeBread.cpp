#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct person {
    int x, y, gx, gy;
    bool isArrive;
    
    person() : x(0), y(0), gx(0), gy(0), isArrive(false) {}
};

int n, m, t=1;
int mv[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
vector<vector<int>> fld;
vector<person> pInfo;

void findBaseCamp() {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    pair<int, int> res = make_pair((n)*100+n, n*n);

    visited[pInfo[t].gx][pInfo[t].gy] = true;
    q.push(make_pair(pInfo[t].gx*100+pInfo[t].gy, 0));

    while (!q.empty()) {
        int x = q.front().first/100;
        int y = q.front().first%100;
        int dist = q.front().second; q.pop();

        for (int dir=0; dir<4; dir++) {
            int dx = x + mv[dir][0];
            int dy = y + mv[dir][1];
            
            if (dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
            if (fld[dx][dy] > 1 || visited[dx][dy]) continue;
            
            // 베이스캠프를 찾았을 경우
            if (fld[dx][dy] == 1) {
                // 거리가 더 짧으면 바꿈
                if (dist < res.second) {
                    res = make_pair(dx*100+dy, dist);
                }
                // 같은 거리에 있으면 우선순위에 따라 교체
                else if (dist == res.second) {
                    if (res.first/100 > dx) res = make_pair(dx*100+dy, dist);
                    else if (res.first/100 == dx && res.first%100 > dy) res = make_pair(dx*100+dy, dist);
                }
            }
            visited[dx][dy] = true; 
            q.push(make_pair(dx*100+dy, dist+1));

        }
    }

    pInfo[t].x = res.first/100;
    pInfo[t].y = res.first%100;
    fld[res.first/100][res.first%100] = 2;
    return ;
}

bool setWall () {
    int cnt = 0;
    for (int i=1; i<pInfo.size(); i++) {
        if (t <= i) continue;
        if (pInfo[i].isArrive) {
            cnt++;
            continue;
        }

        if (pInfo[i].x == pInfo[i].gx && pInfo[i].y == pInfo[i].gy) {
            cnt++;
            pInfo[i].isArrive = true;
            fld[pInfo[i].x][pInfo[i].y] = 2;
        }
    }

    if (cnt == m) return true;
    return false;
}

void movingPeople (int num) {
    if (num > m || num > t) return;

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    // dx,dy, dir
    q.push(make_pair(pInfo[num].x*100+pInfo[num].y, 5));

    visited[pInfo[num].x][pInfo[num].y] = true;

    while (!q.empty()) {
        int x = q.front().first/100;
        int y = q.front().first%100;
        int dir = q.front().second; q.pop();

        for (int i=0; i<4; i++) {
            int dx = x + mv[i][0];
            int dy = y + mv[i][1];

            if (dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
            if (fld[dx][dy] == 2 || visited[dx][dy]) continue;

            // 도착하면
            if (dx == pInfo[num].gx && dy == pInfo[num].gy) {

                dir = dir > 3 ? i : dir;

                pInfo[num].x += mv[dir][0];
                pInfo[num].y += mv[dir][1];
                return ;
            }
            q.push(make_pair(dx*100+dy, dir > 3 ? i : dir));
            visited[dx][dy] = true;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m;

    fld.resize(n, vector<int>(n, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> fld[i][j];
        }
    }

    // 1번 부터 1번 사람
    person tmp;
    pInfo.push_back(tmp);

    for (int i=0; i<m; i++) {
        cin >> tmp.gx >> tmp.gy;
        tmp.gx--;
        tmp.gy--;
        pInfo.push_back(tmp);
    }

    findBaseCamp(); t++;

    while (true) {
        for (int i=1; i<=m; i++) {
            if (pInfo[i].isArrive) continue;
            movingPeople(i);
        } 

        if (setWall()) break;

        if (t <= m) {
            findBaseCamp();
        }
        t++;
    }

    cout << t << "\n";

    return 0;
}