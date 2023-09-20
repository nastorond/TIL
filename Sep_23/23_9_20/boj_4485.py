import sys
from collections import deque
import heapq
input = sys.stdin.readline


def bfs():
    q = deque()
    q.append([0, 0])
    visited[0][0] = 1
    while q:
        x, y = q.popleft()
        if x == n-1 and y == n-1:
            return visited[x][y]
        candidates = []
        for dx, dy in [[0, 1],[1, 0],[0, -1],[-1, 0]]:
            nx, ny = x+dx, y+dy
            if 0<=nx<n and 0<=ny<n and visited[nx][ny] == 0:
                heapq.heappush(candidates, (-fld[nx][ny], nx, ny))
        while candidates:
            w, nx, ny = heapq.heappop(candidates)
            visited[nx][ny] = visited[x][y] - w
            q.append([nx, ny])


tc = 0
while 1:
    n = int(input())
    if n == 0:
        break
    tc += 1
    visited = [[0]*n for _ in range(n)]
    fld = [list(map(int, input().split())) for _ in range(n)]

    res = bfs()

    print(f'Problem {tc}: {res}')
    