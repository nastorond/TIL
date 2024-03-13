#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define MAX_LEN 1000030

using namespace std;

int N, M, K;
vector<long long> arr;
vector<long long> tree;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a, b, tree_size;
    long long c;

    cin >> N >> M >> K;

    tree_size = (int)ceil(log2(N));
    fill(tree.begin(), tree.begin() + tree_size, 0);

    for (int i=0; i<M; i++) {
        cin >> c;
        arr.push_back(c);
    }
}
