import sys
import heapq

sys.stdin = open('input.txt')

"""
# 플로이드 워셜의 경우 전체 탐색을 돌리면 n**3 의 시간을 가져서 제한시간 내에 불가
T = int(input())
for tc in range(1, T+1):
    N, M, X = map(int, input().split())
    gp = [[1e9]*(N+1) for _ in range(N + 1)]
    
    # 플로이드 워셜 구현
    for _ in range(M):
        u, v, w = map(int, input().split())
        gp[u][v] = w
    
    for i in range(1, N + 1):
        gp[i][i] = 0

    for k in range(1, N+1):
        for i in range(1, N+1):
            for j in range(1, N+1):
                gp[i][j] = min(gp[i][j], gp[i][k] + gp[k][j])

    res = 0
    for i in range(1, N+1):
        res = max(res, gp[i][X] + gp[X][i])

    print(f'#{tc} {res}')
"""


def dijkstra(start):
    pq = []
    dist = [1e9] * (V + 1)
    heapq.heappush(pq, (0, start))
    while pq:
        distance, now = heapq.heappop(pq)

        if distance > dist[now]:
            continue

        for loc, weight in gp[now]:
            cost = distance + weight
            if cost < dist[loc]:
                dist[loc] = cost
                heapq.heappush(pq, (cost, loc))

    # 시작점과 인수네 집 위치가 동일하면 전부 꺼낸다.
    if start == X:
        return dist
    return dist[X]


T = int(input())
for tc in range(1, T+1):
    V, E, X = map(int, input().split())
    gp = [[] for _ in range(V + 1)]
    for _ in range(E):
        u, v, w = map(int, input().split())
        gp[u].append([v, w])

    """ 
    idea
    max(x 에서 가는거 + X 로 오는거 따로 구해서 합)
    """
    
    # 인수네 집을 기준으로 Distances 를 받음
    res = dijkstra(X)
    
    # 그 외에 집에서 출발한 집에서 인수네 집까지의 거리를 받아
    # 인수네 집에서 가는 거리를 더한다
    for idx in range(1, V + 1):
        if X == idx:
            continue
        res[idx] += dijkstra(idx)
    
    # 최대값 출력
    print(f'#{tc} {max(res[1:])}')
