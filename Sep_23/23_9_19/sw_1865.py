import sys
sys.stdin = open('input.txt')


def find_ans(cnt, now_val):
    global res1

    #  확률은 곱할수록 작아지므로 지금값보다 작으면 더이상 확인하지 않는다.
    if res > now_val:
        return
    
    # 끝까지 도달하면 값 업데이트
    if sum(visited) == n:
        res = max(res, now_val)
        return
    
    # 경우의 수 나누기
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
    res1 = -1
    find_ans(0, 1)
    print(f'#{tc} {res1 * 100:6f}')
