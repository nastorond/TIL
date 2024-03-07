// dp 계단오르기
#include <iostream>
#define MAX_VAL 302

using namespace std;

int n, stairs[MAX_VAL], dp[MAX_VAL];

int Solution () {
    for (int i=3; i<n-1; i++) {
        
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

// 3개를 연속해서 밟을 수 없음
// 한번 건너 뛰게되면 다음 칸은 무조건 밟아야 함
// i-1 + i-2, i-1 + i ?? 이건가
// 그럼 dp[3] 부터 시작해야대는디
// dp [0] = 0; dp[1] = stair[1], dp[2] = dp[1] + stair[2], dp[1]
