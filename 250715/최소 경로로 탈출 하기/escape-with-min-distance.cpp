#include <iostream>
#include <queue>

using namespace std;

int n, m;
int a[100][100];
int vi[100][100] = {0, };

bool bc(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= m;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.
    queue<pair<int, int>> q;
    int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int x, y, dx, dy;

    q.push(make_pair(0, 0));

    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second; q.pop();
        
        if (x == n-1 && y == m-1) 
        {
            cout << vi[x][y] << "\n";
            break;
        }

        for (int i=0; i<4; i++)
        {
            dx = x + mv[i][0];
            dy = y + mv[i][1];
            
            if (bc(dx, dy) || vi[dx][dy] > 0 || a[dx][dy] == 0) continue;

            q.push(make_pair(dx, dy));
            vi[dx][dy] = vi[x][y] + 1;
        }
    }

    return 0;
}
