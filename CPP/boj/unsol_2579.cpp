// dp 계단오르기
#include <iostream>
#define MAX_VAL 302

using namespace std;

int n, stairs[MAX_VAL], dp[MAX_VAL];

int Solution () {
    for (int i=1; i<n-1; i++) {
        
    }

    return dp[n-1] + stairs[n-1];
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> stairs[i];
    }
    dp[0] = 0;

    return 0;
}
