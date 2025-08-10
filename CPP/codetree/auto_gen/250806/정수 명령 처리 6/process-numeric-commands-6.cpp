#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N;
string command;

int main() {
    cin >> N;
    priority_queue<int> pq;

    for (int i = 0; i < N; i++) {
        cin >> command;
        if (command == "push") 
        {
            int x;
            cin >> x;
            pq.push(x);
        }
        else if (command == "pop")
        {
            cout << pq.top() << "\n";
            pq.pop();
        }
        else if (command == "size")
        {
            cout << pq.size() << "\n";
        }
        else if (command == "empty")
        {
            cout << pq.empty() << "\n";
        }
        else
        {
            cout << pq.top() << "\n";
        }
    }
    return 0;
}
