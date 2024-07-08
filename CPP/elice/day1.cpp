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

    // Next permutation을 찾기 위해 다음 순열 함수 사용
    if (next_permutation(per.begin(), per.end())) {
        for (char digit : per) {
            cout << digit;
        }
        cout << "\n";
    } else {
        cout << "No next permutation\n";
    }

    return 0;
}