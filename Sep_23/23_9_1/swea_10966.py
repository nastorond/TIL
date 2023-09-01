import sys
from collections import deque

sys.stdin = open('input.txt')

di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]


# 땅을 찾는 함수
def find_land(row, col):
    q = deque()
    # visited 를 -1 로 초기화 해서 계산 편하게
    visited = [[-1] * col for _ in range(row)]

    # 물에서 부터 탐색
    for x in range(row):
        for y in range(col):
            if fld[x][y] == 'W':
                q.append([x, y])
                visited[x][y] = 0
    while q:
        dx, dy = q.popleft()
        for i in range(4):
            ni, nj = dx + di[i], dy + dj[i]
            if 0 <= ni < row and 0 <= nj < col and fld[ni][nj] == 'L' and visited[ni][nj] == -1:
                visited[ni][nj] = visited[dx][dy] + 1
                q.append([ni, nj])
    res = 0
    # 모든 W는 0이고, L 은 숫자가 되니까 그냥 더하면댐
    for i in visited:
        # print(i)
        res += sum(i)
    return res


T = int(input())
for tc in range(1, T + 1):
    n, m = map(int, input().split())
    fld = [input().rstrip() for _ in range(n)]

    print(f'#{tc} {find_land(n, m)}')
