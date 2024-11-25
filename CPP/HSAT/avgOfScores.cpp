// Level 3
#include<iostream>
#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
    int nums[1000001];
    int N, K, st, ed, tmp, a, b;
    double number = 0;

    cout << fixed;
    cout.precision(2);
    
    cin >> N >> K;
    
    st = 1; ed = N;
    for (int i=1; i<=N; i++) {
        cin >> tmp;
        number += tmp;
        nums[i] = tmp;
    }

    /** Main Idea
     * 전체 합을 구해놓은 뒤, 필요한 구간 외 것들을 빼는 방식으로 접근 -> 왜 안됐지 아래 주석은 시도한 흔적
     * 그냥 깡 구현으로 해결
     */

    for (int i=0; i<K; i++) {
        cin >> a >> b;
        if (a == b) {
            double ans = nums[a];
            cout << round(ans*100)/100<< "\n";
            continue;
        }
        // while (a != st) {
        //     if (a < st) {
        //         st--;
        //         number += nums[st];
        //     }
        //     if (a > st) {
        //         st++;
        //         number -= nums[st];
        //     }
        // }
        // while (b != ed) {
        //     if (b < ed) {
        //         ed--;
        //         number -= nums[ed];
        //     }
        //     if (b > ed) {
        //         ed++;
        //         number += nums[ed];
        //     }
        // }

        // cout << number/(b-a+1) << "\n";
        double ans = 0;
        for (int j=a; j<=b; j++) {
            ans += nums[j];
        }
        cout << ans/(b-a+1) << "\n";
    }
    
    return 0;
}