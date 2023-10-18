#include <iostream>
using namespace std;

int n, m;
int nums[9];
bool visited[9];


// 중복이 되지 않으면서, 오름차순으로 출력
void backTrack(int num, int cnt){
    if (cnt == m){
        for(int i=0;i<m;i++){
            cout << nums[i] << ' ';
        }
        cout << '\n';
        return ;
    }
    for(int i=num; i<=n; i++){
        if(!visited[i]){
            visited[i]=true;
            nums[cnt]=i;
            // i의 다음번째 인자를 입력해서 항상 더 크게 넘겨준다.
            backTrack(i+1, cnt+1);
            visited[i]=false;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    cin >> n >> m;

    backTrack(1, 0);

    return 0;
}