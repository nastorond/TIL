// 4 연산
#include <iostream>
#include <queue>
#include <string>
#define endl "\n"

using namespace std;

int s, t;

string bfs() {
    queue<pair<int, string>> q;
    q.push(make_pair(s, ""));
    while (!q.empty()) {
        int num = q.front().first;
        string op = q.front().second;
        q.pop();

        cout << num << endl;

        if (num == t) {
            return op;
        }

        for (int i=0; i<4; i++) {
            if (i==0 && num*num < t) {
                q.push(make_pair(num*num, op + "*"));
            }
            else if (i==1 && num+num < t) {
                q.push(make_pair(num*2, op + "+"));
            }
            else if (i==2 && t==0) {
                q.push(make_pair(num - num, op + "-"));
            }
            else if (i==3 && num > 1) {
                q.push(make_pair(num / num, op + "/"));
            }
        } 
    }
    return "-1";
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> s >> t;

    string ans = bfs();

    cout << ans << endl;

    return 0;
}