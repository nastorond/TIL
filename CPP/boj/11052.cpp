#include <iostream>
#define MAX_VAL 1002
#define endl "\n"

using namespace std;

int n;
int cards[MAX_VAL];
int dp[MAX_VAL];

int Solution () {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            dp[i] = max(dp[i], dp[i-j] + cards[j]);
            // cout << i << " " << j << " " << dp[i] << "\n";
        }
    } 
    return dp[n];
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    // input
    cin >> n;
    cards[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> cards[i];
    }
    dp[1] = cards[1];

    int ans = Solution();

    cout << ans << endl;

    return 0;
}