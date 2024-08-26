#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dominoes[7][7], N, resMax=-1e9, resMin=1e9;
bool visited[7] = {false, };

void ckAll(int curRow, int value, vector<pair<int, int>>& par) {
    if (curRow == N) {
        int cycleCnt = 0;
        vector<bool> nodeVisited(N, false);

        for (int i = 0; i < N; i++) {
            if (!nodeVisited[i]) {
                int current = i;
                while (!nodeVisited[current]) {
                    nodeVisited[current] = true;
                    int next = par[current].second - 1;
                    if (next == current) break;
                    current = next;
                }
                cycleCnt++;
            }
        }

        if (cycleCnt % 2 == 0 && cycleCnt > 0) {
            value *= -1;
        }

        resMax = max(value, resMax);
        resMin = min(value, resMin);
        return;
    }
    
    for (int i=0; i<N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            par.push_back(make_pair(curRow+1, i+1));
            ckAll(curRow+1, value*dominoes[curRow][i], par);
            visited[i] = false;
            par.pop_back();
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N;
    string inputText;
    if (N == 1) {
        cin >> inputText;
        if ('A' <= inputText[0] && inputText[0] <= 'I') {
            cout << -1 * (inputText[0] - 'A' + 1) << "\n";
            cout << -1 * (inputText[0] - 'A' + 1) << "\n";
        } else {
            cout << -1 * (inputText[0] - '0') << "\n";
            cout << -1 * (inputText[0] - '0') << "\n";
        }
        return 0;
    }

    for (int i=0; i<N; i++) {
        cin >> inputText;
        int cnt=0;
        for (char c: inputText) {
            if (0 > c - 'A') {
                dominoes[i][cnt] = c - '0';
            } else {
                dominoes[i][cnt] = -(c-'A'+1);
            }
            cnt++;
        }
    }

    pair<int, int> tmp;
    vector<pair<int, int>> tmpV;
    // tmpV.push_back(tmp);
    ckAll(0, 1, tmpV);

    cout << resMin << "\n";
    cout << resMax << "\n";

    return 0;
}