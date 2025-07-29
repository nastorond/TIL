#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n;
int from[100000], to[100000];
unordered_map<int, vector<int>> tree;
int roots[100001] = {0, };

void findingRoot(int cur)
{
    auto tmp = tree.find(cur);
    if (tmp == tree.end()) return ;

    for (int chd : tree[cur])
    {
        //if (roots[chd] != 0) continue;
        roots[chd] = cur;
        findingRoot(chd);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i];
    }

    // Please write your code here.
    for (int i=0; i<n-1;i++)
    {
        auto tmp = tree.find(from[i]);
        if (tmp != tree.end())
        {
            tree[from[i]].push_back(to[i]);
        }
        else
        {
            vector<int> tV;
            tV.push_back(to[i]);
            tree[from[i]] = tV;
        }
    }

    findingRoot(1);
    
    for (int i=2; i<n+1; i++)
    {
        if (roots[i] != 0)
        {
            cout << roots[i] << "\n";
        }
    }

    return 0;
}