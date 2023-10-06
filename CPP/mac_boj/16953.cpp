#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


long long bfs(long long val_first, long long ans){
    queue<pair<long long, long long>> q;
    pair<long long, long long> val;
    val.first = val_first;
    val.second = 0;
    q.push(val);
    while(!q.empty()){
        pair tmp = q.front();
        q.pop();
        if (tmp.first > ans) continue;
        if (tmp.first == ans) return tmp.second;
        val.first = tmp.first * 2;
        val.second = tmp.second + 1;
        q.push(val);
        val.first = (tmp.first * 10) + 1;
        val.second = tmp.second + 1;
        q.push(val);
    }
    return -2;
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    long long val_first, ans;
    cin >> val_first >> ans;

    long long res = bfs(val_first, ans);

    cout << res+1 << "\n";

    return 0;
}