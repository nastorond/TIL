#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct goodsInfo {
    int id, rev, profit, dest;
    bool isDelete, isAvail;

    goodsInfo () : id(0), rev(0), profit(0), dest(0), isDelete(false), isAvail(true) {}

    struct Compare {
        bool operator()(const goodsInfo& a, const goodsInfo& b) const {
            if (a.profit == b.profit) return a.id > b.id;
            return a.profit < b.profit;
        }
    };
};

unordered_map<int, goodsInfo> tours;
priority_queue<goodsInfo, vector<goodsInfo>, goodsInfo::Compare> pq;
int codeTreeLand[2001][2001];
int dis[2001];
int n, arrival = 0;

void dijkstra () {
    priority_queue<pair<int, int>> pq;

    dis[arrival] = 0;
    pq.push(make_pair(0, arrival));

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second; pq.pop();

        if (dis[now] < dist) continue;
        for (int i=0; i<n; i++) {
            if (codeTreeLand[now][i] > 999) continue;
            int nextDist = dist + codeTreeLand[now][i];
            
            if (nextDist < dis[i]) {
                dis[i] = nextDist;
                pq.push(make_pair(-nextDist, i));
            }
        }
    }

    cout << "\n";
    for (int i=0; i<n; i++) cout << dis[i] << " ";
    cout << "\n";

    return ;
}

void init() {
    int m, u, v, w;
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            codeTreeLand[i][j] = 1000;
            if (i==j) codeTreeLand[i][j] = 0;
        }
        dis[i] = 1e9;
    }

    for (int i=0; i<m; i++) {
        cin >> u >> v >> w;
        codeTreeLand[u][v] = min(codeTreeLand[u][v], w);
        codeTreeLand[v][u] = min(codeTreeLand[v][u], w);
    }

    dijkstra ();

    cout << " \n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << codeTreeLand[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void addTourPackage() {
    goodsInfo tourPackage;
    cin >> tourPackage.id >> tourPackage.rev >> tourPackage.dest;

    if (dis[tourPackage.dest] == 1e9) {
        tourPackage.isAvail = false;
        tourPackage.profit = -999;
    } else {
        tourPackage.profit = tourPackage.rev - dis[tourPackage.dest];
    }

    tours[tourPackage.id] = tourPackage;
    pq.push(tourPackage);

    return ;
}

void deletePackage() {
    int id;
    cin >> id;
    tours[id].isDelete = true;
}

void recommendProduct() {
    while (!pq.empty()) {
        goodsInfo tmp = pq.top(); pq.pop();
        if (!tmp.isAvail || tours[tmp.id].isDelete) continue;
        if (tmp.profit < 0) continue;
        cout << tmp.id << "\n";
        tours[tmp.id].isDelete = true;
        return ;
    }

    cout << -1 << "\n";

    return ;
}

void resetStartPoint() {
    cin >> arrival;

    for (int i=0; i<n; i++) {
        dis[i] = 1e9;
    }
 
    dijkstra();
    while (!pq.empty()) pq.pop();

    for (auto tour : tours) {
        if (tour.second.isDelete) continue;
        
        if (tour.second.dest == arrival) {
            tours[tour.first].profit = tour.second.rev;
            tours[tour.first].isAvail = true;
            pq.push(tours[tour.first]);
        }
        else {
            tours[tour.first].profit = tour.second.rev - dis[tour.first];
            tours[tour.first].isAvail = true;

            if (dis[tour.second.dest] > 1000) {
                tours[tour.first].profit = 0;
                tours[tour.first].isAvail = false;
            }
            pq.push(tours[tour.first]);
        }
    }

    cout << "\n";
    for (auto tour : tours) {
        cout << tour.first << " 순이익 : " << tour.second.profit;
        cout << " revenue : " << tour.second.rev;
        cout << " 판매 or 삭제 여부 : " << tour.second.isDelete;
        cout << " 가능 여부 : " << tour.second.isAvail << "\n";
    }
    cout << "\n";

    return ;
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int Q, query;
    cin >> Q;
    for (int i = 0; i<Q; i++) {
        cin >> query;
        switch (query) {
        case 100:
            init();
            break;
        case 200:
            addTourPackage();
            break;
        case 300:
            deletePackage();
            break;
        case 400:
            recommendProduct();
            break;
        case 500:
            resetStartPoint();
            break;
        }
    }

    return 0;
}