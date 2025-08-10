#include <iostream>
#include <vector>
#define pii pair<int, int>

using namespace std;

int n;
vector<vector<pii>> tree;
vector<int> dp;

void dfs(int cur)
{
    if (dp[cur] != -1) return dp[cur];
}

int main() {
    cin >> n;
    dp.resize(n+1, -1);
    tree.resize(n+1);

    int t, a, p;
    for (int i=0; i<n; ++i)
    {
        int num = i+2;
        cin >> t >> a >> p;

        a = t > 0 ? a : -a;

        tree[p].push_back(make_pair(num, a));
    }

    cout << dp[1] << "\n";

    return 0;
}