"""n, m = map(int, input().split())
if n == 1:
    A = int(input())
    res1 = 1
else:
    A = list(map(int, input().split()))
    A.sort()
    res1 = 1
    cnt = A[0]
    cool = False
    for i in range(len(A)):
        if cool:

        if A[i] - cnt >= 100:
            res1 += 1
            cnt += A[i]

if m == 1:
    B = int(input())
    res = 1
else:
    B = list(map(int, input().split()))
    B.sort()
    res = 1
    cnt = B[0]
    for i in range(len(B)):
        if B[i] - cnt >= 360:
            res += 1
            cnt += B[i]

print(res1, res)"""

"""n, m, k = map(int, input().split())
ch = [int(input()) for _ in range(n)]
boss_reward = [list(map(int, input().split())) for _ in range(k)]
ch.sort(reverse=True)
boss_reward.sort(key=lambda x:-x[1])
sec = [900 for _ in range(m)]
print(ch, sec, boss_reward)"""