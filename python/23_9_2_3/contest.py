"""
scores = {'A+': 4.5, 'A': 4.0, 'B+': 3.5, 'B': 3.0, 'C+': 2.5, 'C': 2.0, 'D+': 1.5, 'D': 1.0, 'F': 0}

score = deque(input().rstrip())

num = 0
res = 0
while score:
    rank = score.popleft()
    if len(score):
        if score[0] == '+':
            rank += score.popleft()

    res += scores[rank]
    num += 1

print(res/num)
"""
import sys
from collections import deque
# input = sys.stdin.readline

n, m = map(int, input().split())
lis = [0] * n
for _ in range(m):
    a, b, x = map(int, input().split())
    for i in range(a-1, b):
        if not lis[i]:
            lis[i] = x
print(*lis)
