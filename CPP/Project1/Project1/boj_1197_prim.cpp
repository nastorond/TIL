#include <iostream>
#include <queue>
#include <functional>

#define MAX 10005

using namespace std;
using ti3 = tuple<int, int, int>;

int v, e;

vector<pair<int, int>>adj[MAX];
bool check[MAX];

long long Prim() {
	int cnt = 0;
	long long tot = 0; // MST 

	priority_queue<ti3, vector<ti3>, greater<ti3>>heap;
	for (auto next : adj[1]) {
		heap.push({ next.first, 1, next.second });
	}
	check[1] = 1;

	while (1) {
		int cost, v1, v2;
		tie(cost, v1, v2) = heap.top();
		heap.pop();
		if (check[v2])continue;

		check[v2] = 1;
		cnt++;
		tot += cost;
		if (cnt == v - 1) break;
		for (auto next : adj[v2]) {
			if (check[next.second])continue;
			heap.push({ next.first, v1, next.second });
		}
	}

	return tot;
}

int main() {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back({ cost, to });
		adj[to].push_back({ cost, from });
	}
	long long ans = Prim();

	cout << ans;

	return 0;
}