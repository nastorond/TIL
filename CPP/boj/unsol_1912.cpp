// boj 연속합 S2
#include <iostream>
#define endl "\n"
#define MAX_VAL 100010

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n, dp[MAX_VAL], vals[MAX_VAL];
    bool flg = true;

    // input
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> vals[i];
    }

    dp[0] = 0;
    dp[1] = vals[0];
    for (int i=2; i<=n; i++) {
        if (flg) {
            if (dp[i-1] + vals[i-1] > dp[i-1]) { 
                dp[i] = dp[i-1] + vals[i-1];
            }
            else {
                dp[i] = dp[i-1];
                flg = !flg;
            }
        }
        else {
            if (dp[i-1] < vals[i-1]) {
                dp[i] = vals[i-1];
                flg = !flg;
            }
            else {
                dp[i] = dp[i-1];
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}