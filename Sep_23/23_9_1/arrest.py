import sys
from collections import deque

sys.stdin = open('input.txt')


def bfs(x, y):
    q = deque()
    q.append([x, y])
    visited[x][y] = 0
    while q:
        dx, dy = q.popleft()
        for di, dj in [[0,1],[1,0],[0,-1],[-1,0]]:
            ni, nj = dx+di, dy+dj
            if 0<=ni<N and 0<=nj<M and fld[ni][nj] and visited[ni][nj] == -1:
                pass


T = int(input())
for tc in range(1, T+1):
    N, M, R, C, L = map(int, input().split())
    fld = [list(map(int, input().split())) for _ in range(N)]
    visited = [[-1] * M for _ in range(N)]
