#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

struct santaInfo {
    int score, x, y, extraStun;
    bool isLive;

    santaInfo () : score(0), x(0), y(0), extraStun(0), isLive(true) {}
};

vector<vector<int>> fld;
int N, C, D;
int mv[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int rudolphMv[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
map<int, santaInfo> santa;
pair<int, int> rudolph;

int manhattanDis (int x, int y, int i, int j) {
    return ((x-i) * (x-i)) + ((y-j) * (y-j));
}

void santaInteraction (int num, int x, int y, int dx, int dy) {
    int otherSanta = fld[x][y];
    fld[x][y] = num;
    santa[num].x = x;
    santa[num].y = y;
    x += dx; y += dy;
    if (x < 0 || x >= N || y < 0 || y >= N) {
        santa[otherSanta].isLive = false;
        return ;
    }
    if (fld[x][y] == 0) {
        fld[x][y] = otherSanta;
        santa[otherSanta].x = x;
        santa[otherSanta].y = y;
        return ;
    }
    santaInteraction(otherSanta, x, y, dx, dy);
}

int findSanta(int x, int y) {
    tuple<int, int, int, int> res;
    res = make_tuple(N*N, 10, 0, 0);

    cout << "\n";
    
    vector<int> tmpV;
    for (int i=0; i<8; i++) {
        int dx = x + rudolphMv[i][0];
        int dy = y + rudolphMv[i][1];
        if (dx < 0 || dx >= N || dy < 0 || dy >= N) tmpV.push_back(0);
        else tmpV.push_back(fld[dx][dy]);
    }
    for (int i : {4, 2, 6, 0, 3, 5, 1, 7}) {
        if (tmpV[i] > 0) return i;
    }

    for (int i=0; i<8; i++) {
        int dx = x + rudolphMv[i][0];
        int dy = y + rudolphMv[i][1];
        if (dx < 0 || dx >= N || dy < 0 || dy >= N) continue;

        for (auto p : santa) {
            if (!p.second.isLive) continue;
            
            int tmp = manhattanDis(dx, dy, p.second.x, p.second.y);
            if (get<0>(res) >= tmp) {
                if (get<0>(res) > tmp) {
                    res = make_tuple(tmp, i, p.second.x, p.second.y);
                }
                else if (get<2>(res) < p.second.x) {
                    res = make_tuple(tmp, i, p.second.x, p.second.y);
                }
                else if (get<2>(res) == p.second.x && get<3>(res) < p.second.y) {
                    res = make_tuple(tmp, i, p.second.x, p.second.y);
                }
            }
        }
    }
    return get<1>(res);
}

void rudolphMovingAndCollision() {
    int dir = findSanta(rudolph.first, rudolph.second);
    int x = rudolph.first + rudolphMv[dir][0];
    int y = rudolph.second + rudolphMv[dir][1];

    fld[rudolph.first][rudolph.second] = 0;

    // 돌진한 방향에 산타가 없는 경우
    if (fld[x][y] == 0) {
        rudolph.first = x;
        rudolph.second = y;
        fld[x][y] = 40;
        return ;
    }

    int num = fld[x][y];
    rudolph.first = x;
    rudolph.second = y;

    fld[x][y] = 40;
    santa[num].score += C;
    santa[num].extraStun = 2;

    x += rudolphMv[dir][0]*C; y += rudolphMv[dir][1]*C;
    if (x < 0 || x >= N || y < 0 || y >= N) {
        santa[num].isLive = false;
        return ;
    }
    if (fld[x][y] == 0) {
        santa[num].x = x;
        santa[num].y = y;
        fld[x][y] = num;
        return ;
    }
    
    santaInteraction(num, x, y, rudolphMv[dir][0], rudolphMv[dir][1]);

    return ;
}

int findRudolph (int x, int y) {
    int tmpDist = manhattanDis(x, y, rudolph.first, rudolph.second);

    pair<int, int> p;
    p.first = tmpDist;
    p.second = 5;
    for (int j=0; j<4; j++) {
        int dx = x + mv[j][0];
        int dy = y + mv[j][1];
        if (dx < 0 || dx >= N || dy < 0 || dy >= N) continue;
        if (fld[dx][dy] < 40 && fld[dx][dy] > 0) continue;

        int dist = manhattanDis(dx, dy, rudolph.first, rudolph.second);

        if (p.first > dist) {
            p.first = dist;
            p.second = j;
        }
    }
    if (p.second == 5) return -1;
    return p.second;
}


void simulation() {
    rudolphMovingAndCollision();

    cout << "\n";
    for (auto v: fld) {
        for (int num : v) cout << num << " ";
        cout << "\n";
    }
    cout << "\n";

    for (auto santaUnit : santa) {
        if (!santaUnit.second.isLive) continue;
        if (santaUnit.second.extraStun > 0) {
            santa[santaUnit.first].extraStun--;
            continue;
        }
        int dir = findRudolph(santaUnit.second.x, santaUnit.second.y);

        if (dir == -1) continue;

        fld[santaUnit.second.x][santaUnit.second.y] = 0;

        int x = santaUnit.second.x + mv[dir][0];
        int y = santaUnit.second.y + mv[dir][1];

        if (fld[x][y] == 0) {
            fld[x][y] = santaUnit.first;
            santa[santaUnit.first].x = x;
            santa[santaUnit.first].y = y;
        } else if (fld[x][y] == 40) {
            santa[santaUnit.first].score += D;
            santa[santaUnit.first].extraStun = 1;
            dir = (dir + 2)%4;
            x += mv[dir][0]*D;
            y += mv[dir][1]*D;
            if (x < 0 || x >= N || y < 0 || y >= N) {
                santa[santaUnit.first].isLive = false;
                continue;
            }
            if (fld[x][y] == 0) {
                santa[santaUnit.first].x = x;
                santa[santaUnit.first].y = y;
                fld[x][y] = santaUnit.first;
            }
            else {
                santaInteraction(santaUnit.first, x, y, mv[dir][0], mv[dir][1]);
            }
        }
    }

    cout << "santa" << "\n";
    for (auto v: fld) {
        for (int num : v) cout << num << " ";
        cout << "\n";
    }
    cout << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int M, P;
    cin >> N >> M >> P >> C >> D;
    cin >> rudolph.first >> rudolph.second;

    fld.resize(N, vector<int>(N, 0));
    rudolph.first--; rudolph.second--;
    fld[rudolph.first][rudolph.second] = 40;

    for (int i=0; i<P; i++) {
        int num;
        santaInfo tmp;
        cin >> num >> tmp.x >> tmp.y;
        tmp.x--; tmp.y--;
        santa[num] = tmp;
        fld[tmp.x][tmp.y] = num;
    }

    cout << "\n";
    for (auto v : fld) {
        for (int num : v) cout << num << " ";
        cout << "\n";
    }
    cout << "\n";

    for (int i=0; i<M; i++) {
        simulation();
        int cnt = P;
        for (int i=1; i<=P; i++) {
            if (!santa[i].isLive) continue;
            santa[i].score++;
            cnt--;
        }
        if (cnt == P) break;
    }
    
    for (auto unit : santa) {
        cout << unit.second.score << " ";
    }

    return 0;
}