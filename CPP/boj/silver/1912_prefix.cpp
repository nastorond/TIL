// boj 연속합
#include <iostream>
#define endl "\n"
#define MAX_VAL 100010

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n, dp[MAX_VAL], vals[MAX_VAL];
    int res=-1e9;

    // input
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> vals[i];
    }

    dp[0] = 0;
    for (int i=1; i<=n; i++)
    {
        dp[i] = max(dp[i-1] + vals[i], vals[i]);
        res = max(res, dp[i]);
    }

    cout << res << endl;

    return 0;
}