#include <iostream>
#include <vector>

using namespace std;

int res = 0;

// Brute Force
void BF (int prev, int tot, int goal) {
    if (tot >= goal) {
        if (tot == goal) res++;
        return ;
    }

    if (prev <= 1) BF(1, tot+1, goal);
    if (prev <= 2) BF(2, tot+2, goal);
    if (prev <= 3) BF(3, tot+3, goal);
}

// int main () {
//     ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

//     int n;
    
//     cin >> n;
//     BF(1, 0, n);

//     cout << res << "\n";

//     return 0;
// }

// DP 풀이
int main() {

    int tc, n;
    cin >> tc;

    vector<int> dp(10001, 0);
    dp[0] = 1;

    for (int i = 1; i <= 3; i++) {
        for (int j = i; j <= 10001; j++) {
            dp[j] += dp[j - i];
        }
    }

    while (tc--) {
        cin >> n;
        
        cout << dp[n] << "\n";
    }

    return 0;
}