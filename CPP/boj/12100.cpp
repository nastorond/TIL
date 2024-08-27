#include <iostream>
#include <vector>

using namespace std;

int N, ret=0;
vector<vector<int>> board;

vector<vector<int>> swipingUp (vector<vector<int>>& pos) {
    vector<vector<int>> res(N, vector<int> (N, 0));

    for (int i=0; i<N; i++) {
        vector<bool> merged(N, false);
        int idx = 0;
        for (int j=0; j<N; j++) {
            if (pos[j][i] > 0) {
                if (idx > 0 && res[idx-1][i] == pos[j][i] && !merged[idx-1]) {
                    res[idx-1][i] *= 2;
                    merged[idx-1] = true;
                }
                else {
                    res[idx][i] = pos[j][i];
                    idx++;
                }
            }
        }
    }
    return res;
}

vector<vector<int>> swipingDown (vector<vector<int>>& pos) {
    vector<vector<int>> res(N, vector<int> (N, 0));

    for (int i=0; i<N; i++) {
        vector<bool> merged(N, false);
        int idx = N-1;
        for (int j=N-1; j>=0; j--) {
            if (pos[j][i] > 0) {
                if (idx < N-1 && res[idx+1][i] == pos[j][i] && !merged[idx+1]) {
                    res[idx+1][i] *= 2;
                    merged[idx+1] = true;
                }
                else {
                    res[idx][i] = pos[j][i];
                    idx--;
                }
            }
        }
    }

    return res;
}

vector<vector<int>> swipingLeft (vector<vector<int>>& pos) {
    vector<vector<int>> res(N, vector<int> (N, 0));

    for (int i=0; i<N; i++) {
        vector<bool> merged(N, false);
        int idx=0;
        for (int j=0; j<N; j++) {
            if (pos[i][j] > 0) {
                if (idx>0 && res[i][idx-1] == pos[i][j] && !merged[idx-1]) {
                    res[i][idx-1] *= 2;
                    merged[idx-1] = true;
                }
                else {
                    res[i][idx] = pos[i][j];
                    idx++;
                }
            }
        }
    }

    return res;
}

vector<vector<int>> swipingRight (vector<vector<int>>& pos) {
    vector<vector<int>> res(N, vector<int> (N, 0));

    for (int i=0; i<N; i++) {
        vector<bool> merged(N, false);
        int idx = N-1;
        for (int j=N-1; j>=0; j--) {
            if (pos[i][j] > 0) {
                if (idx < N-1 && res[i][idx+1] == pos[i][j] && !merged[idx+1]) {
                    res[i][idx+1] *= 2;
                    merged[idx+1] = true;
                }
                else {
                    res[i][idx] = pos[i][j];
                    idx--;
                }
            }
        }
    }

    return res;
}

void ckAll (int cnt, vector<vector<int>>& pos) {
    if (cnt == 5) {
        for (int i=0; i<N; i++) {
            for (int num : pos[i]) {
                ret = max(ret, num);
            }
        }
        return ;
    }

    auto upDir = swipingUp(pos);
    auto downDir = swipingDown(pos);
    auto leftDir = swipingLeft(pos);
    auto rightDir = swipingRight(pos);

    if (upDir != pos) ckAll(cnt + 1, upDir);

    if (downDir != pos) ckAll(cnt + 1, downDir);

    if (leftDir != pos) ckAll(cnt + 1, leftDir);

    if (rightDir != pos) ckAll(cnt + 1, rightDir);
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N;
    if (N == 1) {
        int ans;
        cin >> ans;
        cout << ans << "\n"; return 0;
    }

    board.resize(N);

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int tmp; cin >> tmp;
            board[i].push_back(tmp);
        }
    }

    ckAll(0, board);

    cout << ret << "\n";
    
    return 0;
}