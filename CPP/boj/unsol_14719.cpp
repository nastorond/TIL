// boj 14719 빗물 골드?
#include <iostream>
#define MAX_VAL 502

using namespace std;

/**
 * 바닥은 막혀있다고 봐도 무방 => 0은 무조건 최대값 +
 * 한 쪽 부터 가면서, 벽의 높이를 측정하며 비가 고일 지점을 더해가면서 나아가면 될듯.
 * 높은 벽은 저장해서 넘기고, 낮은 벽은 더해가면서 진행
 * 중간에 높았던 벽을 하나 저장해 둬서 그 값과 비교
 * 바닥은 벽이 없으므로 그냥 지나간다
*/

int H, W;
int walls[MAX_VAL]

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> H >> W;
    for (int i=0; i<W; i++) {
        cin >> walls[i];
    }

    return 0;
}