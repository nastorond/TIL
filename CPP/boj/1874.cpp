#include <iostream>
#include <stack>
#include <string>

using namespace std;

string solution () {
    int n, num = 1, tmp;
    stack<int> st;
    string answer = "";
    bool flg = false;

    cin >> n;
    for (int el=0; el<n; el++) {
        cin >> tmp;
        while (num <= tmp) {
            st.push(num++);
            answer += "+\n";
        }
        if (st.top() == tmp) {
            st.pop();
            answer += "-\n";
        }
        else flg = true;
    }
    if (!flg) return answer;
    else return "NO";
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cout << solution();

    return 0;
}