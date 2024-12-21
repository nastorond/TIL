#include<iostream>

using namespace std;

int main (){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int cost[3];
    int houses[1001][3];
    int n;
    houses[0][0] = 0;
    houses[0][1] = 0;
    houses[0][2] = 0;

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> cost[0] >> cost[1] >> cost[2];
        // 현재 위치에서 가능한 가장 최소한의 값으로 갱신
        houses[i][0] = min(houses[i-1][1], houses[i-1][2]) + cost[0];
        houses[i][1] = min(houses[i-1][0], houses[i-1][2]) + cost[1];
        houses[i][2] = min(houses[i-1][0], houses[i-1][1]) + cost[2];
    }
    cout << min(min(houses[n][0], houses[n][1]), houses[n][2]) << "\n";
}