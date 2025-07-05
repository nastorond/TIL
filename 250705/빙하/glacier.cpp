#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int, int>

using namespace std;

int N, M;
int a[200][200];
int mv[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<bool>> vi;

//! 시뮬레이션 종료 조건
int condition()
{
    int res = 0;
    //! 빙하만 체크
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            if (a[i][j] > 0) res++;
        }
    }

    return res;
}

bool boundaryCondition(int x, int y)
{
    return x < 0 || x >= N || y < 0 || y >=M;
}

void simulation()
{

    queue<pii> q;
    q.push(make_pair(0,0));
    vi[0][0] = true;
    int x, y, dx, dy;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second; q.pop();

        for (int i=0; i<4; i++)
        {
            dx = x + mv[i][0];
            dy = y + mv[i][1];
            if (boundaryCondition(dx, dy)) continue;
            if (vi[dx][dy]) continue;

            if (a[dx][dy] == 0) //! 물인 경우만 q push
            {
                q.push(make_pair(dx, dy));
            }
            vi[dx][dy] = true; //! 빙하와 물 표시
        }
    }
}

void meltDown()
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            if (a[i][j] > 0 && vi[i][j])
            {
                a[i][j]--; //! 빙하 녹음
            }
            vi[i][j] = false; //! 방문배열 초기화
        }
    }
}

int main() {
    cin >> N >> M;
    vi.resize(N, vector<bool>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.
    //! 0,0 부터 도달 가능한 부분 전부 찾고 맞닿는 빙하 체크
    //! 찾은 빙하 전부 -1 씩
    //! 내부에 있는 물은 녹는데 영향을 주지 않으므로 무시

    int ret = condition();
    int turn = 0;
    while (true)
    {
        turn++;
        simulation();
        meltDown();

        // for (int i=0; i<N; i++)
        // {
        //     for (int j=0; j<M; j++) cout << a[i][j] << " ";
        //     cout << "\n";
        // }

        int tmp = condition();
        if (tmp == 0)
        {
            break;
        }
        ret = tmp;
    }

    cout << turn << " " << ret << "\n";

    return 0;
}
