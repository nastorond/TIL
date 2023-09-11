import sys
import heapq
input = sys.stdin.readline


def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, node = heapq.heappop(q)
        if distance[node] < dist:
            continue
        for i in gp[node]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))


V, E = map(int, input().split())
R = int(input())
gp = [[] for _ in range(V + 1)]
distance = [1e9] * (V + 1)
for _ in range(E):
    u, v, w = map(int, input().split())
    gp[u].append((v, w))

dijkstra(R)

for i in range(1, V+1):
    if distance[i] == 1e9:
        print('INF')
    else:
        print(distance[i])
