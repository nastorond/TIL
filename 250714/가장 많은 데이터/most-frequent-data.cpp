#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n;
string words[100000];
unordered_map<string, int> mp;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    // Please write your code here.
    int ret = 0;
    string k;
    for (int i=0; i<n; i++)
    {
        k = words[i];
        auto it = mp.find(k);
        if (it == mp.end())
        {
            mp.insert({k, 1});
        }
        else 
        {
            mp[k]++;
            ret = max(ret, mp[k]);
        }
    }
    
    cout << ret << "\n";

    return 0;
}
