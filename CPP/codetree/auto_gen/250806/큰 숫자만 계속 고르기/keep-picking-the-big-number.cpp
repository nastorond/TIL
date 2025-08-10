#include <iostream>
#include <queue>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    int tmp;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        pq.push(tmp);
    }

    // Please write your code here.
    while(m--)
    {
        tmp = pq.top(); pq.pop();
        --tmp;
        pq.push(tmp);
    }
    cout << pq.top() << "\n";

    return 0;
}
