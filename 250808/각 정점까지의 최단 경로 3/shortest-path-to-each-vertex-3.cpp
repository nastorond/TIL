#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
};

int n, m;
vector<vector<pair<int,int>>> graph;
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

int main() {
    cin >> n >> m;

    graph.resize(n+1);
    dist.resize(n+1, 1e9);

    int from, to, w;
    for (int i=0; i<m; ++i)
    {
        cin >> from >> to >> w;
        graph[from].push_back(make_pair(to, w));
    }

    dist[1] = 0;
    pq.push(make_pair(1, 0));
    while (!pq.empty())
    {
        int cur = pq.top().first;
        int cur_dist = pq.top().second; pq.pop();

        for (auto next : graph[cur])
        {
            int next_node = next.first;
            int next_weight = next.second;

            if (dist[next_node] > cur_dist + next_weight)
            {
                dist[next_node] = cur_dist + next_weight;
                pq.push(make_pair(next_node, dist[next_node]));
            }
        }
    }
    
    for (int i=2; i<n+1; ++i)
    {
        if (dist[i] == 1e9) cout << -1 << "\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
