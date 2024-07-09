#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string N;
    cin >> N;

    vector<int> per(N.begin(), N.end());

    if (next_permutation(per.begin(), per.end())) {
        for (char digit : per) {
            cout << digit;
        }
        cout << "\n";
    }

    return 0;
}