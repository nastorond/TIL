import sys
from collections import deque
sys.stdin = open('input.txt')

# union-find

"""
# bfs 이용해서 연결되어 있는지 확인
def bfs(start):
    q = deque()
    q.append(start)
    # 시작점도 방문처리
    visited[start] = start
    while q:
        now = q.popleft()
        for node in gp[now]:
            if not visited[node]:
                q.append(node)
                # 시작노드의 인덱스로 방문처리
                visited[node] = start


T = int(input())
for tc in range(1, T+1):
    n, m = map(int, input().split())
    papers = list(map(int, input().split()))
    # 그래프 생성
    gp = [[] for _ in range(n+1)]
    visited = [0]*(n+1)
    for idx in range(m):
        u, v = papers[idx*2], papers[idx*2 + 1]
        gp[u].append(v)
        gp[v].append(u)

    res = 0
    for i in range(1, n + 1):
        # 방문한적 없던 곳만 방문
        if not visited[i]:
            bfs(i)
    
    # visited 에서 반복되는 수를 제거해 주고 개수를 세어주고 0 제거
    print(f'#{tc} {len(set(visited)) - 1}')
"""
