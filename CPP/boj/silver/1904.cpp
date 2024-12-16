// boj 1904 01 타일
#include <iostream>
#define endl "\n"
#define MAX_VAL 1000001

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n, res;
    int dp[MAX_VAL] = {};

    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    if (n < 3) {
        res = dp[n];
    }
    else {
        for (int i=3; i<=n; i++) {
            // if (i%2) dp[i] = dp[i-1] + 1;
            // else dp[i] = dp[i-1] + 2;
            dp[i] = (dp[i-2] + dp[i-1])%15746;
        }
        res = dp[n];
    }

    cout << res << "\n";

    return 0;
}