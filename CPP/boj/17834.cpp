#include <iostream>
#include <vector>
#include <queue>
#define MAXN 50005

using namespace std;

// 수풀의 수, 오솔길의 수
int N, M;
vector<vector<int>> fld;
int visitedR[MAXN], visitedL[MAXN];

void init () {
    for (int i=0; i<=N; i++) {
        visitedR[i] = -1;
        visitedL[i] = -1;
    }
}

// rabbit location, loin location
bool game (int rl, int ll) {
    init();
    queue<int> qR, qL;
    visitedR[rl] = 1;
    visitedL[ll] = 1;
    qR.push(rl); qL.push(ll);

    while (!qR.empty() && !qL.empty()) {
        int tmpR = qR.front(), tmpL = qL.front();
        qR.pop(); qL.pop();

        for (int i=0; i<fld[rl].size(); i++) {
            if (visitedR[fld[rl][i]] == -1 && visitedL[fld[rl][i]] != visitedR[tmpR]+1) {
                qR.push(fld[rl][i]);
                visitedR[fld[rl][i]] = visitedR[tmpR] + 1;
            } else return false;
        }
        for (int i=0; i<fld[ll].size(); i++) {
            if (visitedL[fld[ll][i]] == -1 && visitedL[fld[ll][i]] != visitedL[tmpL]+1) {
                qL.push(fld[ll][i]);
                visitedL[fld[ll][i]] = visitedL[tmpL] + 1;
            } else return false;
        }
    }
    return true;
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N >> M;
    // N 의 크기에 맞춰서 vector길이 지정
    fld.resize(N+1);

    // 수풀끼리 연결
    for (int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        fld[u].push_back(v);
        fld[v].push_back(u);
    }

    int res = 0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            res += (int) game(i, j);
        }
    }

    cout << res << "\n";

    return 0;
}