// boj 1707 이분 그래프
#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
#define MAX_VERTEX 20002

using namespace std;

vector<vector<int>> gp(MAX_VERTEX);
int visited[MAX_VERTEX];
int vertex, e;

/**
 * other solution via bfs algorithm
 * It gonnna be more easy to understand than dfs
 * It's including isBinary or not
 */
bool bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < gp[cur].size(); i++) {
            int next = gp[cur][i];
            if (visited[next] == 0) {
                visited[next] = 3 - visited[cur]; // 1 -> 2, 2 -> 1
                q.push(next);
            } else if (visited[next] == visited[cur]) {
                return false;
            }
        }
    }
    return true;
}

void dfs (int cur) {
    if (visited[cur] == 0) {
        visited[cur] = 1;
    }
    int len = gp[cur].size();
    for (int i=0; i<len; i++) {
        int next = gp[cur][i];
        if (visited[next] == 0) {
            if (visited[cur] == 1) visited[next] = 2;
            else if (visited[cur] == 2) visited[next] = 1;
            dfs(next);
        }
    }
}

bool isBinary () {
    for (int i=1; i<=vertex; i++) {
        int len = gp[i].size();
        for (int j=0; j<len; j++) {
            int num = gp[i][j];
            if (visited[i] == visited[num]) return false;
        }
    }
    return true;
}

void solution() {
    for (int i=1; i<=vertex; i++) {
        if (!visited[i]) dfs(i);
    }

    if (isBinary()) cout << "YES\n";
    else cout << "NO\n";
}

void input() {
    cin >> vertex >> e;

    for (int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    for (int tc=1; tc<=test_case; tc++) {
        input();
        solution();

        // init
        for (int i=1; i<=vertex; i++) {
            gp[i].clear();
            visited[i] = 0;
        }
    }
    return 0;
}