// Segment Tree 의 기본 활용
#include <iostream>
#include <vector>
#include <math.h>
#define MAX_VAL 1000030

using namespace std;

int n, m, k;

long long arr[MAX_VAL];

// in Parameter : node(fixed as 1), start(fixed as 0), end(fixed as n-1)
// parameter : tree
// n : arr's length
long long init(vector<long long> &segTree, int node, int start, int end) {
    if (start == end) return segTree[node] = arr[start];

    int mid = (start + end) / 2;

    return segTree[node] = init(segTree, node*2, start, mid) + init(segTree, node*2+1, mid+1, end);
}

// parameter : tree, node number(fixed as 1), left(start point for part sum), right(end point for part sum)
long long sum(vector<long long> &segTree, int node, int left, int right, int start, int end) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return segTree[node];
    
    int mid = (start + end) / 2;

    return sum(segTree, node*2, left, right, start, mid) + sum(segTree, node*2+1, left, right, mid+1, end);
}

// parameter : tree, idx(index in arr), diff(new value - original value, type long long)
void update(vector<long long> &segTree, int node, int start, int end, int idx, long long diff) {
    if (idx < start || idx > end) return ;
    segTree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(segTree, node*2, start, mid, idx, diff);
        update(segTree, node*2+1, mid+1, end, idx, diff);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m >> k;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    int h = ceil(log2(n));
    int treeSize = 1 << (h+1);
    vector<long long> segTree(treeSize);

    init(segTree, 1, 0, n-1);
    for (int i=0; i < m + k; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(segTree, 1, 0, n-1, b-1, c-arr[b-1]);
            arr[b-1] = c;
        } else {
            cout << sum(segTree, 1, b-1, c-1, 0, n-1) << "\n";
        }
    }

    return 0;
}