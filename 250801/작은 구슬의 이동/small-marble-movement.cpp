#include <iostream>

using namespace std;

int n, t;
int r, c;
char d;

// north, east, south, west
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

pair<int, int> moving(char dir)
{
    if (dir == 'U') return make_pair(1, 0);
    else if (dir == 'D') return make_pair(-1, 0);
    else if (dir == 'R') return make_pair(0, 1);
    else return make_pair(0, -1);
}

char changedir(char dir)
{
    if (dir == 'U') return 'D';
    else if (dir == 'D') return 'U';
    else if (dir == 'R') return 'L';
    else return 'R';
}

bool boundaryCondition(int x, int y)
{
    return x < 1 || x > n || y < 1 || y > n;
}

int main() {
    cin >> n >> t;
    cin >> r >> c >> d;

    // Please write your code here.
    for (int i=0; i<t; ++i)
    {
        int dx, dy;
        pair<int, int> tmp = moving(d);
        dx = r + tmp.first;
        dy = c + tmp.second;

        if (boundaryCondition(dx ,dy))
        {
            d = changedir(d);
        }
        else
        {
            r = dx;
            c = dy;
        }
    }

    cout << r << " " << c << "\n";

    return 0;
}