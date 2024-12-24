/*
Gold 4
철도 공사

unordered_map 형태로 구현하여 검색 속도 최적화
-> prev, next 를 value 로 저장

or 

vector index 에 저장. -> N 500,000 

or 

pair array

limits
M -> 1,500,000 
guess : limit timecomplexity -> O(N+M) or O(log(N*M))
Memory : 512 MB literary unlimited..
each station is connected like circle

*/
#include <iostream>
#include <string>

using namespace std;

pair<int,int> nodes[1000001]; // prev, next

int buildNext (int stA, int stB) {
    // create new station b next to a
    int stTmp = nodes[stA].second;

    nodes[stB].first = stA;
    nodes[stB].second = stTmp;
    
    nodes[stA].second = stB;
    nodes[stTmp].first = stB;

    return stTmp;
}

int buildPrev (int stA, int stB) {
    // crete new station b before a
    int stTmp = nodes[stA].first;

    nodes[stB].first = stTmp;
    nodes[stB].second = stA;

    nodes[stA].first = stB;
    nodes[stTmp].second = stB;

    return stTmp;
}

int closeNext (int stA) {
    // close station next to a
    int stTmp = nodes[stA].second;

    nodes[stA].second = nodes[stTmp].second;
    nodes[nodes[stTmp].second].first = stA;

    return stTmp;
}

int closePrev (int stA) {
    // close station before a
    int stTmp = nodes[stA].first;

    nodes[stA].first = nodes[stTmp].first;
    nodes[nodes[stTmp].first].second = stA;

    return stTmp;
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int tmp, tmpPrev, st, N, M;
    string constructName;

    cin >> N >> M;

    // input
    // connecting basic stations
    for (int i=0; i<N; i++) {
        cin >> tmp;

        if (i == 0) {
            tmpPrev = tmp;
            st = tmp;
        }
        else if (i == N-1) {
            nodes[tmp].first = tmpPrev;
            nodes[tmp].second = st;
            nodes[tmpPrev].second = tmp;

            nodes[st].first = tmp;
        }
        else {
            nodes[tmp].first = tmpPrev;
            nodes[tmpPrev].second = tmp;
        }
        tmpPrev = tmp;
    }

    // constructing
    while (M--) {
        cin >> constructName >> tmp;
        if (constructName == "BN") {
            cin >> tmpPrev;
            cout << buildNext(tmp, tmpPrev) << "\n";
        }
        else if (constructName == "BP") {
            cin >> tmpPrev;
            cout << buildPrev(tmp, tmpPrev) << "\n";
        }
        else if (constructName == "CN") {
            cout << closeNext(tmp) << "\n";    
        }
        else if (constructName == "CP") {
            cout << closePrev(tmp) << "\n";
        }
    }

    return 0;
}