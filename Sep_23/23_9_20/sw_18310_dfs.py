def dfs(start):
    # 방문처리
    visited[start] = 1
    # 출력
    print(start, end='')
    # 연결된 노드 확인
    for node in gp[start]:
        if not visited[node]:
            dfs(node)


# 입력
v, e = map(int, input().split())
nums = list(map(int, input().split()))
# 그래프 생성
gp = [[] for _ in range(v + 1)]
visited = [0] * (v + 1)
for i in range(e):
    x, y = nums[i*2], nums[i*2 + 1]
    gp[x].append(y)
    gp[y].append(x)
# 오름차순으로 정렬
for i in range(v + 1):
    gp[i].sort()
dfs(1)
