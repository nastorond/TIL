#include <iostream>
#include <algorithm>
#define MAX_VAL 10003

using namespace std;

int res=0, n;
int arr[MAX_VAL];
int dp[MAX_VAL] = {};

void dfs(int cur_loc, int cnt, int cur_val) {
    if (cnt == 2 && dp[cur_loc] > cur_val) return ;

    if (n+1 == cur_loc) {
        res = max(res, cur_val);
        return ;
    }

    if (cnt < 2) {
        dfs(cur_loc+1, cnt+1, cur_val+arr[cur_loc]);
        dp[cur_loc+1] = cur_val+arr[cur_loc];
    }
    dfs(cur_loc+1, 0, cur_val);
    dp[cur_loc+1] = cur_val;
}

void solution() {
    dp[0] = arr[0];
    if (n>1) {
        dp[1] = arr[0] + arr[1]; 
    }
    if (n>2) {
        dp[2] = max(arr[0] + arr[2], arr[1]+arr[2]);
    }
    if (n>3) {
        for (int i=3; i<n; i++) {
            dp[i] = max(*max_element(dp, dp + i-1), *max_element(dp, dp + i-2)+arr[i-1]) + arr[i]; 
        }
    }
    res = *max_element(dp, dp+n);
}



int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // dfs(0, 0, 0);
    solution();

    cout << res << "\n";

    return 0;
} 