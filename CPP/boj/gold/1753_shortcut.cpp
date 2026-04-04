/*
Gold 4
다익스트라 기반의 최단거리 알고리즘
*/

#include <iostream>
#include <vector>
#include <queue>
#define MAX 1e9

using namespace std;

//! 정점 및 간선의 개수
int V, E;
//! 시작점
int StartPoint;
std::vector<std::vector<std::pair<int, int>>> gp;
std::vector<int> dist;

void init()
{
    cin >> V >> E;
    //! 길이 벡터 초기화
    dist.resize(V+1, MAX);
    //! 맵 초기화
    gp.resize(V+1, std::vector<std::pair<int,int>>());

    cin >> StartPoint;

    for (int i=0; i<E; ++i)
    {   
        //! 시작점, 끝점, 가중치
        int st, ed, wg;
        cin >> st >> ed >> wg;
        
        //! 단방향 연결
        gp[st].push_back(std::make_pair(ed, wg));
    }
}

void solution(int st)
{
    //! 자신까지의거리 0
    dist[st] = 0;

    //! basically pq in C++ is MAX Heap
    //std::priority_queue<std::pair<int, int>> pq;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, greater<std::pair<int, int>>> pq;
    pq.push(std::make_pair(0, st));
    while (!pq.empty())
    {
        //! pair info : first -> cur distance, second -> cur point
        std::pair<int, int> cur = pq.top(); pq.pop();
        //cur.first *= -1;

        //! pair info : first -> next point, second -> weight
        for (std::pair<int, int> next : gp[cur.second])
        {
            //! 다음보다 작은 경우만 진행
            if (dist[next.first] > cur.first + next.second)
            {
                dist[next.first] = cur.first + next.second;
                //! min heap
                pq.push(std::make_pair(dist[next.first], next.first));

                //! debug
                //std::cout << "cur point : " << cur.second << " next point : " << next.first << "\n";
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    init();

    solution(StartPoint);

    std::vector<int>::const_iterator iter = dist.begin();
    ++iter; //! 0은 제외

    while (iter != dist.end())
    {
        string output = *iter < MAX ? std::to_string(*iter) : "INF";
        std::cout << output << "\n";
        ++iter;
    }

    return 0;
}