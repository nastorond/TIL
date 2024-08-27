#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n, res;
    cin >> n;
    res = n;

    for (int i=2; i<pow(n, 0.5)+1; i++) {
        if (n%i == 0) {
            res -= res/i;
            while (n%i == 0) {
                n /= i;
            }
        }
    }

    if (n > 1) {
        res -= res/n;
    }

    cout << res << "\n";

    return 0;
}