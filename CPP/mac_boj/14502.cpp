// 14502 연구소
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int gp[9][9];
int visited[9][9];
vector<pair<int, int>> virus[11];

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    // input
    cin >> n >> m;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> gp[i][j];
            visited[i][j] = 0;
            if (gp[i][j] == 2) {
                virus->push_back(make_pair(i,j));
                cnt++;
            }
        }
    }
    
    return 0;
}