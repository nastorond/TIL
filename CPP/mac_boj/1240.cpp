#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> gp[1000+1];
bool visited[1000+1];
int res, startNode, endNode;


void init(){
    for(int i=0; i<=1001; i++) visited[i] = false;
}


void dfs(int now, int dist){
    visited[now] = true;
    if (now==endNode){
        res = dist;
        return ;
    }
    for (int i=0;i<gp[now].size();i++){
        if (visited[gp[now][i].first] == false){
            dfs(gp[now][i].first, dist + gp[now][i].second);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n, m, u, v, w;
    cin >> n >> m;
    for(int i=0;i<n-1;i++){
        cin >> u >> v >> w;
        gp[u].push_back(make_pair(v, w));
        gp[v].push_back(make_pair(u, w));
    }
    for(int i=0;i<m;i++){
        cin >> startNode >> endNode;
        init();
        dfs(startNode, 0);
        cout << res << "\n";
    }

    return 0;
}