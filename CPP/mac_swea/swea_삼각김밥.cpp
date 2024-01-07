#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAX_VAL 10001

using namespace std;

int s, e, res;
vector<int> piramid[MAX_VAL];
bool visited[MAX_VAL];

void init (){
    // for (int i=0; i<MAX_VAL; i++) {
    //     visited[i] = false;
    // }
    memset(visited, false, sizeof(visited));
}

void make_piramid () {
    int flr=2;
    int left = 2;
    int right = 3;
    int num = 2;
    int cnt = 0;
    int pre_left = 1;
    int pre_right = 1;

    while (num < MAX_VAL) {
        if (num == left) {
            piramid[num].emplace_back(pre_left);
            piramid[pre_left].emplace_back(num);
            pre_left = left;
            left += flr;
        }
        else if (num == right) {
            piramid[num].emplace_back(pre_right);
            piramid[num].emplace_back(num-1);
            piramid[pre_right].emplace_back(num);
            piramid[num-1].emplace_back(num);
            pre_right = right;
            right += flr + 1;
        }
        else {
            piramid[num].emplace_back(num-flr);
            piramid[num].emplace_back(num-flr+1);
            piramid[num-flr].emplace_back(num);
            piramid[num-flr+1].emplace_back(num);
            piramid[num].emplace_back(num-1);
            piramid[num-1].emplace_back(num);
        }
        num++;
        cnt++;
        if (cnt == flr) {
            cnt = 0;
            flr++;
        }
    }

}

void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(s, 0));
    visited[s] = true;

    while (!q.empty()) {
        int now = q.front().first;
        int value = q.front().second;
        q.pop();

        if (now == e) {
            res = value;
        }

        for (int i=0; i<piramid[now].size(); i++) {
            int next = piramid[now][i];
            if (next < MAX_VAL && visited[next] == false) {
                visited[next] = true;
                q.push(make_pair(next, value+1));
            }
        }
    }
}

int main() {
    int test_case;
    cin >> test_case;

    make_piramid();

    for (int tc=1; tc<=test_case; tc++) {
        cin >> s >> e;
        init();
        bfs();
        cout << "#" << tc << " " << res << "\n";
    }

    return 0;
}