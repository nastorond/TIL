#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n;
int playerPower[31] = {0, };
int playerDir[31] = {0, };
int fld[21][21] = {0, };
int playerGun[31] = {0, };
int playerPoint[31] = {0, };
int playerLoc[31] = {0, };
int mv[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
unordered_map<int, vector<int>> guns;

bool boundaryCheck(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

void changeGun (int x, int y, int num) {
    vector<int> tmp;
    int tmpPlayerGun = playerGun[num];
    
    for (int gunP : guns[x*100+y]) {
        if (tmpPlayerGun > gunP) {
            tmp.push_back(gunP);
        } else {
            if (tmpPlayerGun > 0) tmp.push_back(tmpPlayerGun);
            tmpPlayerGun = gunP;
        }
    }
    playerGun[num] = tmpPlayerGun;
    guns[x*100+y] = tmp;

    return ;
}

pair<int, int> playGame(int x, int y, int p1) {
    int p2 = fld[x][y];

    int p1Power = playerPower[p1] + playerGun[p1];
    int p2Power = playerPower[p2] + playerGun[p2];
    int loser = p1;

    if (p1Power > p2Power) loser = p2;
    else if (p1Power == p2Power && playerPower[p1] > playerPower[p2]) loser = p2;

    if (playerGun[loser] > 0) {
        guns[x*100+y].push_back(playerGun[loser]);
        playerGun[loser] = 0;
    }
    int lx = x, ly = y;
    int ldir = playerDir[loser];

    while (true) {
        int dx = lx+mv[ldir][0];
        int dy = ly+mv[ldir][1];
        if (!boundaryCheck(dx, dy) && fld[dx][dy] == 0) {
            lx = dx;
            ly = dy;
            playerDir[loser] = ldir;
            playerLoc[loser] = lx*100+ly;
            fld[lx][ly] = loser;
            break;
        }
        ldir = (ldir+1)%4;
    }
    cout << p1 << " " << p2 << "\n";
    cout << "loser " << loser << " " << p1Power << " " << p2Power << "\n";

    // winner p2
    if (loser == p1) {
        fld[x][y] = p2;
        playerPoint[p2] += p2Power - p1Power;
        changeGun(x, y, p2);
        return make_pair(lx, ly);
    }
    // winner p1
    else {
        changeGun(lx, ly, p2);
        playerPoint[p1] += p1Power - p2Power;
    }
    
    return make_pair(x, y);
}

void simulation(int playerNum) {
    int x = playerLoc[playerNum]/100;
    int y = playerLoc[playerNum]%100;
    int dir = playerDir[playerNum];
    fld[x][y] = 0;

    // move forward
    if (boundaryCheck(x+mv[dir][0], y+mv[dir][1])) {
        dir = (dir+2)%4;
        playerDir[playerNum] = dir;
    }
    x += mv[dir][0];
    y += mv[dir][1];

    if (fld[x][y] > 0) {
        pair<int, int> p = playGame(x, y, playerNum);
        x = p.first;
        y = p.second;
    }

    if (guns[x*100+y].size() > 0) changeGun(x, y, playerNum);
    playerLoc[playerNum] = x*100 + y;
    fld[x][y] = playerNum;

    return ;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    
    int m, turn;
    cin >> n >> m >> turn;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int tmp;
            cin >> tmp;
            guns[i*100+j].push_back(tmp);
        }
    }

    int x, y;
    for (int i=1; i<=m; i++) {
        cin >> x >> y >> playerDir[i] >> playerPower[i];
        playerLoc[i] = (x-1)*100+(y-1);
        fld[x-1][y-1] = i;
    }

    for (int t=0; t<turn; t++) {
        for (int num=1; num<=m; num++) {
            simulation(num);

            cout << "\n";
            cout << "player number : " << num << "\n";
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) cout << fld[i][j] << " ";
                cout << "\n";
            }
            cout << "\n";
        }
    }

    for (int i=1; i<=m; i++) {
        cout << playerPoint[i] << " ";
    }
    cout << "\n";

    return 0;
}