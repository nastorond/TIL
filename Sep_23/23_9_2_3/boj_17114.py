import sys
from collections import deque

# input = sys.stdin.readline

dw = [1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
dv = [0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
du = [0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
dt = [0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
ds = [0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
dr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
dq = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0]
dp = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0]
do = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0]
dn = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0]
dm = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1]


def bfs():
    que = deque()
    zero_cnt = 0
    cnt = 0
    for mw in range(w):
        for mv in range(v):
            for mu in range(u):
                for mt in range(t):
                    for ms in range(s):
                        for mr in range(r):
                            for mq in range(q):
                                for mp in range(p):
                                    for mo in range(o):
                                        for mn in range(n):
                                            for mm in range(m):
                                                if tomatoes[mw][mv][mu][mt][ms][mr][mq][mp][mo][mn][mm] == 1:
                                                    que.append((mw, mv, mu, mt, ms, mr, mq, mp, mo, mn, mm, 0))
                                                if tomatoes[mw][mv][mu][mt][ms][mr][mq][mp][mo][mn][mm] == 0:
                                                    zero_cnt += 1
    while que:
        n11, n10, n9, n8, n7, n6, n5, n4, n3, n2, n1, cnt = que.popleft()
        for idx in range(len(dw)):
            d11 = n11 + dw[idx]
            d10 = n10 + dv[idx]
            d9 = n9 + du[idx]
            d8 = n8 + dt[idx]
            d7 = n7 + ds[idx]
            d6 = n6 + dr[idx]
            d5 = n5 + dq[idx]
            d4 = n4 + dp[idx]
            d3 = n3 + do[idx]
            d2 = n2 + dn[idx]
            d1 = n1 + dm[idx]
            d_cnt = cnt + 1
            if 0 <= d11 < w and 0 <= d10 < v and 0 <= d9 < u and 0 <= d8 < t and 0 <= d7 < s and 0 <= d6 < r and 0 <= d5 < q and 0 <= d4 < p and 0 <= d3 < o and 0 <= d2 < n and 0 <= d1 < m:
                if tomatoes[d11][d10][d9][d8][d7][d6][d5][d4][d3][d2][d1] == 0:
                    tomatoes[d11][d10][d9][d8][d7][d6][d5][d4][d3][d2][d1] = 1
                    que.append((d11, d10, d9, d8, d7, d6, d5, d4, d3, d2, d1, d_cnt))
                    zero_cnt -= 1

    if zero_cnt > 0:
        return -1

    return cnt


m, n, o, p, q, r, s, t, u, v, w = map(int, input().split())

tomatoes = [[[[[[[[[[list(map(int, input().split())) for _ in range(n)] for _ in range(o)] for _ in range(p)] for _ in
                  range(q)] for _ in range(r)] for _ in range(s)] for _ in range(t)] for _ in range(u)] for _ in
             range(v)] for _ in range(w)]

print(bfs())
