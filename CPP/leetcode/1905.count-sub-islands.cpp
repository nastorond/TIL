/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> visited;
    vector<vector<bool>> visit;

    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    int n, m;

    bool condition (int x, int y) {
        return x < 0 || x >= n || y < 0 || y >=m;
    }

    int bfs (int x, int y, int mark, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int res = 1;

        q.push(make_pair(x, y));
        visited[x][y] = mark;

        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second; q.pop();
            for (int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (condition(nx, ny) || grid[nx][ny] == 0 || visited[nx][ny] > 0) continue;
                q.push(make_pair(nx, ny));
                visited[nx][ny] = mark;
                res++;
            }
        }
        return res;
    }

    vector<int> findAns(int x, int y, int lim, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<int> v(lim, 0);
        
        q.push(make_pair(x, y));
        visit[x][y] = true;
        v[visited[x][y]]++;

        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second; q.pop();
            
            for (int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (condition(nx, ny) || visit[nx][ny]) continue;
                q.push(make_pair(nx, ny));
                visit[nx][ny] = true;
                if (visited[nx][ny] == 0 || grid[nx][ny] == 0) continue;
                v[visited[nx][ny]]++;
            }
        }
        
        return v;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size(); m = grid1[0].size(); int num=1, ret=0;
        
        visited.resize(n, vector<int>(m, 0));
        visit.resize(n, vector<bool>(m, false));
        
        unordered_map<int, int> memo;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (visited[i][j] == 0 && grid2[i][j] > 0) {
                    int cnt = bfs(i, j, num, grid2);
                    memo[num] = cnt;
                    num++;
                    cnt=0;
                }
            }
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!visit[i][j] && grid1[i][j] > 0 && grid2[i][j] > 0) {
                    vector<int> tmp = findAns(i, j, num, grid1);
                    for (int i=1; i<num; i++) {
                        if (tmp[i] == memo[i]) ret++;
                    }
                }
            }
        }

        return ret;
    }
};
// @lc code=end

