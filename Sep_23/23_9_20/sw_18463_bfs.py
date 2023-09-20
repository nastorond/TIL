from collections import deque


# bfs 함수
def bfs(start):
    q = deque()
    visited = [0] * (v + 1)
    visited[start] = 1
    q.append(start)
    while q:
        node = q.popleft()
        for nodes in gp[node]:
            if not visited[nodes]:
                visited[nodes] = 1
                res1.append(nodes)
                q.append(nodes)


# 입력
v, e = map(int, input().split())
nums = list(map(int, input().split()))
# 그래프 생성
gp = [[] for _ in range(v + 1)]
for i in range(e):
    x, y = nums[i*2], nums[i*2 + 1]
    gp[x].append(y)
    gp[y].append(x)
# 결과지 생성
res1 = [1]
bfs(1)
print(*res1)
