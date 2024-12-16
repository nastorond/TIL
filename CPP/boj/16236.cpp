/** 아기상어
 * 골드 3
 * 시뮬레이션
 */
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#define MAX_VAL 22

using namespace std;

// 필드 크기, 필드 정보
int N, fld[MAX_VAL][MAX_VAL];
vector<vector<int>> vi;
int sharkSize = 2, sharkX, sharkY;
int mv[4][2] = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pair<int, int>> candidates;
int eatingCount = 0;
int turn = 0;

// 정보 입력 함수
void InputFunc() {
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> fld[i][j];
            if (fld[i][j] == 9) {
                sharkX = i;
                sharkY = j;
            }
        }
    }
    vi.resize(N, vector<int>(N, 0));
    candidates.clear();
}

// shark growing accroding to condition
void sharkGrowing() {
    if (sharkSize == eatingCount) {
        eatingCount = 0;
        sharkSize++;
        return ;
    }
    return ;
}

// boundary condition
bool condition(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= N;
}

// moving
bool findFishes() {
    int x = sharkX, y = sharkY;
    queue<pair<int, int>> q;
    
    q.push(make_pair(x, y));
    vi[x][y] = 0;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second; q.pop();
        for (int i=0; i<4; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];
            if (condition(nx, ny) || vi[nx][ny] > 0) continue;
            if (fld[nx][ny] > sharkSize || fld[nx][ny] == 9) continue;
            
            vi[nx][ny] = vi[x][y] + 1;

            if (fld[nx][ny] < sharkSize && fld[nx][ny] > 0) {
                candidates.push_back(make_pair(nx, ny));
            }
            q.push(make_pair(nx, ny));
        }
    }

    return !candidates.empty();
}

bool compare(pair<int, int> a, pair<int, int> b) {
    if (vi[a.first][a.second] != vi[b.first][b.second]) return vi[a.first][a.second] < vi[b.first][b.second];
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

void movingShark () {
    sort(candidates.begin(), candidates.end(), compare);
    pair<int, int> pii = candidates[0];

    eatingCount++;
    sharkGrowing();
    fld[sharkX][sharkY] = 0;
    sharkX = pii.first;
    sharkY = pii.second;
    fld[pii.first][pii.second] = 9;
    turn += vi[pii.first][pii.second];

    return ;
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);

    InputFunc();

    while(1) {
        if (!findFishes()) break;
        movingShark();

        /*
        cout << "\n";
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) cout << vi[i][j] << " ";
            cout << "\n";
        }
        
        cout << "\n";
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) cout << fld[i][j] << " ";
            cout << "\n";
        }
        */

        vi.assign(N, vector<int>(N, 0));
        candidates.clear();
        
    }

    cout << turn << "\n";

    return 0;
}