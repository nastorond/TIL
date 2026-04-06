#include <iostream>
#include <vector>

using namespace std;
using int64 = long long;
const int64 INF = (int64)4e18;

struct Node {
    int64 need; // |v| + 1
    int64 v;
};

int n;
vector<int64> a;

// x로 시작했을 때, 최대 몇 개까지 흡수 가능한지
int maxAbsorbCount(int64 x) {
    int64 cur = x;
    int cnt = 0;

    vector<Node> arr;
    arr.reserve(n);
    for (int i = 0; i < n; ++i) {
        int64 v = a[i];
        int64 need = (v >= 0 ? v + 1 : 1 - v);
        arr.push_back({need, v});
    }

    sort(arr.begin(), arr.end(), [](const Node& A, const Node& B) {
        if (A.need != B.need) return A.need < B.need;
        return A.v > B.v; // need 같다면 v 큰 것 먼저 들어오게
    });

    // pq: 현재 흡수 가능(need <= cur)한 후보들 중 v가 큰 것부터
    priority_queue<int64> pq;

    int idx = 0;
    while (true) {
        // 현재 cur로 흡수 가능한 것들 pq에 추가
        while (idx < n && arr[idx].need <= cur) {
            pq.push(arr[idx].v);
            idx++;
        }

        if (pq.empty()) break; // 더 먹을 수 있는 게 없다

        int64 v = pq.top(); pq.pop();

        // v를 흡수하면 cur' = cur + v 가 되고, 이때도 cur' >= 1 이어야 한다.
        if (cur + v < 1) {
            // 이 v는 지금 먹으면 죽으니까 포기.
            // 하지만 pq 안에 있는 다른 v들은 need <= cur였으므로
            // v가 가장 큰데도 죽는다면 나머지도 다 죽음.
            break;
        }

        cur += v;
        cnt++;
    }

    return cnt;
}

// t개 흡수 가능한 최소 x_t 를 이분 탐색으로 찾기
int64 minStartForT(int t) {
    int64 lo = 1, hi = (int64)1e13;
    int64 ans = -1;

    // 먼저 hi로도 t개 못 먹는다면 -1
    if (maxAbsorbCount(hi) < t) return -1;

    while (lo <= hi) {
        int64 mid = (lo + hi) / 2;
        int got = maxAbsorbCount(mid);
        if (got >= t) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int64> res(n);
    for (int t = 1; t <= n; ++t) {
        res[t-1] = minStartForT(t);
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << (i+1 == n ? '\n' : ' ');
    }
    return 0;
}