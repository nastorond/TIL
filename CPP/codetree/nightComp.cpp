#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

struct nightInfo {
    int x, y, health, maxHP, width, height;
    bool isLive;

    nightInfo () : x(0), y(0), maxHP(0), health(0), width(0), height(0), isLive(true) {}
};

vector<vector<int>> fld;
unordered_map<int, nightInfo> nights;
int mv[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool tryIsAvail (int num, int& dir) {
    vector<vector<int>> fld2 = fld;
    queue<int> q;
    unordered_set<int> ck;

    q.push(num);
    ck.insert(num);

    while (!q.empty()) {
        num = q.front(); q.pop();
        int x = nights[num].x;
        int y = nights[num].y;
        for (int i=x; i<x+nights[num].height; i++) {
            for (int j=y; j<y+nights[num].width; j++) {

                int dx = i + mv[dir][0];
                int dy = j + mv[dir][1];
                fld2[i][j] -= num;
                int tmp = fld2[dx][dy]%2 ? fld2[dx][dy]-1 : fld2[dx][dy];

                if (fld2[dx][dy] == 2) return false;
                if (fld2[dx][dy] > 3 && ck.count(tmp) == 0) {
                    ck.insert(tmp);
                    q.push(tmp);
                }

                fld2[dx][dy] += num;
            }
        }
    }
    return true;
}

void simulation(int num, int& dir) {
    if (!tryIsAvail(num, dir)) return ;

    queue<int> q;
    unordered_set<int> ck;

    q.push(num);
    ck.insert(num);

    while (!q.empty()) {
        int nightNum = q.front(); q.pop();
        int x = nights[nightNum].x;
        int y = nights[nightNum].y;
        int cnt = 0;
        nights[nightNum].x += mv[dir][0];
        nights[nightNum].y += mv[dir][1];

        for (int i=x; i<x+nights[nightNum].height; i++) {
            for (int j=y; j<y+nights[nightNum].width; j++) {
                int dx = i + mv[dir][0];
                int dy = j + mv[dir][1];
                fld[i][j] -= nightNum;
                int tmp = fld[dx][dy]%2 ? fld[dx][dy]-1 : fld[dx][dy];
                if (fld[dx][dy] > 3 && ck.count(tmp) == 0) {
                    ck.insert(tmp);
                    q.push(tmp);
                }
                fld[dx][dy] += nightNum;
                if (fld[dx][dy]%2) cnt++;
            }
        }
        if (nightNum == num) continue;
        nights[nightNum].health -= cnt;
        if (nights[nightNum].health <= 0) {
            nights[nightNum].isLive = false;
            for (int i=nights[nightNum].x; i<nights[nightNum].x+nights[nightNum].height; i++) {
                for (int j=nights[nightNum].y; j<nights[nightNum].y+nights[nightNum].width; j++) fld[i][j] -= nightNum;
            }
        }
    }

    return ;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int L, N, Q, res=0;
    
    cin >> L >> N >> Q;
    fld.resize(L+2, vector<int>(L+2, 2));

    for (int i=1; i<=L; i++) {
        for (int j=1; j<=L; j++) {
            cin >> fld[i][j];
        }
    }

    for (int i=2; i<=N+1; i++) {
        nightInfo tmp;
        cin >> tmp.x >> tmp.y >> tmp.height >> tmp.width >> tmp.health;
        tmp.maxHP = tmp.health;
        for (int h=tmp.x; h<tmp.x+tmp.height; h++) {
            for (int w=tmp.y; w<tmp.y+tmp.width; w++) {
                fld[h][w] += i*2;
            }
        }
        nights[i*2] = tmp;
    }

    for (int q=0; q<Q; q++) {
        int i, d;
        cin >> i >> d;
        if (!nights[i*2+2].isLive) continue;

        simulation(i*2+2, d);

        cout << "\n";
        for (auto v: fld) {
            for (auto num : v) cout << num << " ";
            cout << "\n";
        }
    }

    for (auto night : nights) {
        if (!night.second.isLive) continue;
        res += night.second.maxHP - night.second.health;
    }
    
    cout << res << "\n";

    return 0;
}