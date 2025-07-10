#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//! 입력값. 격자 크기, 팀 수, 턴 수
int n, m, k;
//! 전체 스코어의 합
int score = 0;
//! moving index
int mv[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//! 각 팀의 머리 사람 위치(n-1), 꼬리사람 위치(n*2 - 1)
vector<pair<int, int>> infos;
vector<vector<int>> fld; //! 게임 필드
vector<vector<bool>> vi; //! 방문 배열
vector<vector<int>> person_fld;

//! 필드 확인
void debug_func()
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << fld[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "---------------------------------------" << "\n";

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << person_fld[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "---------------------------------------" << "\n";

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << vi[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "---------------------------------------" << "\n";
}

//! 경계조건
bool boundary_condition(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= n;
}

//! 머리부터 꼬리까지 탐색하며 한칸씩 이동
void finding_tail(pair<int, int> hd, int team_num)
{
    int x = hd.first;
    int y = hd.second;
    vi[x][y] = true;
    queue<pair<int, int>> q;
    q.push(hd);
    int cnt = 1;

    int dx, dy;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second; q.pop();
        int val = fld[x][y];

        for (int i=0; i<4; i++)
        {
            dx = x + mv[i][0];
            dy = y + mv[i][1];

            if (!boundary_condition(dx, dy) && vi[dx][dy] == false && fld[dx][dy] > 0)
            {
                if (fld[dx][dy] == 2 && val == 3)
                {
                    fld[dx][dy] = 3;
                    fld[x][y] = 4;
                    infos[team_num + n] = make_pair(dx, dy);
                    person_fld[dx][dy] = cnt;
                    return ;
                }
                else if (val == 1 && fld[dx][dy] == 4)
                {
                    fld[dx][dy] = 1;
                    fld[x][y] = 2;
                    person_fld[dx][dy] = 1;
                    person_fld[x][y] = 2;
                    
                    q.push(make_pair(dx, dy));
                    vi[dx][dy] = true;
                    cnt = 3;
                }
                else if (fld[dx][dy] == 4)
                {
                    person_fld[dx][dy] = 4;
                    vi[dx][dy] = true;
                }
                else 
                {
                    person_fld[dx][dy] = cnt;
                    q.push(make_pair(dx, dy));
                    vi[dx][dy] = true;
                    cnt++;   
                }
            }
        }
    }
}

//! 머리 사람을 따라 한칸 전진
void moving()
{
    for (int i=0; i<m; i++)
    {
        finding_tail(infos[i], i);
    }
}

//! 공이 날아올 위치와 최초 피격인
//! 시작 행, 열
void ball_loc_find_hitted(int turn)
{
    int raw, col;
    int limit_line = n * 4;

    int loc = turn % limit_line;

    if (loc < n)
    {
        raw = loc;
        col = 0;

        for (int i=0; i < n; i++)
        {
            if (person_fld[raw][i] > 0)
            {
                score += (person_fld[raw][i]) * (person_fld[raw][i]);
                return ;
            }
        }
    }
    else if (n <= loc && loc < 2*n)
    {
        raw = n-1;
        col = loc%4;

        for (int i=n-1; i >= 0; i--)
        {
            if (person_fld[i][col] > 0)
            {
                score += (person_fld[i][col]) * (person_fld[i][col]);
                return ;
            }
        }
    }
    else if (2*n < loc && loc < 3*n)
    {
        raw = 3 * n - loc - 1;
        col = n-1;

        for (int i=n-1; n >= 0; i--)
        {
            if (person_fld[raw][i] > 0)
            {
                score += (person_fld[raw][i]) * (person_fld[raw][i]);
                return ;
            }
        }
    }
    else 
    {
        raw = 0;
        col = 4 * n - loc - 1;

        for (int i=0; i < n; i++)
        {
            if (person_fld[i][col] > 0)
            {
                score += (person_fld[i][col]) * (person_fld[i][col]);
                return ;
            }
        }
    }

    return ;
}

//! 뒤로 돌기
void turning_back()
{
    for (int i=0; i<m; i++)
    {
        infos[i] = infos[n+i]; //! 꼬리 머리 교채
    }
}

int main() {
    // Please write your code here.
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m >> k;
    fld.resize(n, vector<int>(n, 0));
    infos.reserve(10);

    int tmp = 0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin >> fld[i][j];
            if (fld[i][j] == 1)
            {
                infos[tmp] = make_pair(i,j); 
                tmp++;
            }
        }
    }

    for (int turn = 0; turn<k; turn++)
    {
        vi.resize(n, vector<bool>(n, false));
        person_fld.resize(n, vector<int>(n, 0));
        moving();

        cout << "after moving\n"; 
        debug_func();

        ball_loc_find_hitted(turn);
        turning_back();

        cout << "after turnning back\n"; 
        debug_func();
    }

    cout << score << "\n";

    return 0;
}