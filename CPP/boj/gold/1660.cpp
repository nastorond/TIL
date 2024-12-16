// 캡틴 이다솜 개어렵네
#include <iostream>
#include <vector>
#define endl "\n"
#define MAX_VAL 300001

using namespace std;

int cal(int n) {
    return (n*(n+1))/2;
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vector<int> balls;
    int dp[MAX_VAL] = {};
    int n, cnt;

    cin >> n;
    
    dp[0] = 0;
    cnt = 0;

    int i=1;
    while (cnt<n) {
        cnt += cal(i);
        balls.push_back(cnt);
        i++;
    }

    for (int i=1; i<=n; i++) {
        // 적당히 큰 수
        dp[i] = 1e9;
        for (int b=0; b<balls.size(); b++) {
            if (balls[b] == i) {
                dp[i]=1; 
                break;
            }
            else if (balls[b] > i) break;
            dp[i] = min(dp[i], dp[i-balls[b]] + 1);
        }
    }


    /*
    while (n>0) {
        for (int i=1; i<=n*2; i++) {
            if (dp[i] == 0) {
                dp[i] = cal(i) + dp[i-1];
            }   
            if (dp[i] > n) {
                n -= dp[i-1];
                res++;
                break;
            }
        }
    }
    */

    cout << dp[n] << endl;

    return 0;
}