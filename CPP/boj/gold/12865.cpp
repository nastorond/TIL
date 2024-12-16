// 평범한 배낭 / DP / Gold 5
#include <iostream>
#include <vector>

using namespace std;

int res=0, N, limit;
vector<bool> visited;
vector<pair<int, int>> candidates;
vector<vector<int>> dp;

void BF (int value, int weight) {
    res = res < value ? value : res;

    for (int i=0; i<N; i++) {
        if (!visited[i] && candidates[i].first + weight <= limit) {
            visited[i] = true;
            BF(value + candidates[i].second, weight + candidates[i].first);
            visited[i] = false;
        }
    }
}

int solve (int weight, int now) {
    if (now == N) return 0;
    if (dp[weight][now] != -1) return dp[weight][now];

    int ret = solve(weight, now + 1);

    if (weight + candidates[now].first <= limit) {
        ret = max(ret, candidates[now].second + solve(weight + candidates[now].first, now + 1));
    }

    dp[weight][now] = ret;

    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N >> limit;

    visited.resize(N+1, false);
    dp.resize(limit+1, vector<int>(N+1, -1));
    candidates.resize(N+1, make_pair(0,0));

    for (int i=0; i<N; i++) {
        cin >> candidates[i].first >> candidates[i].second;
    }

    // BF(0, 0);

    cout << res << "\n";
    cout << solve(0, 0) << "\n";

    return 0;
}