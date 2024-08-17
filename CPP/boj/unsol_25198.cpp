// 곰곰이의 심부름
#include <iostream>
#include <vector>
#define MAX_VAL 100002

using namespace std;

int n, s, c, h;
vector<int> gp[MAX_VAL];
int visited[MAX_VAL] = {};

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    // input
    cin >> n;
    cin >> s >> c >> h;

    // init
    for (int i=0; i<n; i++) {
        gp[i].clear();
    }

    for (int i=0; i<n; i++) {
        int u, v;
        cin >> u >> v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }

    

    return 0;
}