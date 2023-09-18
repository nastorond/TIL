import sys

sys.stdin = open('input.txt')


def partition(left, right):
    p = a[left]
    i, j = left, right
    while i <= j:
        while i <= j and a[i] <= p:
            i += 1
        while i <= j and a[j] >= p:
            j -= 1
        if i < j:
            a[i], a[j] = a[j], a[i]

    a[left], a[j] = a[j], a[left]
    return j


def quick_sort(left, right):
    if left < right:
        pivot = partition(left, right)
        quick_sort(left, pivot - 1)
        quick_sort(pivot + 1, right)


T = int(input())
for tc in range(1, T+1):
    N = int(input())
    a = list(map(int, input().split()))
    quick_sort(0, len(a) - 1)
    print(f'#{tc} {a[N // 2]}')
