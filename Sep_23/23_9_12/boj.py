n, m = map(int, input().split())
nums = list(range(1, n*m + 1))

for i in range(n):
    print(*nums[m*i: m*i + m])