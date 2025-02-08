#include <iostream>
#include <string>

using namespace std;

bool condition(char cA, char cB)
{
    return (cA - '0') + (cB - '0') < 1;
}

bool sol(int iNum)
{
    bool bRes = true;
    string sTmp;
    while (iNum--)
    {
        cin >> sTmp;

        if (condition(sTmp[0], sTmp[1]) || condition(sTmp[1], sTmp[2]))
        {
            bRes = false;
        }
    }

    return bRes;
}

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("input.txt", "r", stdin);

    int iTc;
    int height;
    cin >> iTc;

    for (int iCnt=0; iCnt<iTc; iCnt++)
    {
        cin >> height;
        if (!sol(height)) 
            cout << "Case " << iCnt + 1 << ": Fallen\n";
        else 
            cout << "Case " << iCnt + 1 << ": Standing\n";
    }

    return 0;
}
