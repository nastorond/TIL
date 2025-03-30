#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main ()
{
    vector<string> preWords;
    vector<string> candidates;
    unordered_set<string> preWordSet;
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int N;
    string tmp;
    string preFix, sufFix;
    int cnt = 0;

    cin >> N;

    if (N == 1) //! 예외처리
    {
        cin >> tmp;
        cin >> N;
        cin >> tmp;
        cout << tmp << "\n";
        return 0;
    }

    for (int i=0; i<N; i++)
    {
        cin >> tmp;
        if (tmp == "?") cnt = i;
        preWords.push_back(tmp);
        preWordSet.insert(tmp);
    }

    cin >> N;
    while(N--)
    {
        cin >> tmp;
        candidates.push_back(tmp);
    }

    if (cnt == 0)
    {
        preFix = "";
        sufFix = preWords[1][0];
    }
    else if (cnt == preWords.size() - 1)
    {
        preFix = preWords[cnt-1][preWords[cnt-1].size()-1];
        sufFix = "";
    }
    else 
    {
        preFix = preWords[cnt-1][preWords[cnt-1].size()-1];
        sufFix = preWords[cnt+1][0];
    }

    for (string s : candidates)
    {
        if (preFix != "" && preFix[0] != s[0]) continue;
        if (sufFix != "" && sufFix[0] != s[s.size()-1]) continue;
        if (preWordSet.count(s) > 0) continue;

        cout << s << "\n";
        break;
    }

    return 0;
}