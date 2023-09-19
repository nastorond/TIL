import sys
sys.stdin = open('input.txt')


def find_ans(now, now_val):
    global res
    # 유망성 확인
    if res < now_val:
        return
    # 끝까지 도달하면 결과값 갱신
    if sum(visited) == n:
        res = min(now_val, res)
        return
    # 경우의수 나누기
    for i in range(n):
        if not visited[i]:
            visited[i] = 1
            find_ans(now + 1, now_val + v[now][i])
            visited[i] = 0


T = int(input())
for tc in range(1, T+1):
    n = int(input())
    v = [list(map(int, input().split())) for _ in range(n)]
    visited = [0] * n
    res = 1e9
    find_ans(0, 0)
    print(f'#{tc} {res}')
