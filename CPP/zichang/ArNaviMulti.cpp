/*
N개 교차로 M개 도로 infra
S -> E 최단 시간 구하고
최단 시간을 구했을 떄, 해당 시간 내에 도달할 수 있는 모든 경로를 구하고 해당 경로들 중 특정 보안 검문소 K를 지나는 지 확인

다익스트라를 통한 특정 거리까지의 최단거리 구하기?
BFS를 진행하며 최단거리로 도달하는 경우의 수를 구함과 동시에 지나오면서 특정 노드들을 지나는 지 검사.

초기 최단거리 dist = 1e9 값으로 설정
BFS를 진행하며 목적지에 도달 한 경우를 최단거리라고 가정하며 진행.
해당 거리보다 더 진행된 경우의수는 삭제
노드에 도달했을 시점에 검문소를 거쳤는지 특정하고 priority_queue에 저장. max 힙이니까 그냥 저장
최종적으로 종료됐을 때, top의 최단거리를 기준으로 같은 거리로 도달한 정보에 거쳤는지 여부 확인.

BFS로 그냥 진행 시 1,000 * 100,000 = 100,000,000 이므로 시간 초과.
최단거리 점검 후 최단거리를 기반으로 도달 여부 확인이 더 좋을듯.
*/
//#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#define MAX 1e9

using namespace std;

int N, M; //! 교차로 / 도로
int st, ed; //! 시작점 / 끝점
int max_dist = MAX; //! 최단 거리
bool isReachedSite = false; //! 최단거리 도달 여부
std::vector<vector<std::pair<int, int>>> infra; //! 도로 상황. 시작점 -> 끝점(가중치)
std::priority_queue<std::pair<int, bool>> pq; //! 도달 지점 점검용
std::unordered_set<int> security_site; //! 보안 검문소
std::vector<int> dists;

struct curInfo
{
    int node; //! 현재위치
    int dist; //! 도달 거리
    bool isReached; //! 검문소 도달 여부
};

void init()
{
    cin >> N >> M >> st >> ed;
    infra.resize(N+1, std::vector<std::pair<int, int>>());
    dists.resize(N+1, MAX);

    int startP, endP, wg; //! 시작, 끝, 가중치
    for (int i=0; i<M; ++i)
    {
        cin >> startP >> endP >> wg;
        infra[startP].push_back(std::make_pair(endP, wg));
    }

    int site_cnt, site_num; //! 보안검문소 개수, 보안검문소 번호
    cin >> site_cnt;
    for (int i=0; i<site_cnt; ++i)
    {
        cin >> site_num;
        security_site.insert(site_num);
    }
}

bool isSecuritySite(int cur)
{
    std::unordered_set<int>::const_iterator iter = security_site.find(cur);
    //! set 내 존재 여부 반환
    return (iter != security_site.end());
}

void searchingMap()
{
    /* 기존 로직 폐기
    std::queue<curInfo> q;
    //! 기본 데이터 적재
    curInfo tmp;
    tmp.node = st;
    tmp.dist = 0;
    tmp.isReached = isSecuritySite(st);

    q.push(tmp);
    while (!q.empty())
    {
        curInfo cur = q.front(); q.pop();

        //! 목표 지점에 도달한 경우
        if (cur.node == ed)
        {
            max_dist = cur.dist; //! 최단 거리 갱신
            pq.push(std::make_pair(max_dist, cur.isReached)); //! 현재 최단 정보와 도달 여부 확인
        }
        
        //! 다음 위치, 가중치
        for (std::pair<int, int> next : infra[cur.node])
        {
            //! 최단거리보다 짧은 경우만 이동
            if (cur.dist + next.second < max_dist)
            {
                //! q에 넣을 정보 생성
                curInfo nextInfo;
                nextInfo.node = next.first; //! 다음 교차로 번호
                nextInfo.dist = cur.dist + next.second; //! 다음교차로 까지의 가중치
                nextInfo.isReached = isSecuritySite(next.first); //! 현재가 보안 교차로인지 확인

                q.push(nextInfo);
            }
        }
    }
    */

    //! dist, curNode, set minHeap
    priority_queue<pair<int, int>> pq;

    //! 시작 노드를 거리 0으로 시작
    pq.push(std::make_pair(0, st));
    while (!pq.empty())
    {
        //! pair info : distance, cur node num
        std::pair<int, int> cur = pq.top(); pq.pop();
        cur.first *= -1;
        if (cur.second == ed)
        {
            max_dist = cur.first;
            break;
        }

        //! pair info : next node num, weight
        for (std::pair<int, int> next : infra[cur.second])
        {
            //! 현재 저장되어있는 거리보다 짧은 경우만 진행
            if (dists[next.first] > cur.first + next.second)
            {
                dists[next.first] = cur.first + next.second;
                pq.push(std::make_pair(dists[next.first] * -1, next.first));
            }
        }
    }
}

void solution()
{
    /*
    while (true)
    {
        //! 거리, 도달여부
        std::pair<int, bool> topInfo = pq.top(); pq.pop();
        
        if (topInfo.second > max_dist)
        {
            //! 더이상 점검 할 필요 없으므로 loop 정지
            break;
        }

        if (topInfo.second)
        {
            //! 도달 여부 갱신 후 loop 정지
            isReachedSite = true;
            break;
        }
    }
    */

    //! node num, dist
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(st, 0));

    //! 특정 거리보다 짧은 경우 도달 가능한지 확인
    while (!q.empty())
    {
        std::pair<int, int> cur = q.front(); q.pop();
        
        //! 도달 가능한 경우 종료
        if (isSecuritySite(cur.first))
        {
            isReachedSite = true;
            break;
        }

        //! 그래프 순회
        for (std::pair<int, int> next : infra[cur.first])
        {   
            //! 최단 거리보다 짧은 경우만 고려
            if (max_dist > next.second + cur.second)
            {
                q.push(std::make_pair(next.first, next.second + cur.second));
            }
        }
    }

    std::cout << max_dist << "\n";
    if (isReachedSite)
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    searchingMap();
    solution();
    
    return 0;
}
