// dp 계단오르기
#include <iostream>
#define MAX_VAL 302

using namespace std;

int n, stairs[MAX_VAL], dp[MAX_VAL];

int Solution () {
    for (int i=1; i<=n; i++) {
        
    }

    return dp[n];
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n;
    stairs[0] = 0;
    dp[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> stairs[i];
    }

    return 0;
}