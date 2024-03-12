// Segment Tree
/*
* 1. 배열이 A[N]의 배열이 존재할 때,
* 순서쌍 (i, j)에 대하여 A[i], ..., A[j] 중 최솟 값을 찾는 경우, A[i] 부터 A[j] 까지 순회하면서 찾는 것이 가장 단순한 방법임
* 이 경우 시간복잡도는 O(N)임
* 이런 연산이 Q개 주어지고 N과 Q의 범위가 1 ~ 10만 이면, 시간복잡도가 O(NQ)라서 오래걸림
* 2. 구간 [l, r](l<=r)이 주어질 때,
* A[l] + A[l+1] + ... + A[r-1] + A[r] 을 구한뒤, i번째 수를 v로 바꾼다. 이 과정을 M번만큼 반복한다.
* 각각 O(N), O(1)이므로, M번 수행하는 경우 시간복잡도는 O(MN + M) 이 된다
* 1은 RMQ(Range Minimum Query), 2는 구간 합을 구하는 문제로써 세그먼트트리를 이용해 효율적으로 구할 수 있다.
* O(QlogN)
* 세그먼트트리는 Full binary tree 에 가깝기 때문에 배열에 모든 값이 대부분 가득 차게 된다.
* 배열의 크기 => h = (int)ceil(log2(n))
* 트리 사이즈 => tree_size = (1 << (h+1));
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

long long init(vector<long long> &arr, vector<long long> &tree, int node, int start, int end) {
    if (start == end) // 노드가 리프 노드인 경우
        return tree[node] = arr[start]; // 배열의 그 원소를 가져야 함

    int mid = (start + end) / 2;

    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
    // 구간의 최솟값을 구하는 경우
    // return tree[node] = min(arr, tree, node * 2, start, mid), init(arr, tree, node * 2 + 1, mid + 1, end);
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    // case 1: [start, end] 앞 뒤에 [left, right]가 있는 경우
    // 겹치지 않기 때문에 탐색을 더 이상 할 필요가 없다
    if (left > end || right < start) return 0;

    // case 2: [start, end] 가 [left, right]에 포함
    if (left <= start && end <= right) return tree[node];

    // case 3, 4: 왼쪽 자식과 오른쪽 자싱을 루트로 하는 트리에서 다시 탐색
    int mid = (start + end) / 2;
    return sum(tree, node*2, start, mid, left, right) + sum(tree, node*2+1, mid+1, end, left, right);
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return ;
    tree[node] = tree[node] + diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, node*2, start, mid, index, diff);
        update(tree, node*2+1, start, end, index, diff);
    }
}

int n = 10;
int h = (int)ceil(log2(n));
int tree_size = (1 << (h+1));

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    
}