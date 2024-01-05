#include <iostream>
#include <string>
#include <unordered_map>
#define MAX_VAL 1001

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string tmp;
    unordered_map<string, int> inp_car;
    int n, ck_gap;
    int gaps[MAX_VAL];
    bool flg = false;
    int res=0;

    // input
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        inp_car.insert({tmp, i});
    }
    for (int i=0; i<n; i++) {
        cin >> tmp;
        gaps[i] = inp_car[tmp] - i;
        // if (i < inp_car[tmp]) {
        //     res++;
        // }
    }

    ck_gap = 1e9;
    for (int i=1; i<n; i++) {
        ck_gap = min(gaps[i], ck_gap);
    }

    cout << -ck_gap << "\n";

    return 0;
}