import sys
from collections import deque
sys.stdin = open('input.txt')


def bfs(start):
    q = deque()
    q.append(start)
    visited[start] = 1
    while q:
        now_node = q.popleft()
        for node in gp[now_node]:
            if not visited[node]:
                visited[node] = visited[now_node] + 1
                q.append(node)


for tc in range(1, 11):
    e, r = map(int, input().split())
    edges = list(map(int, input().split()))

    gp = [[] for _ in range(101)]
    visited = [0] * 101
    for idx in range(e//2):
        u, v = edges[idx*2], edges[idx*2+1]
        # 단방향 연결
        gp[u].append(v)

    bfs(r)
    
    # 최대값 탐색
    max_num = max(visited)
    # visited 배열에서 뒤에서부터 탐색해 가장 큰 수가 나오면 출력
    for i in range(100, -1, -1):
        if visited[i] == max_num:
            print(f'#{tc} {i}')
            break
