#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 53

using namespace std;

vector<vector<int>> tree;
int N;

bool compare(int a, int b) {
    return a > b;
}

int dfs (int cur) {
    vector<int> list;

    if (tree[cur].size() == 0) return 0;

    for (int i=0; i<tree[cur].size(); i++) {
        int tmp = dfs(tree[cur][i]);
        list.push_back(tmp);
    }
    sort(list.begin(), list.end(), compare);
    

    int res = 0;
    for (int i=0; i<list.size(); i++) {
        res = max(res, list[i] + i+1);
    }

    // cout << "현재 노드 " <<  cur << "\n";
    // for (auto it = list.begin(); it != list.end(); it++) {
    //     cout << *it << " ";
    // }
    // cout << "\n예측 결과 " << res << "\n" << "\n";

    return res;
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    
    cin >> N;
    tree.resize(N);

    int par_num;
    cin >> par_num;
    for (int i=1; i<N; i++) {
        cin >> par_num;
        tree[par_num].push_back(i);
    }

    if (N == 1) {
        cout << 0 << "\n";
    }
    else {
        int tmp = dfs(0);
        cout << tmp << "\n";
    }

    return 0;
}