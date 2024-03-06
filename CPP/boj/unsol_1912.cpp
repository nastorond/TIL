// boj 연속합
#include <iostream>
#define endl "\n"
#define MAX_VAL 100010

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n, dp[MAX_VAL], vals[MAX_VAL];

    // input
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> vals[i];
    }

    dp[0] = 0;
    

    cout << dp[n] << endl;

    return 0;
}