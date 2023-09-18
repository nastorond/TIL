import sys
sys.stdin = open('input.txt')


def merge(left, right):
    global cnt

    if left[-1] > right[-1]:
        cnt += 1

    res = []

    len_l = len(left)
    len_r = len(right)

    left_index = right_index = 0

    while left_index < len_l and right_index < len_r:
        if left[left_index] <= right[right_index]:
            res.append(left[left_index])
            left_index += 1
        else:
            res.append(right[right_index])
            right_index += 1

    res.extend(left[left_index:])
    res.extend(right[right_index:])

    return res


def merge_sort(m):
    if len(m) == 1:
        return m

    mid = len(m)//2
    left, right = m[:mid], m[mid:]

    left = merge_sort(left)
    right = merge_sort(right)

    return merge(left, right)


T = int(input())
for tc in range(1, T+1):
    N = int(input())
    nums = list(map(int, input().split()))
    cnt = 0
    result = merge_sort(nums)

    print(f'#{tc} {result[N // 2]} {cnt}')
