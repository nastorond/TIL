#include <iostream>

using namespace std;

int ret = 1e9;

void dfs(int cur, int cnt)
{
    if (cur == 1) 
    {
        ret = min(ret, cnt);
        return ;
    }

    if (cur < 0) return;
    if (cnt > ret) return;

    dfs(cur - 1, cnt+1);
    dfs(cur + 1, cnt+1);
    
    if (cur%2 == 0) dfs(cur/2, cnt+1);
    if (cur%3 == 0) dfs(cur/3, cnt+1);
}

int N;

int main() {
    cin >> N;

    // Please write your code here.

    dfs(N, 0);

    cout << ret << "\n";

    return 0;
}
