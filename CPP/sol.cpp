#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

regex re("\\d[,]");

bool solution(string amountText) {
    bool answer = true;

    for (char c: amountText) {
    }

    return answer;
}

int main () {
    cout << solution("10,000원") << "\n";
    return 0;
}