#include <iostream>
#include <vector>

using namespace std;

int n, m, t;
vector<vector<int>> fld;
vector<vector<int>> balls;
vector<vector<int>> copy_balls;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool boundary_condition(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= n;
}

void moving_ball(int x, int y)
{
    int ret = 0;
    int max_val = 0;
    int tmp_val;

    for (int i=0; i<4; ++i)
    {
        if (boundary_condition(x+dir[i][0], y + dir[i][1])) continue;
        tmp_val = fld[x + dir[i][0]][y + dir[i][1]];

        if (tmp_val > max_val)
        {
            max_val = tmp_val;
            ret = i;
        }
    }

    balls[x][y] = 0;
    copy_balls[x + dir[ret][0]][y + dir[ret][1]] += 1;
}

void simul()
{
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            if (balls[i][j] == 1) moving_ball(i, j);

            if (balls[i][j] > 1) balls[i][j] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m >> t;
    fld.resize(n, vector<int>(n, 0));
    balls.resize(n, vector<int>(n, 0));
    copy_balls.resize(n, vector<int>(n, 0));

    // input field conditions
    for (int i=0;i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            cin >> fld[i][j];
        }
    }

    // input balls first locations
    int x, y;
    for (int i=0; i<m; ++i)
    {
        cin >> x >> y;
        --x; --y;
        balls[x][y] = 1;
    }

    // simulation
    for (int turn = 0; turn < t; ++turn)
    {
        copy_balls.assign(n, vector<int>(n, 0));

        simul();

        swap(balls, copy_balls); // copy result
    }

    int ret = 0;
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            if (balls[i][j] > 1) continue;
            ret += balls[i][j];
        }
    }

    cout << ret << "\n";

    return 0;
}