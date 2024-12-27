#include <iostream>
#include <string>

using namespace std;

int alpha[26] = {0, };

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string word;
    cin >> word;
    for (char c: word) {
        alpha[c-'a']++;
    }

    for (int i=0; i<27; i++) cout << alpha[i] << " ";
    cout << "\n";

    return 0;
}