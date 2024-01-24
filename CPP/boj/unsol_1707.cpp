// boj 1707 이분 그래프
#include <iostream>
#include <vector>
#define endl "\n"
#define MAX_VERTEX 20001

using namespace std;

vector<int>* gp = new vector<int>[MAX_VERTEX];
char visited[MAX_VERTEX];
int vertex, e;

void solution() {
    for (int i=1; i<=vertex; i++) {
        for (int j=0; j<gp[i].size(); j++) {
            cout << gp[i][j] << " ";
        }
        cout << endl;
    }
}

void input() {
    cin >> vertex >> e;
    
    // init
    for (int i=1; i<=vertex; i++) {
        gp[i].clear();
        visited[i] = 0;
    }

    for (int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    for (int tc=1; tc<=test_case; tc++) {
        input();
        solution();
    }
    return 0;
}