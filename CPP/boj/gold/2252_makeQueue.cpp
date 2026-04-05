/*
Gold 3 줄세우기
서로의 키가 다름을 이용해 순서를 정렬하는 기본적인 위상정렬 문제
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//! 학생 수, 비교 횟수
int N, M;
std::vector<std::vector<int>> relations;
std::vector<int> indegree;
std::vector<int> order;

void init()
{
    cin >> N >> M;
    relations.resize(N+1, std::vector<int>());
    indegree.resize(N+1, 0);

    //! 상대적으로 작은, 큰
    int st, ed;
    for (int cpCnt=0; cpCnt<M; ++cpCnt)
    {
        cin >> st >> ed;
        //! X -> Y 연결
        relations[st].push_back(ed);
        //! 더 큰 학생 번호 ++
        ++indegree[ed];
    }
}

void sortStudents()
{
    std::queue<int> q;

    //! 가장 앞에 서 있어야하는 학생 번호 특정
    for (int i=1; i<=N; ++i)
    {
        //! 뒤에 선적 없는 학새은 가장 앞
        if (indegree[i] == 0)
        {
            q.push(i);
            order.push_back(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front(); q.pop();

        for (int& next : relations[cur])
        {
            //! 누군가의 뒤에 서있는 경우 몇번째 뒤인지 확인
            --indegree[next];
            //! 바로 뒤 인 경우 순서에 추가
            if (indegree[next] == 0)
            {
                q.push(next);
                order.push_back(next);
            }
        }
    }
}

void printAns()
{
    for(int& num : order)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    init();
    sortStudents();
    printAns();

    return 0;
}