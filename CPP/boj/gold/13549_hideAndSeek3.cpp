#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 200010;
const int INF = 1e9;

int visited[MAX];

/**
* @brief 방문 안한 곳만 탐색 djikstra 활용
* @param startP 시작점
* @param endP 도착지
* @return 소요시간
*/
int bfs(const int startP, const int endP) 
{
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	int ret = -1;
	pq.push(make_pair(0, startP));
	visited[startP] = 0;

	while (!pq.empty()) 
	{
		const int now = pq.top().second;
		const int dist = pq.top().first; pq.pop();

		if (dist > visited[now]) continue;

		if (now == endP) 
		{
			ret = dist;
			break;
		}

		if (now + 1 < MAX && dist + 1 < visited[now + 1])
		{
			visited[now + 1] = dist + 1;
			pq.push(make_pair(dist + 1, now + 1));
		}

		if (now - 1 >= 0 && dist + 1 < visited[now - 1])
		{
			visited[now - 1] = dist + 1;
			pq.push(make_pair(dist + 1, now - 1));
		}

		if (now * 2 <= MAX && dist < visited[now * 2])
		{
			visited[now * 2] = dist;
			pq.push(make_pair(dist, now * 2));
		}
	}

	return ret;
}

int main() 
{
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	if (N == K) 
	{
		cout << 0 << "\n";
	}
	else
	{
		fill(visited, visited + MAX, INF);
		cout << bfs(N, K) << "\n";
	}

	return 0;
}