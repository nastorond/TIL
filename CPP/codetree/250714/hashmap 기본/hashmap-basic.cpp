#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n;
string cmd[100000];
int k[100000];
int v[100000];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd[i];
        cin >> k[i];
        if (cmd[i] == "add") {
            cin >> v[i];
        }
    }

    // Please write your code here.
    unordered_map<int, int> mp;
    int key, val;
    for (int i=0; i<n; i++)
    {
        if (cmd[i] == "add")
        {
            key = k[i];
            val = v[i];
            mp[key] = val;
        }
        else
        {
            key = k[i];
            auto it = mp.find(key);

            if (cmd[i] == "remove")
            {
                mp.erase(it);
            }
            else 
            {
                if (it == mp.end()) cout << "None\n";
                else cout << it->second << "\n";
            }
        }
    }


    return 0;
}
