#include <iostream>
#include <queue>
#define pii pair<int, int>

using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];
bool vi[100][100] = {false, };

bool boundaryCondition(int x, int y)
{
    return x < 0 || x>= n || y < 0 || y >= n;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cin >> grid[i][j];
    }

    queue<pii> q;
    int x, y;
    int ret = 0;

    for (int i = 0; i < k; i++) 
    {
        cin >> x >> y;
        x--;
        y--;
        vi[x][y] = true;
        q.push(make_pair(x, y));
        ret++;
    }

    // Please write your code here.
    int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dx, dy;

    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second; q.pop();
        for (int i=0; i<4; i++)
        {
            dx = x + mv[i][0];
            dy = y + mv[i][1];
            if (!boundaryCondition(dx, dy) && !vi[dx][dy] && grid[dx][dy] == 0)
            {
                q.push(make_pair(dx, dy));
                vi[dx][dy] = true;
                ret++;
            }
        }
    }

    cout << ret << "\n";

    return 0;
}
