#include <iostream>
#include <deque>

using namespace std;

int n, t;
deque<int> u;
deque<int> d;

int main() {
    cin >> n >> t;

    u.resize(n);
    d.resize(n);
    for (int i = 0; i < n; i++) cin >> u[i];

    for (int i = 0; i < n; i++) cin >> d[i];

    // Please write your code here.
    int turn = t%(2*n);
    //! cout << turn << "\n";

    while (turn > 0)
    {
        turn--;
        int tmp1 = u.back(); u.pop_back();
        int tmp2 = d.back(); d.pop_back();

        u.push_front(tmp2);
        d.push_front(tmp1);
    }

    for (auto& it : u)
    {
        cout << it << " ";
    }
    cout << "\n";
    for (auto& it : d)
    {
        cout << it << " ";
    }

    return 0;
}
