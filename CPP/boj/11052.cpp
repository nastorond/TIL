#include <iostream>
#define MAX_VAL 1002
#define endl "\n"

using namespace std;

int n;
int cards[MAX_VAL];

int Solution () {
    int res;

    return res;
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    // input
    cin >> n;
    cards[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> cards[i];
    }

    int ans = Solution();

    cout << ans << endl;

    return 0;
}