/** 아기상어
 * 골드 3
 * 시뮬레이션
 */
#include <bits/stdc++.h>
#define MAX_VAL 22

using namespace std;

/** 상어의 정보
 * ex 다음 레벨까지 잔여 물고기 수
 * level 상어의 레벨
 * loc_x 위치 x
 * loc_y 위치 y
 */
struct shark {
    int ex = 2;
    int level = 2:
    int loc_x;
    int loc_y;
};
// 필드 크기, 필드 정보
int N, field[MAX_VAL][MAX_VAL];
// 각 물고기의 위치와 물고기로의 방향
vector<tuple<int, int, int>> fishes;

shark baby_shark;

// 정보 입력 함수
void Input_func() {
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> field[i][j];
            if (field[i][j] == 9) {
                baby_shark.loc_x = i;
                baby_shark.loc_y = j;
                field[i][j] = 0;
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);

    Input_func();

    return 0
}