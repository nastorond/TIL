#include <iostream>
#include <queue>
#define pii pair<int, int>

using namespace std;

struct compare 
{
    bool operator() (pii a, pii b)
    {
        int sumA = a.first + a.second;
        int sumB = b.first + b.second;
        if (sumA == sumB)
        {
            if (a.first == b.first) return a.second > b.second;
            else return a.first > b.first;
        }
        return sumA > sumB;
    }
};

const int MAX_N = 100000;
int n, m;

int main() {
    cin >> n >> m;
    priority_queue<pii, vector<pii>, compare> pq;

    int x, y;
    for (int i=0; i<n; ++i)
    {
        cin >> x >> y;
        pq.push(make_pair(x, y));
    }

    while (m--)
    {
        pii tmp = pq.top(); pq.pop();

        //cout << tmp.first << " " << tmp.second << "\n";

        tmp.first += 2;
        tmp.second += 2;
        pq.push(tmp);
    }

    cout << pq.top().first << " " << pq.top().second << "\n";

    return 0;
}
