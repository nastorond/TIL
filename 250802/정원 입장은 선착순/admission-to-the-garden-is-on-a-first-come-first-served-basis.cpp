#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int, int>

using namespace std;

int N;
int base_time=0;

struct info
{
    int number;
    int ar_time;
    int vw_time;
};

struct compare
{
    bool operator()(info a, info b)
    {
        if (a.ar_time == b.ar_time)
        {
            return a.number > b.number;
        }
        return a.ar_time > b.ar_time;
    }
};

struct compare2
{
    bool operator()(info a, info b)
    {
        return a.number > b.number;
    }
};

priority_queue<info, vector<info>, compare> arrival_q;
priority_queue<info, vector<info>, compare2> ready_q;
priority_queue<pii> ret;

void solution()
{
    auto tmp = arrival_q.top(); arrival_q.pop();
    base_time = tmp.ar_time;
    base_time += tmp.vw_time;
    ret.push(make_pair(0, -1 * tmp.number));

    while (true)
    {
        while (!arrival_q.empty()) //! move person to ready queue
        {
            if (base_time < arrival_q.top().ar_time) break;

            ready_q.push(arrival_q.top()); arrival_q.pop();
        }

        int delay_time = 0;
        if (ready_q.empty())
        {
            tmp = arrival_q.top();

            base_time = tmp.ar_time;
        }
        else
        {
            tmp = ready_q.top(); ready_q.pop();

            if (base_time < tmp.ar_time)
            {
                base_time = tmp.ar_time;
                base_time += tmp.vw_time;
            }
            else
            {
                delay_time = base_time - tmp.ar_time;
                base_time += tmp.vw_time;
            }
            ret.push(make_pair(delay_time, -1 * tmp.number));
        }

        if (arrival_q.empty() && ready_q.empty()) break;
    }

    cout << ret.top().first << "\n";
    /*
    while (!ret.empty())
    {
        cout << ret.top().first << " " << ret.top().second << "\n";
        ret.pop();
    }
    */
}

int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N;

    info tmp;
    for (int i=0; i<N; ++i)
    {
        cin >> tmp.ar_time >> tmp.vw_time;
        tmp.number = i+1;
        arrival_q.push(tmp);
    }

    /*
    while (!arrival_q.empty())
    {
        tmp = arrival_q.top(); arrival_q.pop();
        cout << tmp.number << " " << tmp.ar_time << "\n";
    }
    */

    solution();

    return 0;
}
