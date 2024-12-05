#include <iostream>
#include <vector>

using namespace std;

struct Shark {
    int r, c, size, dir, speed;
    bool isLive;
};

vector<Shark> skInfo;
vector<vector<int>> fld;
int res = 0, n, m, skNum;
// north, south, east, west
int mv[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void fishingShark (int sec) {
    for (int i=1; i<n+1; i++) {
        if (fld[i][sec] != 0) {
            skInfo[fld[i][sec]].isLive = false;
            res += skInfo[fld[i][sec]].size;
            fld[i][sec] = 0;
            return ;
        }
    }
}

bool boundaryCondition(int x, int y) {
    return x < 1 || x > n || y < 1 || y > m;
}

int setDir (int dir) {
    switch (dir)
    {
    case 0:
        dir = 1;
        break;
    case 1:
        dir = 0;
        break;
    case 2:
        dir = 3;
        break;
    case 3:
        dir = 2;
        break;
    }
    return dir;
}

void moving (int num) {
    int cnt = skInfo[num].speed;
    int x = skInfo[num].r, y = skInfo[num].c, dir = skInfo[num].dir;
    if (fld[x][y] == num) fld[x][y] = 0;

    while (cnt--) {
        int nx = x + mv[dir][0];
        int ny = y + mv[dir][1];
        if (!boundaryCondition(nx, ny)) {
            x = nx; y = ny;
        }
        else {
            dir = setDir(dir);
            x += mv[dir][0];
            y += mv[dir][1]; 
        }
    }

    // if (dir < 2 && cnt > n) cnt -= n-x;
    // else if (dir > 1 && cnt > m) cnt -= m-y;
    
    // int dis = cnt%m;
    // bool leftRight = (cnt/m-1)%2 ? true : false;
    // if (dir < 2) {
    //     dis = cnt%n;
    //     leftRight = (cnt/n-1)%2 ? true : false;
    // }

    // if (!leftRight) {
    //     dir = setDir(dir);
    // }

    // if (dir < 2) {
    //     if (dir == 0) {
    //         x = n - dis;
    //     }
    //     else {
    //         x = dis + 1;
    //     }
    // }
    // else {
    //     if (dir == 2) {
    //         y = 1 + dis;
    //     }
    //     else {
    //         y = m - dis;
    //     }
    // }

    if (fld[x][y] > 0 && fld[x][y] < num) {
        if (skInfo[fld[x][y]].size > skInfo[num].size) {
            skInfo[num].isLive = false; 
            return ;
        } else {
            skInfo[fld[x][y]].isLive = false;
        }
    }
    
    fld[x][y] = num;
    skInfo[num].r = x; skInfo[num].c = y;
    skInfo[num].dir = dir;
}

void skMoving () {
    for (int i=1; i<skNum+1; i++) {
        if (!skInfo[i].isLive) continue;
        else moving(i);
    }
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    Shark sk;
    cin >> n >> m >> skNum;

    fld.resize(n+1, vector<int>(m+1, 0));

    sk.isLive = true;
    skInfo.push_back(sk);
    for (int i=0; i<skNum; i++) {
        cin >> sk.r >> sk.c >> sk.speed >> sk.dir >> sk.size;
        sk.dir--;
        if (sk.dir > 1) {
            sk.speed %= (m-1)*2;
        }
        else {
            sk.speed %= (n-1)*2;
        }
        fld[sk.r][sk.c] = i+1;
        skInfo.push_back(sk);
    }

    for (int i=1; i<=m; i++) {
        fishingShark(i);
        skMoving();

    }

    cout << res << "\n";

    return 0;
}