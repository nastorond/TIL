#include <iostream>
#include <vector>

using namespace std;

int T;
int N;

struct Ball
{
    char id;
    char dir;
    bool isAlive;
    int x;
    int y;
    int weight;
};
vector<Ball> balls;
vector<vector<char>> fld;
int mv[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

char get_dir(char c)
{
    if (c == 'U') return 0;
    if (c == 'D') return 1;
    if (c == 'R') return 2;
    if (c == 'L') return 3;
}

bool compare(Ball& a, Ball& b)
{
    if (a.weight == b.weight) return a.weight > b.weight;
    return a.id > b.id;
}

bool boundaryCondition(int x, int y)
{
    return x < 0 || x >= 2000 || y < 0 || y >= 2000;
}

bool simulation()
{
    bool ret = false;

    for (auto& b : balls)
    {
        if (!b.isAlive) continue;
        fld[b.x][b.y] = 0;
        b.x += mv[b.dir][0];
        b.y += mv[b.dir][1];

        char loc_id = fld[b.x][b.y];
        if (loc_id != 0 && b.id > loc_id) //! only compare id is bigger then before
        {
            if (compare(balls[loc_id], b))
            {
                b.isAlive = false;
            }
            else
            {
                balls[loc_id].isAlive = false;
                fld[b.x][b.y] = b.id;
            }
            ret = true;
        }
        else //! if id is bigger then now, that id is not moving yet
        {
            fld[b.x][b.y] = b.id;
        }
    }

    return ret;
}

int main() {
    cin >> T;
    int ret = 0;
    for (int t = 0; t < T; t++) 
    {
        fld.resize(2000, vector<char>(2000, 0));
        cin >> N;
        Ball b;
        b.isAlive = true;
        char d;

        for (int i = 0; i < N; i++) //! init balls
        {
            cin >> b.x >> b.y >> b.weight >> d;
            b.x += 1000;
            b.y += 1000;

            fld[b.x][b.y] = static_cast<char>(i);
            b.dir = get_dir(d);
            b.id = i;
            balls.push_back(b);
        }

        int max_turn = 2000; //! 양 끝 단 이 만나는 마지막 시간
        ret = -1;
        for (int turn=1; turn <= max_turn; turn++)
        {
            if (!simulation()) continue;
            ret = turn;
        }
        cout << ret << "\n";
    }

    return 0;
}