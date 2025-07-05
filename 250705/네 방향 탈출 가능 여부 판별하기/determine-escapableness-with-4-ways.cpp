#include <iostream>
#include <queue>
#define pii pair<int, int>

using namespace std;

int n, m;
int a[100][100];

bool vi[100][100] = {false, };
int mv[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool boundaryCondition(int x, int y)
{
    return x < 0 || x >=n || y < 0 || y >= m;    
}

void printVisited()
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout << vi[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.
    queue<pii> q;
    int x, y, dx, dy;
    int ret = 0;
    vi[0][0] = true;
    q.push(make_pair(0, 0));

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second; q.pop();

        if (x == n-1 && y == m-1)
        {
            ret = 1;
            break;
        }

        for (int i=0; i<4; i++)
        {
            dx = x + mv[i][0];
            dy = y + mv[i][1];
            if (!boundaryCondition(dx, dy) && !vi[dx][dy] && a[dx][dy] == 1)
            {
                q.push(make_pair(dx, dy));
                vi[dx][dy] = true;
            }
        }
    }

    //! printVisited();
    cout << ret << "\n";

    return 0;
}
