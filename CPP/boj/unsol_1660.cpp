#include <iostream>
#define endl "\n"
#define MAX_VAL 300001

using namespace std;

int cal(int n) {
    return (n*(n+1))/2;
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int dp[MAX_VAL] = {};
    int n, res;

    cin >> n;
    
    dp[0] = 0;

    for (int i=1; i<=n*2; i++) {
        dp[i] = cal(i) + dp[i-1];
        // cout << "test " << dp[i] << endl;
        if (dp[i] > n) {
            res = i-1;
            break;
        }
    }

    cout << res << endl;

    return 0;
}