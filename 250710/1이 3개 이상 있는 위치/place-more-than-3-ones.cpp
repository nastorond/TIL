#include <iostream>

using namespace std;

int n;
int grid[100][100];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool boudaryCondition(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= n;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int x, y, dx, dy, cnt;
    int ret = 0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            x = i; y = j;
            cnt = 0;
            for (int i=0; i<4; i++)
            {
                dx = x + dir[i][0];
                dy = y + dir[i][1];
                if (!boudaryCondition(dx, dy) && grid[dx][dy] > 0)
                {
                    cnt++;
                }
            }
            if (cnt > 2)
            {
                ret++;
            }
        }
    }

    cout << ret << "\n";

    return 0;
}