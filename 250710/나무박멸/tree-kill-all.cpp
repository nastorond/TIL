#include <iostream>
#include <vector>

using namespace std;

int n, m, k, c;
int ret = 0;
int fld[20][20];
int anti[20][20];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int dia[4][2] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

void debug_print()
{
    cout << "-------------- fld -------------\n";
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << fld[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "-------------- anti -------------\n";
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << anti[i][j] << " ";
        }
        cout << "\n";
    }
}

void init()
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            fld[i][j] = 0;
            anti[i][j] = 0;
        }
    }
}

void input_fld()
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin >> fld[i][j];
        }
    }
}

bool boundaryCondition(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= n;
}

void grow_up_and_duplicated()
{
    int dx, dy, background, cnt;
    vector<pair<int, int>> tmp_v;
    bool candidates[20][20] = {false, };

    //! grow up
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (fld[i][j] <= 0) continue;

            cnt = 0;
            for (int idx=0; idx<4; idx++)
            {
                dx = i + dir[idx][0];
                dy = j + dir[idx][1];
                if (boundaryCondition(dx, dy) || fld[dx][dy] < 0) continue;

                if (fld[dx][dy] == 0)
                {
                    candidates[dx][dy] = true;
                    continue;
                }

                cnt++;
            }

            fld[i][j] += cnt;
        }
    }
    
    //! duplicate
    int tmp_fld[20][20] = {0, };
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (fld[i][j] == -1)
            {
                tmp_fld[i][j] = -1;
                continue;
            }
            if (fld[i][j] == 0) continue;

            tmp_fld[i][j] = fld[i][j];

            for (int idx=0; idx<4; idx++) //! find blanks
            {
                dx = i + dir[idx][0];
                dy = j + dir[idx][1];
                if (!boundaryCondition(dx, dy) && anti[dx][dy] == 0 && candidates[dx][dy])
                {
                    tmp_v.push_back(make_pair(dx, dy));
                }
            }

            if (tmp_v.size() == 0) continue;

            background = fld[i][j] / tmp_v.size();
            for (auto pii : tmp_v) //! duplicate tree
            {
                tmp_fld[pii.first][pii.second] += background;
            }

            tmp_v.clear();
        }
    }

    swap(fld, tmp_fld);
}

void spray_anits(int x, int y)
{
    int dx, dy;
    anti[x][y] = c + 1;
    fld[x][y] = 0;

    for (int i=0; i<4; i++) //! 4 of directions
    {
        for (int j=1; j <= k; j++) //! how many times to go
        {
            dx = x + dia[i][0]*j;
            dy = y + dia[i][1]*j;
            if (boundaryCondition(dx, dy)) continue; //! out of bounds
            if (fld[dx][dy] < 0) break; //! can't go anymore

            fld[dx][dy] = 0;
            anti[dx][dy] = c + 1;
        }
    }
}

void anti_weeds()
{
    int max_weed = 0;
    int dx, dy, cnt;
    pair<int, int> candidate_tree = make_pair(0, 0);

    for (int x=0; x<n; x++)
    {
        for (int y=0; y<n; y++)
        {
            if (fld[x][y] < 1) continue;

            //! counting trees
            cnt = fld[x][y];
            for (int i=0; i<4; i++) //! 4 of directions
            {
                for (int j=1; j <= k; j++) //! how many times to go
                {
                    dx = x + dia[i][0]*j;
                    dy = y + dia[i][1]*j;
                    if (boundaryCondition(dx, dy)) continue; //! out of bounds
                    if (fld[dx][dy] < 0) break; //! can't go anymore

                    cnt += fld[dx][dy];
                }
            }

            if (cnt > max_weed) //! if find more trees
            {
                max_weed = cnt; //! refresh infos
                candidate_tree = make_pair(x, y);
            }
        }
    }

    ret += max_weed; //! sum result
    spray_anits(candidate_tree.first, candidate_tree.second); //! spary
}

void turn_going()
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (anti[i][j] > 0)
            {
                anti[i][j]--;
            }
        }
    }
}

int main() {
    // Please write your code here.
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m >> k >> c;

    init();
    input_fld();

    while (m--)
    {
        grow_up_and_duplicated();
        debug_print();

        anti_weeds();
        turn_going();

        debug_print();
    }

    cout << ret << "\n";

    return 0;
}