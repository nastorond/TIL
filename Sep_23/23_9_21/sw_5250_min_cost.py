import sys
import heapq

sys.stdin = open('input.txt')


# 다익스트라 구현
def find_min_cost():
    pq = []
    heapq.heappush(pq, (0, 0, 0))
    visited[0][0] = 0
    while pq:
        w, x, y = heapq.heappop(pq)

        for dx, dy in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < n:
                # 조건에 따라 이전 값에 + 1
                cost = visited[x][y] + 1

                # 오르막길인 경우 가중치 추가
                if fld[nx][ny] > fld[x][y]:
                    cost += fld[nx][ny] - fld[x][y]

                if cost < visited[nx][ny]:
                    visited[nx][ny] = cost
                    heapq.heappush(pq, (cost, nx, ny))


T = int(input())
for tc in range(1, T + 1):
    n = int(input())
    fld = [list(map(int, input().split())) for _ in range(n)]
    visited = [[1e9] * n for _ in range(n)]

    find_min_cost()

    # for i in visited:
    #     print(i)

    print(f'#{tc} {visited[n-1][n-1]}')
