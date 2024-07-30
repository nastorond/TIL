#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int> q;
    for (int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp==0 && !q.empty()) {
            cout << -q.top() << "\n";
            q.pop();
        } else if (tmp == 0) {
            cout << 0 << "\n";
        } else {
            q.push(-tmp);
        }
    }

    return 0;
}