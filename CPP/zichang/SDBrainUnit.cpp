/*
중간 부품을 조립하여 최종 차량 완제품 생산
N을 위한 부품 여러개. Y를 위한 X K개. -> M
완제품 한개를 위한 1차 기본 부품 총 소요 개수

tree를 순회하여 root를 찾고 root로 부터 목적지 dijkstra => 아님

root로부터 특정 지점까지 도달하는 데 필요한개수 저장 후 재사용하는 방식필요.
    - 전체 탐색하면 시간초과.
    - 특정 위치까지 도달하는데에 필요한 개수를 vector에 각각 저장.
    - 각 노드에 도달할 때, 해당 노드에 가중치? 저장된 값이 0이면 더 안쪽 탐색. 그게 아니면 현재 값 사용.
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

//! 부품 총 개수, 의존성 관계 수
int N, M;
std::vector<std::vector<std::pair<int, int>>> tree; //! 관계 그래프 / start -> {destination, weight}
std::vector<int> dist; //! 특정 노드 별 도달했을 때, 필요 가중치 표시
std::vector<bool> isReached; //! 방문지가 된 적있는지 점검

void init()
{
    cin >> N >> M;
    //! 트리 형태의 관계 구조 초기화
    tree.resize(N+1, std::vector<std::pair<int, int>>());
    //! 각 노드 별 도달 시 0으로 초기화
    dist.resize(N+1, 0);
    //! false 초기화
    isReached.resize(N+1, false);

    int st, ed, we;
    for (int i=0; i<M; ++i)
    {
        cin >> st >> ed >> we;
        tree[st].push_back(std::make_pair(ed, we));
    }
}

int updateNode(int cur, int count)
{
    int res = 1;
    if (dist[cur] != 0)
    {
        res = dist[cur];
    }
    else 
    {
        //! pair info : next node num, weight
        vector<std::pair<int,int>>::const_iterator next = tree[cur].begin();
        while(next != tree[cur].end())
        {
            isReached[next->first] = true; //! 줄기 표시

            if (dist[next->first] == 0)
            {
                res = updateNode(next->first, next->second);
            }

            ++next;
        }
        
    }
    
    //! 현재 노드에서 필요한 가중치 * 개수
    return res * count;
}

void solution()
{
    for (int i=1; i<=N; ++i)
    {
        if (!isReached[i])
        {
            dist[i] = updateNode(i, tree[i][0].second);
        }
    }

    for (int i=1; i<N; ++i)
    {
        if (!isReached[i])
        {
            std::cout << i << " " << dist[i] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solution();
    
    return 0;
}
