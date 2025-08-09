#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, m, k;
vector<vector<pair<int, int>>> gp;
priority_queue<pair<int, int>> pq;
vector<int> dist;

int main() {
    cin >> n >> m;
    cin >> k;

    gp.resize(n+1);
    dist.resize(n+1, 1e9);

    int from, to, w;
    for (int i=0; i<m; ++i)
    {
        cin >> from >> to >> w;
        gp[from].push_back(make_pair(to, w));
        gp[to].push_back(make_pair(from, w));
    }

    dist[k] = 0;
    pq.push(make_pair(0, k));

    while (!pq.empty())
    {
        int cur_loc, cur_dist;
        tie(cur_dist, cur_loc) = pq.top(); 
        pq.pop();
        cur_dist = -cur_dist;

        if (cur_dist != dist[cur_loc]) continue;

        for (auto next_info : gp[cur_loc])
        {
            int next_loc, next_dist;
            tie(next_loc, next_dist) = next_info;

            if (next_dist + cur_dist < dist[next_loc])
            {
                dist[next_loc] = next_dist + cur_dist;
                pq.push(make_pair(-dist[next_loc], next_loc));
            }
        }

    }

    for (int i=1; i<n+1; ++i)
    {
        if (dist[i] == 1e9) cout << -1 << "\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
