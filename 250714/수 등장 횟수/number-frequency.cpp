#include <iostream>

using namespace std;

const int MAX_N = 100000;

int n, m;
int arr[MAX_N];
int nums[MAX_N];
int ck[MAX_N] = {0, };

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ck[arr[i]]++;
    }

    for (int i = 0; i < m; i++) {
        cin >> nums[i];
        cout << ck[nums[i]] << " ";
    }

    // Please write your code here.

    return 0;
}
