#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int T;
int N;

struct Ball
{
    bool isAlive;
    int id;
    int dir;
    int x;
    int y;
    int weight;
};
vector<Ball> balls;

int mv[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

char get_dir(char c)
{
    if (c == 'U') return 0;
    if (c == 'D') return 1;
    if (c == 'R') return 2;
    if (c == 'L') return 3;
}


int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N;

        Ball b;
        char d;
        for (int i = 0; i < N; i++) {
            cin >> b.x >> b.y >> b.weight >> d;
            b.id = i;
            b.dir = get_dir(d);
            balls.push_back(b);
        }
        
        int ret;
        for (int turn=1; turn<=4000; turn++)
        {
            
            ret = turn*2;
        }
    }

    return 0;
}