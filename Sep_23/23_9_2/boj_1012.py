import sys
from collections import deque


# input = sys.stdin.readline


def bfs(x, y):
    q = deque()
    fld[x][y] = 0
    q.append([x, y])
    while q:
        dx, dy = q.popleft()
        for di, dj in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
            ni, nj = dx + di, dy + dj
            if 0 <= ni < n and 0 <= nj < m and fld[ni][nj]:
                q.append([ni, nj])
                fld[ni][nj] = 0
    return 1


T = int(input())
for _ in range(T):
    n, m, k = map(int, input().split())
    fld = [[0] * m for _ in range(n)]
    for _ in range(k):
        u, v = map(int, input().split())
        fld[u][v] = 1
    res = 0
    for i in range(n):
        for j in range(m):
            if fld[i][j]:
                res += bfs(i, j)
    print(res)
