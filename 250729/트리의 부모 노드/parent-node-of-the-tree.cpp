#include <iostream>
#include <unordered_map>

using namespace std;

int n;
// int from[100000], to[100000];
unordered_map<int, int> tree;
int arr[100000] = {0, };

int main() {
    cin >> n;
    // for (int i = 0; i < n - 1; i++) {
    //     cin >> from[i] >> to[i];
    // }

    // Please write your code here.
    int from, to;
    for (int i=0; i<n-1;i++)
    {
        cin >> from >> to;
        arr[to] = from;
    }

    for (int i=2; i<n+1; i++)
    {
        if (arr[i] == 0) continue;
        cout << arr[i] << "\n";
    }

    return 0;
}