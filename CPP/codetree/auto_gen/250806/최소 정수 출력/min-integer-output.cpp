#include <iostream>
#include <queue>

using namespace std;

int n;
int x[200000];

struct compare
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main() {
    cin >> n;
    priority_queue<int, vector<int>, compare> pq;

    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;

        if (tmp == 0)
        {
            if (pq.empty()) cout << 0 << "\n";
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(tmp);
        }
    }

    return 0;
}
