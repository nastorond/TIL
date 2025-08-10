#include <iostream>

using namespace std;

int N;
char dir[100];
int dist[100];
int mv[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int ret = 0;

int get_dir(int dire)
{
    if (dire == 'N')
    {
        return 0;
    }
    else if (dire == 'E')
    {
        return 1;
    }
    else if (dire == 'S')
    {
        return 2;
    }
    else 
    {
        return 3;
    }
}

pair<int, int> moving(int x, int y, char dire, int weight)
{
    int direction = get_dir(dire);

    int dx,dy;
    for (int w=1; w <= weight; w++)
    {
        dx = x + mv[direction][0]*w;
        dy = y + mv[direction][1]*w;

        ret++;
        if (dx == 0 && dy == 0)
        {
            return make_pair(0, 0);
        }
    }
    return make_pair(dx, dy);
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> dir[i] >> dist[i];
    }

    // Please write your code here.
    pair<int, int> pii = make_pair(0, 0);
    
    for (int turn = 0; turn < N; turn++)
    {
        pii = moving(pii.first, pii.second, dir[turn], dist[turn]);

        if (pii.first == 0 && pii.second == 0)
        {
            cout << ret << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";

    return 0;
}