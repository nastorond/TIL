/*
BOJ 2667 - 단지번호 붙이기
silver - 1

정사각형 모양의 집이 주어지고, 1은 집이 있는 곳. 0은 집이 없는곳을 의미.
각 단지 별 집의 개수를 구하고. 오름차순 정렬 출력

input
- 정사각형 한 변의 길이
- 단지 정보.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;  //! 크기
std::vector<std::vector<int>> apt;      //! 아파트 단지
std::vector<std::vector<bool>> visited; //! 방문 여부

//! 좌우상하
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool checkBoundary(int x, int y)
{
    return 0 > x || x > n-1 || 0 > y || y > n-1;
}

int solution(int x, int y)
{
    //! 최초 도달지 true 설정
    visited[x][y] = true;
    //! 현재 위치 포함 return 값 생성
    int res = 1;

    //! 순회를 위한 que
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(x, y));
    while (!q.empty())
    {
        //! 현재 좌표 저장
        std::pair<int, int> cur = q.front(); q.pop();

        //! 상하좌우 탐색
        for (int i=0; i<4; ++i)
        {
            //! 다음 목적지
            std::pair<int, int> next = make_pair(cur.first + dir[i][0], cur.second + dir[i][1]);
            //! 범위 내 이거나, 방문한 적 없으며, 단지가 있는 경우만 방문
            if (!checkBoundary(next.first, next.second) && !visited[next.first][next.second] && apt[next.first][next.second] == 1)
            {
                q.push(next);
                visited[next.first][next.second] = true;
                ++res;
            }
        }
    }

    return res;
}

void debugMap()
{
    //! apt 벡터 적재 내용 디버그용 출력
    for (auto v : apt)
    {
        for (int i : v)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
}

int main ()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n;

    //! 0으로 초기화되어있는 아파트 단지 구성
    apt.resize(n, std::vector<int>());
    //! n x n 크기의 방문 확인 배열 초기화 false - 미방문, true - 방문.
    visited.resize(n, std::vector<bool>(n, false));

    //! 입력받을 한 행에대한 정보
    std::string info;
    //! 정사각형 형태이므로 한변의 길이만큼 순회하며 필드 채움.
    for (int i=0; i<n; ++i)
    {
        cin >> info;

        //! 각 행 순회
        for (char c : info)
        {
            //! int 형태로 변환을 위한 char - '0' -> 0 or 1 저장
            apt[i].push_back(static_cast<int>(c - '0'));
        }
    }

    //debugMap();

    //! 결과 벡터
    std::vector<int> resVector;

    for (int i=0; i < n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            if (!visited[i][j] && apt[i][j] > 0)
            {
                resVector.push_back(solution(i, j));
            }
        }
    }

    sort(resVector.begin(), resVector.end());

    std::cout << resVector.size() << "\n";
    for (int i : resVector)
    {
        std::cout << i << "\n";
    }

    return 0;
}