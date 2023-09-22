#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, pair<int, int>> T;

int V, E;
vector<T> v;
int parents[100000 + 1];
int ans;

int findSet(int x){
    if (x == parents[x]) return x;
    return parents[x] = findSet(parents[x]);
}
void unionSet(int x, int y){
    x = findSet(x);
    y = findSet(y);
    
    if (x == y) return ;

    if (x<y){
        parents[y] = x;
    }else{
        parents[x] = y;
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E;
    for(int i=0; i<E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    sort(v.begin(), v.end());
    for(int i=1; i<=V; i++){
        parents[i] = i;
    }

    int cnt = 0;
    int last = 0;

    for(int i=0; i<v.size(); i++){
        T curEdge = v[i];

        int cost = curEdge.first;
        int now = curEdge.second.first;
        int next = curEdge.second.second;

        if (findSet(now) != findSet(next)){
            unionSet(now, next);
            ans += cost;
            last = cost;

            if (++cnt == V-1) break;
        }
    }
    cout << ans - last << "\n";
    return 0;
}