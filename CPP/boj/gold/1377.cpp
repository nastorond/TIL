#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int N;

    cin >> N;

    vector <pair<int, int>> Arr(N);
    int a;
    for (int i=0; i<N; i++){
        cin >> Arr[i].first;
        Arr[i].second = i;
    }
    sort(Arr.begin(), Arr.end());

    int ans = -1;
    for (int i=0;i<N;i++){
        if (ans < Arr[i].second - i){
            ans = Arr[i].second - i; 
        }
    }

    cout << ans + 1 << "\n";

    return 0;
}
