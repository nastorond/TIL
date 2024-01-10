// 맥주 마시면서 걸어가기
#include <iostream>
#include <vector>
#include <queue>
#define MAX_VAL 101

using namespace std;

int n, end_x, end_y;
bool flg;
bool visited[MAX_VAL];
vector<pair<int, int>> con_info;

/*
거리 계산 식
dx + dy
최대 진행 가능 거리 1000
*/

void dfs(int now_x, int now_y) {
    // 수정 필요
    if (abs(now_x - end_x) + abs(now_y-end_y) <= 1000) {
        flg = true;
        return ;
    }

    for (int i=0; i<con_info.size(); i++) {
        if (!visited[i] && !flg) {
            int dx, dy;
            if (now_x * con_info[i].first < 0) {
                dx = abs(now_x + con_info[i].first);
            }
            else dx = abs(now_x - con_info[i].first);
            if (now_y * con_info[i].second < 0) {
                dy = abs(now_y + con_info[i].second);
            }
            else dy = abs(now_y - con_info[i].second);

            if (dx + dy <= 1000) {
                visited[i] = true;
                dfs(con_info[i].first, con_info[i].second);
                visited[i] = false; 
            }
        }
    }
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    while (!q.empty()) {
        
    }
}

void init () {
    con_info.clear();
    flg = false;
    for (int i=0; i<=n; i++) {
        visited[i] = false;
    }
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int test_case;

    cin >> test_case;
    for (int tc=1; tc<=test_case; tc++) {
        int start_x, start_y;

        // init
        init();

        // input
        cin >> n;
        cin >> start_x >> start_y;
        int tmp_x, tmp_y;
        for (int i=0; i<n; i++) {
            cin >> tmp_x >> tmp_y;
            con_info.push_back(make_pair(tmp_x, tmp_y));
        }
        cin >> end_x >> end_y;

        dfs(start_x, start_y);

        // output
        if (flg) cout << "happy" << "\n";
        else cout << "sad" << "\n";
    }

    return 0;
}