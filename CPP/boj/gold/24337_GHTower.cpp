/*
Gold lll 가희와 탑
건물 N개
가희의 건물 L / 단비의 건물 R
가희 R 1번 건물
if 0 < x < N 
    x, x+1, x+2

k번 건물 왼쪽에 있는 모든 건물이 k번 건물보다 높이가 낮으면 가희는 k번 건물을 볼 수 있음.
k번 건물 오른쪽에 있는 모든 건물이 k번 건물보다 높이가 높으면 단비는 k번 건물을 볼 수 있음.

input
가희 - 단비 사이에 건물 N개     0 < N < 10^5 + 1
가희가 볼 수 있는 건물 개수 a   0 < a < N+1
단비가 볼 수 있는 건물 개수 b   0 < b < N+1

사전순으로 가장 앞서는 N개의 높이 정보 출력 / 가장 작은 수.
건물의 배치를 출력하는데 가장 작은 수로 구성

각 관측자 입장에서 보이는 건물의 개수 이므로
112 가 될 수 없음.

층 수, 높이에는 제한이 없지만 최소값을 리턴해야 하는듯.
최소 높이는 1이니까 모든 수는 1로 채움.
1 부터 카운팅해서 늘려서 출력하는 식으로 풀이. 7개 중 4개를 본다 하면 1 1 1 1 2 3 4
역순은 개수가 채워질 수 있을 때 까지 1을 넣고 나머지 숫자 입력. 7개 중 4개를 본다 하면 4 1 1 1 3 2 1 이런식

안되는 경우의 수 찾기
더해서 작거나 큰 경우 모두 예외처리 가능.

왼쪽에서부터 채웠을 때의 최소값과 오른쪽에서 부터 채웠을 경우 최소값의 합 -1 이 N과 다르면 불가능 할듯.

서로의 최고점이 꼭 같다는 보장은 없다. 다를 수도 있음. 그럼 나머지는 그냥 쓰고 최고점은 큰 수 사용.

서로의 최소 개수를 먼저 구한 후 최고점 제외
서로 값을 더했을 떄, 값이 N-1 보다 크면 -1 출력
*/

#include <iostream>
#include <deque>

using namespace std;
int NumOfTower, GNum, DNum, GaheeSide, DanbiSide;

void solution()
{
    //! Top은 각 사이드 중 더 큰 숫자 +1
    int topOfBuildings = (GaheeSide > DanbiSide ? GaheeSide : DanbiSide) + 1;

    deque<int> resGahee; //! Result for Gahee
    deque<int> resDanbi; //! Result for Danbi

    //! 가희가 보는 개수 deque에 입력
    for (int i=1; i<=GaheeSide; ++i)
    {
        resGahee.push_back(i);
    }

    //! 단비가 보는 개수 deque에 입력
    for (int i=DanbiSide; i>=1; --i)
    {
        resDanbi.push_back(i);
    }

    if (resGahee.size() == 0)
    {
        cout << topOfBuildings << " ";
        
        int counting = resDanbi.size() + 1;

        while (true)
        {
            if (counting < NumOfTower)
            {
                cout << "1 ";
            }
            else
            {
                break;
            }
            ++counting;
        }

        for (int towerH : resDanbi)
        {
            cout << towerH << " ";
        }
    }
    else 
    {
        int counting = resDanbi.size() + resGahee.size() + 1;

        while (true)
        {
            if (counting < NumOfTower)
            {
                cout << "1 ";
            }
            else
            {
                break;
            }
            ++counting;
        }

        for (int iter : resGahee)
        {
            cout << iter << " ";
        }

        cout << topOfBuildings << " ";

        for (int iter : resDanbi)
        {
            cout << iter << " ";
        }
    }
    
}

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> NumOfTower >> GNum >> DNum;

    GaheeSide = GNum - 1;
    DanbiSide = DNum - 1;

    if (GaheeSide + DanbiSide + 1 > NumOfTower) //! 실패 경우 출력
    {
        cout << "-1\n";
    }
    else
    {
        solution();
    }

    return 0;
}