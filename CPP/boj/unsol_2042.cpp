#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define MAX_LEN 1000030

using namespace std;

int N, M, K;
vector<long long> arr;
vector<long long> tree;

long long init (int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];

    int mid = (start  + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

long long sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid+1 ,end, left, right);
}

void update(int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return ;
    tree[node] = tree[node] + diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a, b, h, tree_size;
    long long c;

    cin >> N >> M >> K;

    h = (int)ceil(log2(N));
    tree_size = (1 << (h + 1));
    for (int i=0; i<tree_size; i++) {
        tree.push_back(0);
    }

    for (int i=0; i<N; i++) {
        cin >> c;
        arr.push_back(c);
    }

    init(1, 0, N-1);

    for (int i=0; i<M; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            long long diff = arr[b] - c;
            arr[b] = c;
            update(1, 1, tree_size, b, diff);
        }
        else {
            int tmp = (int)c;
            cout << sum(1, 1, tree_size, b, (int)c) << "\n";
        }        
    }
}
