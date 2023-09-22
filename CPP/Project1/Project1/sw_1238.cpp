#include <iostream>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;

vector<int> graph[MAX];
int depth[MAX];

void init(){
	for (int i = 1; i < MAX; i++) {
		graph[i].clear();
		depth[i] = 0;
	}
}
void bfs(int start) {
	queue<int> q;
	q.push(start);
	depth[start] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < graph[v].size(); i++) {
			int next = graph[v][i];
			if (depth[next] == 0) {
				depth[next] = depth[v] + 1;
				q.push(next);
			}
		}
	}
}
int main(int argc, char** argv) {
	int T = 10;
	for (int tc = 1; tc <= T; ++tc) {
		int e, start;
		cin >> e >> start;
		init();

		for (int i = 0; i < e / 2; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
		}

		bfs(start);

		int lastVisited = 0;
		for (int i = 1; i < MAX; i++) {
			if (depth[i] >= depth[lastVisited]) {
				lastVisited = i;
			}
		}
		cout << "#" << tc << " " << lastVisited << "\n";
	}
	return 0;
}