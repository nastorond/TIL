#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool maps[102][102];
int visited[102][102];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void init(vector<vector<int>> rectangle) {
    for (int i=0; i<rectangle.size(); i++) {
        for (int j=rectangle[i][0]*2; j<=rectangle[i][2]*2; j++) {
            for (int k=rectangle[i][1]*2; k<=rectangle[k][3]*2; k++) {
                visited[j][k] = 1;
                if (rectangle[i][0]*2 < j && j < rectangle[i][2]*2 && rectangle[i][1]*2 < k && k < rectangle[i][3]*2) {
                    maps[j][k] = false;
                }
                else {
                    maps[j][k] = true;
                }
            }
        }
    }
}

int findItem(int startX, int startY, int eX, int eY) {
    queue<pair<int, int>> q;
    visited[startX][startY] = true;
    q.push(make_pair(startX, startY));
    int res;
    
    int x, y, nx, ny;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        if (x==eX && y==eY) {
            res = visited[x][y] / 2;
            break;
        }
        
        for (int i=0; i<4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (maps[nx][ny] == 1 && visited[nx][ny] == 1) {
                visited[nx][ny] += visited[x][y];
                q.push(make_pair(nx, ny));
            }
        }
    }
    return res;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    init(rectangle);
    
    return findItem(characterX*2, characterY*2, itemX*2, itemY*2);
}

int main() {
    int res = solution({{1,1,7,4},{3,2,5,5},{4,3,6,9},{2,6,8,8}}, 1, 3, 7, 8);
    
    cout << res << "\n";
    return 0;
}