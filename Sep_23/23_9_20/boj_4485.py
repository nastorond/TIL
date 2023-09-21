import sys
from collections import deque
import heapq
input = sys.stdin.readline


# 실패
def bfs():
    q = deque()
    q.append([0, 0])
    visited[0][0] = fld[0][0]
    while q:
        x, y = q.popleft()
        # 후보자들 선정
        candidates = []
        for dx, dy in [[0, 1],[1, 0],[0, -1],[-1, 0]]:
            nx, ny = x+dx, y+dy
            if 0<=nx<n and 0<=ny<n and visited[nx][ny] == 1e6:
                heapq.heappush(candidates, (fld[nx][ny], nx, ny))
        while candidates:
            w, nx, ny = heapq.heappop(candidates)
            visited[nx][ny] = min(visited[x][y] + w, visited[nx][ny])
            q.append([nx, ny])


def dijkstra():
    q = []
    heapq.heappush(q, (fld[0][0], 0, 0))
    visited[0][0] = fld[0][0]
    while q:
        weight, x, y = heapq.heappop(q)

        # 추가로 주어질 가중치가 이미 가중되어있는 가중치 보다 크면 추가 안함
        if visited[x][y] < weight:
            continue
        for dx, dy in [[0, 1],[1, 0],[0, -1],[-1, 0]]:
            nx, ny = x+dx, y+dy
            if 0<=nx<n and 0<=ny<n and visited[nx][ny] == 1e6:
                cost = weight + fld[nx][ny]
                if cost < visited[nx][ny]:
                    visited[nx][ny] = cost
                    heapq.heappush(q, (cost, nx, ny))


tc = 0
while 1:
    n = int(input())
    if n == 0:
        break
    tc += 1
    visited = [[1e6]*n for _ in range(n)]
    fld = [list(map(int, input().split())) for _ in range(n)]

    # bfs()
    dijkstra()

    res = visited[n-1][n-1]

    if tc == 2:
        for i in visited:
            print(i)

    print(f'Problem {tc}: {res}')
