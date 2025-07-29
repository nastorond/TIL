#include <iostream>
#include <unordered_map>

using namespace std;

int n;
int from[100000], to[100000];
unordered_map<int, int> tree;

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i];
    }

    // Please write your code here.
    for (int i=0; i<n-1;i++)
    {
        tree.insert({to[i], from[i]});
    }

    for (int i=2; i<n+1; i++)
    {
        auto tmp = tree.find(i);
        if (tmp != tree.end())
        {
            cout << tmp->second << "\n";
        }
    }

    return 0;
}