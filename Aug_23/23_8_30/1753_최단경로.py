import sys
from collections import deque

# input = sys.stdin.readline
sys.stdin = open('input.txt')


def bfs(pos1):
    q = deque()
    q.append(pos1)
    visited[pos1] = 1
    while q:
        now_loc = q.popleft()
        for i in gp[now_loc]:
            if visited[i] == 0:
                print(weight[now_loc][i])
                visited[i] = visited[now_loc] + weight[now_loc][i]
                q.append(i)
            else:
                visited[i] = min(visited[i], visited[now_loc] + weight[now_loc][i])


V, E = map(int, input().split())
R = int(input())
gp = [[] for _ in range(V + 1)]
visited = [0] * (V + 1)

# weight = [[0] * (V + 1) for _ in range(V + 1)]
weight = dict()

for _ in range(E):
    u, v, w = map(int, input().split())
    gp[u].append(v)
    try:
        weight[u].get(v, 0)
        if weight[u][v] > w:
            weight[u][v] = w
    except KeyError:
        weight[u] = {v: w}

print(weight)

bfs(R)

for i in range(1, V+1):
    if i == 1:
        print(0)
    elif visited[i] == 0:
        print('INF')
    else:
        print(visited[i] - 1)
