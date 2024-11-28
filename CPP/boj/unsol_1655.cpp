#include <iostream>
#include <queue>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int N, num;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    cin >> N;

    while (N--) {
        cin >> num;
        
        if (maxHeap.empty() || maxHeap.top() > num) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top()); minHeap.pop();
        } else if (minHeap.size() + 1 < maxHeap.size()) {
            minHeap.push(maxHeap.top()); maxHeap.pop();
        }

        cout << maxHeap.top() << "\n";
    }

    return 0;
}