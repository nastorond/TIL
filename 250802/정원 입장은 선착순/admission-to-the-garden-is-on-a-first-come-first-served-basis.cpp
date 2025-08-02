#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#define pii pair<int, int>
#define tiii tuple<int, int, int>

using namespace std;

int N;
int base_time=0;

struct compare
{
    bool operator()(tiii a, tiii b)
    {
        if ((get<0>(a) < base_time && get<0>(b) < base_time) || get<0>(a) == get<0>(b))
        {
            return get<2>(a) > get<2>(b);
        }
        return get<0>(a) > get<0>(b);
    }
};

priority_queue<tiii, vector<tiii>, compare> pq;
priority_queue<pii> ret;

void solution()
{
    auto tmp = pq.top(); pq.pop();
    base_time += get<1>(tmp);
    base_time += get<0>(tmp);

    while (!pq.empty())
    {
        // cout << get<0>(pq.top()) << " " << get<1>(pq.top()) << " " << get<2>(pq.top()) << "\n";
        tmp = pq.top(); pq.pop();
        while (!pq.empty())
        {
            auto tmp2 = pq.top();
            if (get<0>(tmp2) < base_time && get<2>(tmp2) < get<2>(tmp))
            {
                pq.pop();
                pq.push(tmp);
                swap(tmp, tmp2);
            }
            else
            {
                break;
            }
        }

        int delay_time = 0;
        if (base_time < get<0>(tmp))
        {
            base_time = get<0>(tmp);
        }
        else
        {
            delay_time = base_time - get<0>(tmp);
        }

        base_time += get<1>(tmp);
        ret.push(make_pair(delay_time, get<2>(tmp)));
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

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N;

    int a, t;
    for (int i=0; i<N; ++i)
    {
        cin >> a >> t;
        pq.push(make_tuple(a, t, i+1));
    }

    solution();

    return 0;
}
