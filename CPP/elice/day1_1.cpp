#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> per;
int check_num;

int make_int() {
    int i=1, res=0;

    for(auto it=per.end()-1; it != per.begin()-1; it--) {
        res += *it * i;
        i *= 10;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string N;
    cin >> N;

    for (int i: N) {
        per.push_back(i-48);
    }

    check_num = stoi(N);

    sort(per.begin(), per.end());

    do {

        int tmp = make_int();
        if (check_num < tmp) {
            cout << tmp << "\n";
            break;
        }

    }while(next_permutation(per.begin(), per.end()));

}
