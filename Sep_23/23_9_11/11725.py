import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


def dfs(pos1):
    for i in tree[pos1]:
        if not visited[i]:
            visited[i] = pos1
            dfs(i)


n = int(input())

visited = [0]*(n+1)
tree = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    tree[u].append(v)
    tree[v].append(u)

visited[1] = 1
dfs(1)

for i in range(2, n+1):
    print(visited[i])
