//! 위상정렬 기반의 코드
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
// current -> {next, k}
vector<vector<pair<int,int>>> adj;
vector<int> indegree;
// dp[i][j] = i를 만들 때 필요한 기본 부품 j 개수
vector<vector<int>> dp;

void init() {
    cin >> N >> M;
    adj.assign(N + 1, {});
    indegree.assign(N + 1, 0);
    dp.assign(N + 1, vector<int>(N + 1, 0));

    for (int i = 0; i < M; ++i) {
        int X, Y, K;
        cin >> X >> Y >> K;
        adj[Y].push_back({X, K});   // Y -> X
        indegree[X]++;              // X로 들어오는 간선 +1
    }
}

void solution() {
    queue<int> q;

    // 기본 부품: 진입 차수 0
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
            dp[i][i] = 1;   // 기본 부품 자기 자신 1개
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (const auto &nx : adj[cur]) {
            int next = nx.first;
            int k    = nx.second;

            // cur을 k개 써서 next 1개 만듦
            for (int j = 1; j <= N; ++j) {
                dp[next][j] += dp[cur][j] * k;
            }

            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    // 완제품 N에 대한 기본 부품 개수 출력
    for (int j = 1; j <= N; ++j) {
        if (dp[N][j] > 0) {
            cout << j << " " << dp[N][j] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solution();
    return 0;
}