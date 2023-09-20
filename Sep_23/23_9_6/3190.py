import sys
from collections import deque


def game():
    q = deque()
    q.append((0, 0))
    sec = 0
    direction = 0
    while 1:
        sec += 1
        x, y = direc[direction]
        nx, ny = q[0]
        dx, dy = x + nx, y + ny
        if 0 <= dx < n and 0 <= dy < n:
            if (dx, dy) in q:
                return sec
            if fld[dx][dy]:
                fld[dx][dy] = 0
            else:
                q.pop()
            q.appendleft((dx, dy))
        else:
            return sec

        if moving.get(sec, False):
            if moving[sec] == 'D':
                direction += 1
            else:
                direction -= 1
            direction %= 4


direc = [[0, 1], [1, 0], [0, -1], [-1, 0]]
# input = sys.stdin.readline
n = int(input())
fld = [[0] * n for _ in range(n)]
apple = int(input())
for _ in range(apple):
    u, v = map(int, input().split())
    fld[u - 1][v - 1] = 1
turn = int(input())
moving = {}
for _ in range(turn):
    inp = input().rstrip().split()
    moving[int(inp[0])] = inp[1]
res1 = game()
print(res1)
