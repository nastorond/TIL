// 최솟값과 최댓값
#include <iostream>
#include <vector>
#include <math.h>
#define MAX_VAL 100030

using namespace std;

int n, m;
long long arr[MAX_VAL];

long long init(vector<long long> &tree, int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    
    int mid = (start + end) / 2;
    
    return tree[node] = init(tree, node*2, start, mid) + init(tree, node*2+1, mid+1, end);
}

long long getMax(vector<long long> &tree, int node, int left, int right, int start, int end) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];

    int mid = (start + end) / 2;

    return max(getMax(tree, node*2, left, right, start, mid), getMax(tree, node*2+1, left, right, mid+1, end));
}

long long getMin(vector<long long> &tree, int node, int left, int right, int start, int end) {
    if (left > end || right < start) return 1e9;
    if (left <= start && right >= end) return tree[node];

    int mid = (start + end) / 2;

    return min(getMin(tree, node*2, left, right, start, mid), getMin(tree, node*2+1, left, right, mid+1, end));
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int a, b;
    int h = ceil(log2(n));
    int tree_size = 1 << (h+1);
    vector<long long> tree(tree_size);
    init(tree, 1, 0, n-1);
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        cout << getMin(tree, 1, a-1, b-1, 0, n-1) << " ";
        cout << getMax(tree, 1, a-1, b-1, 0, n-1) << "\n";
    }

    return 0;
}