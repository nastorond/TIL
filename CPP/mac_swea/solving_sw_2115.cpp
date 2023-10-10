#include <iostream>
#include <algorithm>

using namespace std;

int h_box[11][11];
int ck_box[11][11];
bool visited[11];
int tmp_list[11];
int tmp_cost;


void findMaxVal(int cnt, int max_cnt, int limit_val, int now_val){
    if (now_val > limit_val) return ;

    if (cnt == max_cnt-1){
        for (int i=0; i<max_cnt; i++){
            if (visited[i]) tmp_cost += tmp_list[i]^2;
        }
    }

    visited[cnt]=true;
    findMaxVal(cnt+1, max_cnt, limit_val, now_val + tmp_list[cnt]);
    visited[cnt]=false;
    findMaxVal(cnt+1, max_cnt, limit_val, now_val);
}


int main(){
    int T, n, m, c;
    int max_val, tmp;
    cin >> T;

    for(int tc=1;tc<=T;tc++){
        cin >> n >> m >> c;

        for(int i=0;i<n;i++){
            for(int j=0; j<n;j++){
                cin >> h_box[i][j];
                ck_box[i][j] = 0;
            }
        }
        // 최대 벌통의 크기 100, 최소 선택 벌통의 개수 1개 일때 완전탐색하면 100
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // 첫번째 후보 선택
                if (j+m<n){
                    for (int k=0;k<m;k++){
                        tmp_list[k] = h_box[i][j+k];
                        visited[k]=false;
                        ck_box[i][j+k]=1;
                    }
                    tmp_cost=0;
                    findMaxVal(0,m,c,0);
                    tmp = tmp_cost;
                }
                // 두번째 후보 선택
                for(int u=0; u<n; u++){
                    for(int v=0; v<n; v++){
                        if(v+m<n){
                            if(ck_box[u][v]==0 && ck_box[u][v+m]==0){
                                for (int k=0;k<m;k++){
                                    visited[k]=false;
                                    tmp_list[k] = h_box[u][v+k];
                                }
                                // 초기화
                                tmp_cost=0;
                                findMaxVal(0,m,c,0);
                                // 값 갱신
                                max_val = max(max_val, tmp + tmp_cost);
                            }
                        }
                    }
                }
            }
        }
        cout << "#" << tc << " " << max_val << "\n";
    }
    return 0;
}
