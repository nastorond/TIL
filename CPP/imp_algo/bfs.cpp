#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[10001];
bool visited[10001];

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int i=0; i< graph[tmp].size(); i++){
            int node = graph[tmp][i];
            if (visited[node] == false){
                q.push(node);
                visited[node] = true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n, m;
    // vector<int> graph[n+1];
    // bool visited[n+1];
    cin >> n >> m;
    fill(visited, visited+n+1, false);

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int res = 0;
    for(int i=1; i<n+1; i++){
        if (visited[i] == false){
            bfs(i);
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}
