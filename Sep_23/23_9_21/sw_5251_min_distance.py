import sys
import heapq

sys.stdin = open('input.txt')


# 데이크스트라 구현
def dijkstra():
    pq = []
    heapq.heappush(pq, (0, 0))
    dist[0] = 0
    while pq:
        distance, now = heapq.heappop(pq)
        
        # 도착지에 도달하면 종료
        if now == N:
            return dist[N]
        
        # distance 값이 더 크면 더 볼 필요 없음
        if distance > dist[now]:
            continue

        for idx in gp[now]:
            cost = dist[now] + idx[1]
            if cost < dist[idx[0]]:
                dist[idx[0]] = cost
                heapq.heappush(pq, (cost, idx[0]))


T = int(input())
for tc in range(1, T+1):
    N, E = map(int, input().split())
    gp = [[] for _ in range(N + 1)]
    dist = [1e9] * (N+1)
    for _ in range(E):
        u, v, w = map(int, input().split())
        gp[u].append([v, w])

    print(f'#{tc} {dijkstra()}')
