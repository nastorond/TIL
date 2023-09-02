import sys
from collections import deque


# input = sys.stdin.readline


def bfs():
    q = deque()
    for i in range(h):
        for j in range(n):
            for k in range(m):
                if tomatoes[i][j][k] == 1:
                    q.append([i, j, k])
                    visited[i][j][k] = 1
                if tomatoes[i][j][k] == -1:
                    visited[i][j][k] = 1
    while q:
        dz, dx, dy = q.popleft()
        for dk, di, dj in [[1, 0, 0], [-1, 0, 0], [0, 0, 1], [0, 1, 0], [0, 0, -1], [0, -1, 0]]:
            nz, nx, ny = dz + dk, dx + di, dy + dj
            if 0 <= nz < h and 0 <= nx < n and 0 <= ny < m and tomatoes[nz][nx][ny] == 0 and not visited[nz][nx][ny]:
                visited[nz][nx][ny] = visited[dz][dx][dy] + 1
                q.append([nz, nx, ny])

    for z in range(h):
        for x in range(n):
            for y in range(m):
                if visited[z][x][y] == 0:
                    return -1

    if visited[dz][dx][dy] == 1:
        return 0

    return visited[dz][dx][dy] - 1


m, n, h = map(int, input().split())
tomatoes = [[list(map(int, input().split())) for _ in range(n)] for _ in range(h)]
visited = [[[0] * m for _ in range(n)] for _ in range(h)]

print(bfs())
