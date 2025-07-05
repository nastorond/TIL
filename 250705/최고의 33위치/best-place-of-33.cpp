#include <iostream>

using namespace std;

int N;
int grid[20][20];

int calc(int x, int y)
{
    int res = 0;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            res += grid[x + i][y + j];
        }
    }

    return res;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int limitBoundaty = N - 3 + 1;
    int ret = -1;
    for (int i=0; i<limitBoundaty; i++)
    {
        for (int j=0; j<limitBoundaty; j++)
        {
            ret = max(ret, calc(i,j));
        }
    }

    cout << ret << "\n";
    
    return 0;
}
