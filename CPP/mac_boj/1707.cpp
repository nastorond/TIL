#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int visited[20000+1];
vector<int> gp[20000+1];
bool res;

void init(int n){
    for(int i=1; i<=n; i++){
        visited[i]=-1;
        gp[i].clear();
        res = true;
    }
}

void dfs(int start){
    visited[start] = start;
    for(int i=0; i<gp[start].size();i++){
        int tmp = gp[start][i];
        if (visited[tmp]==-1){
            if(visited[start] == 1) visited[tmp]=2;
            if(visited[start] == 2) visited[tmp]=1;
            dfs(tmp);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int k, edges, vertexes, u, v;
    cin >> k;

    for(int tc=0; tc<k; tc++){
        cin >> vertexes >> edges;
        init(vertexes);

        for(int i=0; i<edges; i++){
            cin >> u >> v;
            gp[u].push_back(v);
            gp[v].push_back(u);
        }
        
        for(int i=1; i<=vertexes; i++){
            if(visited[i] == -1){
                visited[i] = 1;
                dfs(i);
            }
        }
        if(res==false) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}