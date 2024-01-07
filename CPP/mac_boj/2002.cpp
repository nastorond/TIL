#include <iostream>
#include <string>
#include <unordered_map>
#define MAX_VAL 1001

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string tmp;
    unordered_map<string, int> inp_car;
    string out_car[MAX_VAL];
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
        out_car[i] = tmp;
    }

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (inp_car[out_car[i]] > inp_car[out_car[j]]) {
                res++;
                break;
            }
        }
    }

    cout << res << "\n";

    return 0;
}