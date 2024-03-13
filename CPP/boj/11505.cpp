// segTree with product
#include <iostream>
#include <vector>
#include <math.h>
#define MAX_VAL 1000030
#define PROB_CONDITION 1000000007

using namespace std;

int n, m, k;
long long arr[MAX_VAL];
// vector<long long> tree(MAX_VAL);

long long init(vector<long long> &tree, int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];

    int mid = (start + end) / 2;
    return tree[node] = (init(tree, node*2, start, mid) * init(tree, node*2+1, mid+1, end)) % PROB_CONDITION;
}

long long product(vector<long long> &tree, int node, int left, int right, int start, int end) {
    if (left > end || right < start) return 1;
    if (left <= start && right >= end) return tree[node];

    int mid = (start + end) / 2;

    return (product(tree, node*2, left, right, start, mid) * product(tree, node*2+1, left, right, mid+1, end)) % PROB_CONDITION;
}

void update(vector<long long> &tree, int node, int start, int end, int idx, long long value) {
    if (idx < start || idx > end) return ;

    if (start != end) {
        int mid = (start+end) / 2;
        update(tree, node*2, start, mid, idx, value);
        update(tree, node*2+1, mid+1, end, idx, value);
        tree[node] = (tree[node*2] * tree[node*2+1]) % PROB_CONDITION;
    } else {
        tree[node] = value;
    }
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m >> k;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int h = ceil(log2(n));
    int treeSize = 1 << (h + 1);

    vector<long long> tree(treeSize);

    init(tree, 1, 0, n-1);
    int a, b;
    long long c;
    for (int i=0; i<m+k; i++) {
        cin >> a >> b >> c;
        if (a==1) {
            update(tree, 1, 0, n-1, b-1, c);
            arr[b-1] = c;
        } else {
            cout << product(tree, 1, b-1, c-1, 0, n-1) << "\n";
        }
    }

    return 0;
}