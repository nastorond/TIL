// https://acmicpc.net/problem/1302
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct BookInfo
{
    string name;
    int cnt; 
};

bool Compare(BookInfo a, BookInfo b)
{
    if (a.cnt == b.cnt)
    {
        return a.name < b.name;
    }
    
    return a.cnt > b.cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int N;
    cin >> N;

    vector<BookInfo> v;
    unordered_map<string, int> bookHashing;

    int index = 0;

    for (int i=0; i<N; ++i)
    {
        BookInfo tmp;
        string book_name;
        cin >> book_name;
        
        auto it = bookHashing.find(book_name);
        if (it != bookHashing.end())
        {
            v[it->second].cnt++;
        }
        else
        {
            bookHashing[book_name] = index;
            index++;

            tmp.name = book_name;
            tmp.cnt = 1;
            v.push_back(tmp);
        }
    }

    sort(v.begin(), v.end(), Compare);

    cout << v[0].name << "\n";

    return 0;
}