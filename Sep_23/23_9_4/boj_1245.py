import sys
from collections import deque
# input = sys.stdin.readline


def bfs(x, y):
    q = deque()
    q.append([x, y])
    visited[x][y] = 1
    while q:
        dx, dy = q.popleft()
        for di, dj in [[0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1], [-1, 0], [-1, 1]]:
            ni, nj = dx + di, dy + dj
            if 0 <= ni < n and 0 <= nj < m and fld[ni][nj] and not visited[ni][nj]:
                if fld[dx][dy] < fld[ni][nj]:
                    return 0
                q.append([ni, nj])
                visited[ni][nj] = 1
    return 1


n, m = map(int, input().split())
fld = [list(map(int, input().split())) for _ in range(n)]
visited = [[0] * m for _ in range(n)]

res1 = 0
for i in range(n):
    for j in range(m):
        if not visited[i][j] and fld[i][j]:
            res1 += bfs(i, j)
print(res1)
