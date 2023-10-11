#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

char fld[101][101];
int visited[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;


void bfs_normal(int x, int y, char now){
    int nx, ny, mx, my;
    queue<pair<int, int>> q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        pair tmp = q.front();
        mx = tmp.first;
        my = tmp.second;
        q.pop();
        for(int i=0;i<4;i++){
            nx = mx+dx[i];
            ny = my+dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<n && visited[nx][ny]==0){
                if (fld[nx][ny] == now){
                    visited[nx][ny] = now;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}


void bfs(int x, int y, char now){
    int nx, ny, mx, my;
    queue<pair<int, int>> q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        pair tmp = q.front();
        mx = tmp.first;
        my = tmp.second;
        q.pop();
        for(int i=0;i<4;i++){
            nx = mx+dx[i];
            ny = my+dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<n && visited[nx][ny]==0){
                if (now=='G' || now=='R'){
                    if (fld[nx][ny]=='G' || fld[nx][ny]=='R') {
                        q.push(make_pair(nx, ny));
                        visited[nx][ny] = now;
                    }
                }else {
                    if (now==fld[nx][ny]){
                        q.push(make_pair(nx, ny));
                        visited[nx][ny] = now;
                    }
                }
            }
        }
    }
}


void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j] = 0;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int res1=0, res2=0;

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> fld[i][j];
            visited[i][j]=0;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] == 0){
                bfs_normal(i, j, fld[i][j]);
                res1++;
            }
        }
    }

    init();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] == 0){
                bfs(i, j, fld[i][j]);
                res2++;
            }
        }
    }

    cout << res1 << " " << res2 << "\n"; 

    return 0;
}
