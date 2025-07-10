#include <iostream>

using namespace std;

int N, M;
int r[10000], c[10000];
int fld[101][101];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

bool boundary(int x, int y)
{
    return x < 0 || x >= N || y < 0 || y >= N;
}

int solution(int x, int y)
{
    int dx, dy;
    int ret = 0;
    for (int i=0; i<4; i++)
    {
        dx = x + dir[i][0];
        dy = y + dir[i][1];
        if (!boundary(dx, dy) && fld[dx][dy] > 0)
        {
            ret++;
        }
    }

    if (ret == 3) return 1;
    return 0;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> r[i] >> c[i];
    }

    // Please write your code here.
    if (N < 2)
    {
        for (int i=0; i<M; i++)
        {
            cout << 0 << "\n";
        }
        
        return 0;
    }

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++) fld[i][j] = 0;
    } 

    for (int i=0; i<M; i++)
    {
        fld[r[i]-1][c[i]-1] = 1;
        cout << solution(r[i]-1, c[i]-1) << "\n";
    }

    return 0;
}