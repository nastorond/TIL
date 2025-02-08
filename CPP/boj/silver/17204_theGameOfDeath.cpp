#include <iostream>
#include <algorithm>

using namespace std;

int iaPeople[151];
bool bVis[151];
int iGoal;
int iRes = -1;

void solution (int iNow, int iCnt)
{
    if (iNow == iGoal)
    { 
        iRes = iCnt;
        return ;
    }

    if (!bVis[iaPeople[iNow]])
    {
        bVis[iaPeople[iNow]] = true;
        solution(iaPeople[iNow], iCnt+1);
    }
    else 
    {
        return ; // cycle
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt", "r", stdin);

    fill(bVis, bVis+151, false);
    fill(iaPeople, iaPeople+151, -1);

    int N, iTmp;
    cin >> N >> iGoal;

    for (int i=0; i<N; i++)
    {
        cin >> iTmp;
        iaPeople[i] = iTmp;
    }

    bVis[0] = true;
    solution(0, 0);

    cout << iRes << "\n";

    return 0;
}