#include <iostream>
#include <unordered_map>

using namespace std;

const int MAX_N = 100001;

int n, m;
int arr[MAX_N];
int nums[MAX_N];
unordered_map<int, int> mp;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> nums[i];
    }

    // Please write your code here.
    int k;
    for (int i=0; i<n; i++)
    {
        k = arr[i];
        auto it = mp.find(k);
        if (it != mp.end())
        {
            it->second++;
        }
        else 
        {
            mp.insert({k, 1});
        }
    }

    for (int i=0; i<m; i++)
    {
        k = nums[i];
        auto it = mp.find(k);
        if (it != mp.end()) cout << it->second << " ";
        else cout << "0 ";
    }

    return 0;
}
