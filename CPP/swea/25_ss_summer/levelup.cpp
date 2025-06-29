/*
1차원 수직선상에서 진행
N 개의 체크포인트 존재
1번에서 시작해 N 까지 진행
정확히 한개의 체크포인트(2 ~ N-1 중 하나)는 방문하지 않아도 된다.
i -> j 일 때, abs(xi - xj)

brute force N^2 시간 초과
누적합 활용하면 될듯
*/
#include <iostream>
#include <vector>
#include <cmath>

#define MAXNUM 100001

using namespace std;

int points[MAXNUM] = {0,};
int numOfCheckPoint;

void inputData()
{
    //! memset(points, 0, sizeof(points));
    cin >> numOfCheckPoint;
    for (int cnt=0; cnt<numOfCheckPoint; cnt++)
    {
        cin >> points[cnt];
    }
}

int solution()
{
    vector<int> preSum;
    int preSumTot = 0;
    for (int idx=1; idx<numOfCheckPoint; idx++)
    {
        int tmpNum = abs(points[idx] - points[idx-1]);
        preSum.push_back(tmpNum);
        preSumTot += tmpNum;
    }

    int res = 1e9;
    
    for (int idx = 1; idx < numOfCheckPoint-1; idx++)
    {
        int skipNum = preSum[idx] + preSum[idx+1];
        int newSum = abs(points[idx+1] - points[idx-1]);
        int tmpRet = preSumTot - skipNum + newSum;
        res = min(res, tmpRet);
    }

    return res;
}

int main (int argc, char** argv) 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;

    for (int test_case=0; test_case<tc; test_case++)
    {
        inputData();
        cout << solution() << "\n";
        cout.flush();
    }

    return 0;
}