#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//! 부품 총 개수, 의존성 관계 수
int N, M;

//! 관계 그래프
//! Y -> {X, K}
//! Y를 K개 사용해서 X를 만듦
std::vector<std::vector<std::pair<int, int>>> tree;

//! 진입 차수: 해당 부품을 만들기 위해 필요한 하위 부품 수
std::vector<int> indegree;

//! 나가는 차수: 해당 부품이 상위 부품 제작에 사용되는 횟수
std::vector<int> outdegree;

//! basic 부품 여부
std::vector<bool> isBasic;

//! dp[u][b] = u를 1개 만들 때 기본 부품 b가 필요한 개수
std::vector<std::vector<int>> dp;

void init()
{
    cin >> N >> M;

    tree.resize(N + 1, std::vector<std::pair<int, int>>());
    indegree.resize(N + 1, 0);
    outdegree.resize(N + 1, 0);
    isBasic.resize(N + 1, false);
    dp.resize(N + 1, std::vector<int>(N + 1, 0));

    int X, Y, K;
    for (int i = 0; i < M; ++i)
    {
        cin >> X >> Y >> K;

        //! Y -> X
        tree[Y].push_back(std::make_pair(X, K));

        indegree[X]++;
        outdegree[Y]++;
    }
}

void solution()
{
    queue<int> q;

    //! 기본 부품 찾기: indegree == 0
    for (int i = 1; i <= N; ++i)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            isBasic[i] = true;
            dp[i][i] = 1; //! 기본 부품 자기 자신 1개
        }
    }

    //! 위상정렬 + DP
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (const std::pair<int, int>& next : tree[cur])
        {
            int nextNode = next.first;
            int needCount = next.second;

            //! cur 부품 정보로 nextNode의 기본 부품 개수 누적
            for (int basic = 1; basic <= N; ++basic)
            {
                dp[nextNode][basic] += dp[cur][basic] * needCount;
            }

            indegree[nextNode]--;

            if (indegree[nextNode] == 0)
            {
                q.push(nextNode);
            }
        }
    }

    //! 완제품 출력: outdegree == 0
    //! 완제품이 여러 개일 수 있으므로 모두 출력
    for (int product = 1; product <= N; ++product)
    {
        if (outdegree[product] == 0)
        {
            cout << "product " << product << "\n";

            for (int basic = 1; basic <= N; ++basic)
            {
                if (isBasic[basic] && dp[product][basic] > 0)
                {
                    cout << basic << " " << dp[product][basic] << "\n";
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solution();

    return 0;
}