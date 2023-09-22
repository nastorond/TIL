import sys
sys.stdin = open('input.txt')


# 부모찾기
def find_set(x):
    if x == parents[x]:
        return x

    parents[x] = find_set(parents[x])
    return parents[x]


# 합치기
def union(x, y):
    x = find_set(x)
    y = find_set(y)

    if x == y:
        return

    if x < y:
        parents[y] = x
    else:
        parents[x] = y


T = int(input())
for tc in range(1, T+1):
    # 입력
    n, m = map(int, input().split())
    parents = [i for i in range(n+1)]
    for _ in range(m):
        # 입력받은 거 연결
        u, v = map(int, input().split())
        union(u, v)

    cnt = 0
    for i in range(1, n+1):
        if i == parents[i]:
            cnt += 1

    print(f'#{tc} {cnt}')
