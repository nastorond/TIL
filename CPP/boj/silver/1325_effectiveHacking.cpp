#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> gp[10000 + 1];
bool visited[10000 + 1];
int ans[10000 + 1];

void init(int n){
    for(int i=0; i<=n; i++){
        visited[i] = false;
    }
}

int bfs(int start, int cnt) {
	queue<int> q;
	q.push(start);
	visited[start] = start;
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < gp[tmp].size(); i++) {
			if (visited[gp[tmp][i]] == false) {
				q.push(gp[tmp][i]);
				visited[gp[tmp][i]] = true;
                ++cnt;
			}
		}
	}
    return cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		gp[u].push_back(v);
	}
    
    int res = -1;
    int tmp;
	for (int i = 1; i <= n; i++) {
        init(n);
        tmp = bfs(i, 0);
        ans[i] = tmp;
        res = max(tmp, res);
	}

    for(int i=1; i<=n; i++){
        if(ans[i] == res){
            cout << i << " ";
        }
    }

	return 0;
}