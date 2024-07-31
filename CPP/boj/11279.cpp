#include <bits/stdc++.h>
#define MAX 1000005

using namespace std;

int heap[MAX];
int heapCnt = 0;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void push(int num) {
    heap[++heapCnt] = num;

    int chd = heapCnt;
    int par = chd/2;

    while (chd > 1 && heap[chd] > heap[par]) {
        swap(&heap[chd], &heap[par]);
        chd = par;
        par = chd/2;
    }
}

int pop() {
    int res = heap[1];
    swap(&heap[1], &heap[heapCnt]);
    heapCnt -= 1;

    int par = 1;
    int chd = par*2;

    if (chd + 1 <= heapCnt) {
        chd = (heap[chd] > heap[chd+1]) ? chd : chd+1;
    }

    while (chd <= heapCnt && heap[chd]>heap[par]) {
        swap(&heap[chd], &heap[par]);
        par = chd;
        chd = par*2;

        if (chd + 1 <= heapCnt) {
            chd = (heap[chd]>heap[chd+1]) ? chd : chd+1;
        }
    }

    return res;
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) {
            if (heapCnt == 0) cout << 0 << "\n";
            else {
                int num = pop();
                cout << num << "\n";
            }
        } else {
            push(tmp);
        }
    }

}