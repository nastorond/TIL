#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[11];
int scores[11];
int n;

void dfs(){
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> scores[i+1];
    }

    for(int i=0;i<n;i++){
        int cnt;
        cin >> cnt;
        for(int j=0; j<cnt; j++){
            int a;
            cin >> a;
            graph[i].push_back(a);
            graph[a].push_back(i);
        }
    }
    int visited[11];
}