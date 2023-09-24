#include <iostream>
#include <vector>

using namespace std;

int res = 100000000;
int n;

void find_ans(int visited[], int now, int now_val, int arr[]){
    if (res < now_val) return ;

    int sum_val = 0;
    for (int i=0; i<n; i++){
        sum_val += visited[i];
    }
    if(sum_val == n){
        if (now_val < res) res = now_val;
        return ;
    }

    for(int i = 0; i<n; i++){
        if (visited[i] == 0){
            visited[i] = 1;
            find_ans(visited, now+1, now_val, arr);
            visited[i] = 0;
        }
    }
}

int main(){
    int T;
    cin >> T;
    for (int i=1; i<=T; i++){
        cin >> n;

        // 동적할당으로 입력
        // int** arr = new int*[n];
        // for(int i=0;i<n;i++){
        //     arr[i] = new int[n];
        //     fill_n(arr[i], n, 0);
        //     for (int j=0; j<n; j++){
        //         cin >> arr[i][j];
        //     }
        // }
        vector<vector<int>> arr(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int t;
                cin >> t;
                arr[i].push_back(t);
            }
        }
        vector<int> visited[n];
        // find_ans(visited, 0, 0, arr);
    }
}