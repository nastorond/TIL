import sys
import heapq
input = sys.stdin.readline


def find_cost(start):
    q = []
    heapq.heappush(q, (start, 0))
    distance[start] = 0
    while q:
        now, cost = heapq.heappop(q)
        if cost > distance[now]:
            continue
        for i in gp[now]:
            add_cost = cost + i[1]
            if add_cost < distance[i[0]]:
                distance[i[0]] = add_cost
                heapq.heappush(q, (i[0], add_cost))


n = int(input())
m = int(input())
gp = [[] for _ in range(n+1)]
distance = [1e9] * (n+1)
for _ in range(m):
    u, v, w = map(int, input().split())
    gp[u].append((v,w))
start, goal = map(int, input().split())

find_cost(start)

print(distance[goal])
