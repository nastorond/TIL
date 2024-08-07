#include <iostream>
#include <vector>
#include <queue>
#define MAXN 50005

using namespace std;

// 수풀의 수, 오솔길의 수
int N, M, res=0;
vector<vector<int>> fld(MAXN);
int visited[MAXN];

void dfs (int cur) {
    if (visited[cur] == 0) {
        visited[cur] = 1;
        res++;
    }
    for (int i=0; i<fld[cur].size(); i++) {
        int next = fld[cur][i];
        if (visited[next] == 0) {
            if (visited[cur] == 1) {
                visited[next] = 2;
            }
            else if (visited[cur] == 2) {
                visited[next] = 1;
                res++;
            }
            dfs(next);
        }
    }
}

bool isBinary() {
    for (int i=1; i<=N; i++) {
        for (int j=0; j<fld[i].size(); j++) {
            if (visited[i] == visited[fld[i][j]]) return false;
        }
    }
    return true;
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N >> M;

    // 수풀끼리 연결
    for (int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        fld[u].push_back(v);
        fld[v].push_back(u);
    }
    for (int i=1; i<=N; i++) {
        visited[i] = 0;
    }

    for (int i=1; i<=N; i++) {
        if (visited[i] == 0) dfs(i);
    }

    if (isBinary()) cout << res * (N-res) * 2 << "\n";
    else cout << 0 << "\n";

    return 0;
}