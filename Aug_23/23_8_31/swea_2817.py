import sys

sys.stdin = open('input.txt')


def ck_num(cnt, sum_val):
    global res
    if sum_val == k:
        res += 1
        return
    if cnt == n:
        return
    ck_num(cnt + 1, sum_val + nums[cnt])
    ck_num(cnt + 1, sum_val)


T = int(input())
for tc in range(1, T + 1):
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    res = 0
    ck_num(0, 0)
    print(f'#{tc} {res}')
