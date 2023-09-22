#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, pair<int, int>> T;

int V,E;
vector<T> v;
int parents[100000 + 1];
int ans;

int find_set(int x){
    if (parents[x] == x) return x;
    return parents[x] = find_set(parents[x]);
}

void union_sets(int x, int y){
    x = find_set(x);
    y = find_set(y);

    if (x==y) return ;

    if(x<y){
        parents[y] = x;
    }else{
        parents[x] = y;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E;
    for (int i=0; i<E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
        // cout << a << b << c << "\n";
    }
    sort(v.begin(), v.end());
    for(int i=1;i<=V;i++){
        parents[i] = i;
    }

    int cnt = 0;
    int last = 0;

    for (int i=0; i < v.size(); i++){
        // cout << ans << "\n";
        T curEdge = v[i];

        int cost = curEdge.first;
        int now = curEdge.second.first;
        int next = curEdge.second.second;

        if (find_set(now) != find_set(next)){
            union_sets(now, next);
            ans += cost;
            last = cost;

            if (++cnt == V-1) break;
        }
    }
    cout << ans - last << "\n";
    return 0;
}