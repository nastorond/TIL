#include <iostream>
#include <vector>

using namespace std;

int res = 100000000;
int n;
int arr[15][15];

void find_ans(bool visited[], int now, int now_val){
    if (res < now_val) return ;

    if(now == n){
        if (now_val < res) res = now_val;
        return ;
    }

    for(int i = 0; i<n; i++){
        if (visited[i] == false){
            visited[i] = true;
            find_ans(visited, now+1, now_val + arr[now][i]);
            visited[i] = false;
        }
    }
}
void init(){
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            arr[i][j] = 0;
        }
    }
    res = 1e9;
}

int main(){
    int T;
    cin >> T;
    for (int tc=1; tc<=T; tc++){
        cin >> n;
        init();
        // 동적할당으로 입력
        // int** arr = new int*[n];
        // for(int i=0;i<n;i++){
        //     arr[i] = new int[n];
        //     fill_n(arr[i], n, 0);
        //     for (int j=0; j<n; j++){
        //         cin >> arr[i][j];
        //     }
        // }
        // vector<vector<int>> arr(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> arr[i][j];
            }
        }
        bool visited[n];
        fill(visited, visited+n, false);
        find_ans(visited, 0, 0);
        cout << "#" << tc << " " << res << "\n";
    }
}