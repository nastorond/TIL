// 1, 2, 3 더하기
// boj silver
// dynamic programming / recursion
#include <iostream>

using namespace std;

int dp[12] = {};
int n, target_num;

void dfs(int cur_val) {
    if (cur_val > target_num) return ;
    if (cur_val == target_num) {
        dp[cur_val]++;
        return ;
    }
    dfs(cur_val+1);
    dfs(cur_val+2);
    dfs(cur_val+3);
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> target_num;
        dfs(0);
        cout << dp[target_num] << "\n";
    }

    return 0;
}