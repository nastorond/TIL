#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define MAX_LEN 1000030
typedef long long ll;

using namespace std;

int N, M, K;
vector<ll> arr;
vector<ll> tree;

int init (int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];

    int mid = (start  + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a, b, h, tree_size;
    ll c;

    cin >> N >> M >> K;

    h = (int)ceil(log2(N));
    tree_size = (1 << (h + 1));
    fill(tree.begin(), tree.begin() + tree_size, 0);

    for (int i=0; i<M; i++) {
        cin >> c;
        arr.push_back(c);
    }
}
