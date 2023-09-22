import sys

sys.stdin = open('input.txt')


def recur(y, x, number):
    if len(number) == 7:
        res.add(number)
        return

    for dy, dx in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
        ny = y + dy
        nx = x + dx

        if ny < 0 or ny >= 4:
            continue
        if nx < 0 or nx >= 4:
            continue

        recur(ny, nx, number + maps[ny][nx])


T = int(input())
for tc in range(1, T + 1):
    maps = [input().split() for _ in range(4)]

    res = set()

    for i in range(4):
        for j in range(4):
            recur(i, j, '')

    print(f'#{tc} {len(res)}')
