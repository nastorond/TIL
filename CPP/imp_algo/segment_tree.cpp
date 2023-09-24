#include <iostream>
#include <vector>
#include <math.h>

#define MAX 1000000

using namespace std;

int n, m, k;

long long arr[MAX];

long long init(vector<long long> &segTree, int node, int start, int end){
    // 현재 노드가 리프노드인 경우
    if (start == end){ 
        // 배열에서 같은 인덱스 값을 가지는 원소를 가져야 함
        return segTree[node] = arr[start]; 
    }

    int mid = (start + end) / 2;

    // 구간 합을 구하는 경우
    // too few arguments in function call 파라미터 개수가 부족한 오류
    return segTree[node] = init(segTree, node * 2, start, mid) + init(segTree, node * 2 + 1, mid + 1, end);
}

void updateTree(vector<long long> &segTree, int node, int start, int end, int idx, long long diff){
    if (idx < start || idx > end) return ;
    segTree[node] += diff;
    if (start != end){
        int mid = (start + end) / 2;
        updateTree(segTree, node*2, start, mid, idx, diff);
        updateTree(segTree, node*2+1, mid+1, end, idx, diff);
    }
}

int sumTree(vector <long long> &segTree, int node, int left, int right, int start, int end){
    if (left <= start && end <= right) return segTree[node];

    if (right < start || end < left) return 0;

    int mid = (start + end) / 2;
    return sumTree(segTree,node*2, left, right, start, mid) + sumTree(segTree,node*2+1, left, right, mid+1, end);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int treeDepth = ceil(log2(n));
    int treeSize = 1 << (treeDepth + 1);

    vector <long long> segTree(treeSize);

    init(segTree, 1, 0, n-1);

    for (int i=0; i<m+k; i++){
        int order, left;
        long long right;
        cin >> order >> left >> right;
        if (order == 1){
            updateTree(segTree, 1, 0, n-1, left-1, right-arr[left-1]);
            arr[left - 1] = right;
        }else{
            cout << sumTree(segTree, 1, left-1, right-1, 0, n-1) << "\n";
        }
    }
    return 0;
}