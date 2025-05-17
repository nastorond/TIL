// dp 계단오르기
#include <iostream>
#include <cstring>
#define MAX_VAL 302

using namespace std;

int n, stairs[MAX_VAL], dp[MAX_VAL][3];

int upStairs (int cur, int steps) 
{
    if (cur > n)
    {
        return -1e9;
    }

    if (cur == n)
    {
        return stairs[cur];
    }

    if (dp[cur][steps] != -1)
    {
        return dp[cur][steps];
    }

    int point = -1e9;

    if (steps < 2)
    {
        point = max(point, upStairs(cur+1, steps+1));
    }
    point = max(point, upStairs(cur+2, 1));

    dp[cur][steps] = point + stairs[cur];

    return dp[cur][steps];
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n;

    stairs[0] = 0;
    memset(dp, -1, sizeof(dp));

    for (int i=1; i<=n; i++)
    {
        cin >> stairs[i];
    }

    cout << upStairs(0,0)<< "\n";

    return 0;
}
