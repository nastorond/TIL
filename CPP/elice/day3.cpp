#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    string S;
    cin >> S;
    stack<char> tmp;
    
    string tmp_str = "";
    for (auto it : S) {
        if (isdigit(it)) {
            tmp.push(it);
        } else if (it == '(') {
            tmp.push(it);
        } else {
            while(tmp.top() != '(') {
                tmp_str += tmp.top(); tmp.pop();
            }
            tmp.pop();
            char repeat = tmp.top() - '0'; tmp.pop();
            for (int i=0; i<repeat; i++) {
                for (auto a : tmp_str) {
                    tmp.push(a);
                }
            }
            tmp_str = "";
        }
    }
    cout << tmp.size() << "\n";

    // cout << res + 1 << "\n";

    return 0;
}
