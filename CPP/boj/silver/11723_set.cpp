#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

void insertAll(unordered_set<int>& numS)
{
    for (int i=1; i<=20; i++)
    {
        numS.insert(i);
    }
}

void makeAll(vector<bool>& b, bool flg)
{
    for (int i=1; i<=20; i++)
    {
        b[i] = flg;
    }
}

void doOrder(std::string od, unordered_set<int>& numS, int i)
{
    if (od == "add")
    {
        numS.insert(i);
    }
    else if (od == "remove")
    {
        auto tmp = numS.find(i);
        if (tmp != numS.end()) 
        {
            numS.erase(i);
        }
    }
    else if (od == "check")
    {
        auto tmp = numS.find(i);
        if (tmp == numS.end())
        {
            cout << "0\n";
        }
        else
        {
            cout << "1\n";
        }
    }
    else if (od == "toggle")
    {
        auto tmp = numS.find(i);
        if (tmp == numS.end())
        {
            numS.insert(i);
        }
        else
        {
            numS.erase(i);
        }
    }
    else if (od == "empty")
    {
        numS.clear();
    }
    else if (od == "all")
    {
        insertAll(numS);
    }
    else
    {
        // do nothing
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int M;

    vector<bool> bArr;
    bArr.resize(21, false);
    
    unordered_set<int> numSet;
    std::string order;
    int orderNum = 0;

    freopen("input.txt", "r", stdin);

    cin >> M;

    while (M--)
    {
        cin >> order;
        if (order != "all" && order != "empty")
        {
            cin >> orderNum;
        }
        
        if (order == "empty")
        {
            makeAll(bArr, false);
        }
        else if (order == "all")
        {
            makeAll(bArr, true);
        }
        else if (order == "add")
        {
            bArr[orderNum] = true;
        }
        else if (order == "remove")
        {
            bArr[orderNum] = false;
        }
        else if (order == "check")
        {
            if (bArr[orderNum])
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if (order == "toggle")
        {
            bArr[orderNum] = !bArr[orderNum];
        }
        else
        {
            // do nothing
        }
        
        // doOrder(order, numSet, orderNum);
    }

    return 0;
}