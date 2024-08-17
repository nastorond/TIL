// 가장 긴 부분이 증가하는 수열
#include <iostream>
#define MAX_VAL 1002

using namespace std;

int n;
int arr[MAX_VAL];

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    return 0;
}
