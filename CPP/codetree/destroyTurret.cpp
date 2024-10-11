#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>

using namespace std;

struct Turret {
    int x, y, damage, turn;
};

vector<vector<int>> fld;
vector<vector<int>> turnManage;
vector<vector<bool>> isDamaged;
vector<vector<bool>> visited;
vector<Turret> turrets;

int N, M;
// 우선순위 대로 구성 우, 하, 좌, 상
int mv[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
// 포탄 공격 좌상, 상, 우상, 좌, 우, 좌하, 하, 우하
int throwing[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, 
                        {0, -1},          {0, 1}, 
                        {1, -1}, {1, 0}, {1, 1}};

void init() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            visited[i][j] = false;
            isDamaged[i][j] = false;
        }
    }
}

pair<int, int> calBoundary (int x, int y) {
    x = x < 0 ? N-1 : (x == N ? 0 : x);
    y = y < 0 ? M-1 : (y == M ? 0 : y);
    return make_pair(x, y);
}

bool compare(Turret a, Turret b) {
    if (a.damage != b.damage) return a.damage < b.damage;
    else if (a.turn != b.turn) return a.turn > b.turn;
    else if (a.x + a.y != b.x + b.y) return a.x + a.y > b.x + b.y;
    return a.y > b.y;
}

vector<int> raserAttack(int sx, int sy, int gx, int gy) {
    queue<tuple<int, int, vector<int>>> q;
    vector<int> tmp;
    tmp.push_back(sx*100+sy);
    q.push(make_tuple(sx, sy, tmp));
    visited[sx][sy] = true;
    
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        vector<int> v = get<2>(q.front()); q.pop();
        
        for (int i=0; i<4; i++) {
            pair<int, int> xy = calBoundary(x+mv[i][0], y+mv[i][1]);
            int dx = xy.first, dy = xy.second;

            // 방문한 적 있거나, 공격력이 0 이면 방문하지 않음
            if (visited[dx][dy] || fld[dx][dy] == 0) continue;

            // 목적지에 도착하면 종료
            if (dx == gx && dy == gy) return v;

            visited[dx][dy] = true;
            vector<int> tmpV = v;
            tmpV.push_back(dx*100+dy);
            q.push(make_tuple(dx, dy, tmpV));
        }
    }
    return {};
}

void attack(int atkX, int atkY, int dfnX, int dfnY, int turn) {

    // 공격자 턴 갱신
    turnManage[atkX][atkY] = turn;

    // 공격력 보정
    fld[atkX][atkY] += N+M;
    isDamaged[atkX][atkY] = true;

    vector<int> routes = raserAttack(atkX, atkY, dfnX, dfnY);

    // 레이저 공격이 안될 시, 포탄 공격 시도
    if (routes.size() < 1) {
        routes.push_back(atkX*100 + atkY);

        for (int i=0; i<8; i++) {
            pair<int, int> xy = calBoundary(dfnX+throwing[i][0], dfnY+throwing[i][1]);
            int dx = xy.first, dy = xy.second;

            if (fld[dx][dy] == 0 || (dx == atkX && dy == atkY)) continue;
            routes.push_back(dx*100+dy);
        }
    }

    // 경로나 근처에 있는 터렛 절반의 데미지로 공격
    for (int i=1; i<routes.size(); i++) {
        int x = routes[i]/100;
        int y = routes[i]%100;

        isDamaged[x][y] = true;

        // 0이 이하면 0 으로 통일
        int tmp = fld[x][y] - fld[atkX][atkY]/2;
        fld[x][y] = tmp < 0 ? 0 : tmp;

    }

    // 목표물 공격
    int tmp = fld[dfnX][dfnY] - fld[atkX][atkY];
    fld[dfnX][dfnY] = tmp < 0 ? 0 : tmp;
    isDamaged[dfnX][dfnY] = true;

    return ;
}

vector<int> findAttackerAndDefender() {
    sort(turrets.begin(), turrets.end(), compare);

    Turret atk = turrets[0];
    Turret dfn = turrets[turrets.size() - 1];

    turrets.clear();

    return {atk.x, atk.y, dfn.x, dfn.y};
}

bool fixTurret(int turn) {
    Turret tmp;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (fld[i][j] > 0) {
                tmp.x = i;
                tmp.y = j;
                if (!isDamaged[i][j]) fld[i][j]++;
                tmp.damage = fld[i][j];
                tmp.turn = turnManage[i][j];
                turrets.push_back(tmp);
            }
        }
    }
    if (turrets.size() == 1) return false;

    return true;
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int K;
    cin >> N >> M >> K;

    fld.resize(N, vector<int>(M, 0));
    turnManage.resize(N, vector<int>(M, 0));
    isDamaged.resize(N, vector<bool>(M, false));
    visited.resize(N, vector<bool>(M, false));

    Turret tmp;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> fld[i][j];
            if (fld[i][j] > 0) {
                tmp.x = i;
                tmp.y = j;
                tmp.damage = fld[i][j];
                tmp.turn = 0;
                turrets.push_back(tmp);
            }
        }
    }

    // simulation
    for (int turn=1; turn<K+1; turn++) {
        init();

        vector<int> info = findAttackerAndDefender();
        attack(info[0], info[1], info[2], info[3], turn);

        cout << "\n";
        for (auto v: fld) {
            for (int num : v) cout << num << " ";
            cout << "\n";
        }

        if (!fixTurret(turn)) break;

        cout << "\n";
        for (auto v: fld) {
            for (int num : v) cout << num << " ";
            cout << "\n";
        }
    }

    int res = 0;
    for (auto v: fld) {
        for (int atkP : v) {
            res = max(res, atkP);
        }
    }

    cout << res << "\n";

    return 0;
}