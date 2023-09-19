import sys
sys.stdin = open('input.txt')


def find_ans(cnt, now_val):
    global res

    if res > now_val:
        return

    if sum(visited) == n:
        res = max(res, now_val)
        return

    for i in range(n):
        if p[cnt][i]:
            if not visited[i]:
                visited[i] = 1
                find_ans(cnt + 1, now_val * (p[cnt][i]*0.01))
                visited[i] = 0


T = int(input())
for tc in range(1, T+1):
    n = int(input())
    p = [list(map(int, input().split())) for _ in range(n)]
    visited = [0] * n
    res = -1
    find_ans(0, 1)
    print(f'#{tc} {res*100:6f}')
