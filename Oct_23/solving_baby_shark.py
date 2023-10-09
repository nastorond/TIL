# BOJ_16236 : 아기 상어
import sys
from collections import deque

input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]


def bfs_16236(x, y):
    global n, eating, distance, shark_size
    visited = [([False] * n) for _ in range(n)]

    q = deque()
    q.append([x, y, 0])
    visited[x][y] = True
    while q:
        x, y, dist = q.popleft()
        
        for p in range(4):
            nx, ny = x + dx[p], y + dy[p]
            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny]:
                visited[nx][ny] = True

                # 그냥 지나 갈 경우
                if not arr[nx][ny] or arr[nx][ny] == shark_size:
                    q.append([nx, ny, dist + 1])

                # 물고기를 잡아 먹었을 경우
                elif arr[nx][ny] and arr[nx][ny] < shark_size:
                    arr[nx][ny] = 0
                    eating += 1
                    if shark_size == eating:
                        eating = 0
                        shark_size += 1
                    distance += dist + 1

                    # 순간이동
                    q.clear()
                    q.append([nx, ny, 0])
                    visited = [([False] * n) for _ in range(n)]
                    break


n = int(input())


arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

eating, distance = 0, 0
shark_size = 2
for i in range(n):
    for j in range(n):
        if arr[i][j] == 9:
            arr[i][j] = 0
            bfs_16236(i, j)

print(distance)