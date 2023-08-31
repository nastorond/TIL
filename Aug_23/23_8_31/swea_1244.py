import sys

sys.stdin = open('input.txt')

T = int(input())
for tc in range(1, T+1):
    inp = input().rstrip().split()
    change_num = int(inp[1])
    num = list(map(int, inp[0]))

    while change_num > 0:
        max_val, min_val = max(num), min(num)
        max_idx, min_idx = 0, num.index(min_val)

        for i in range(len(num), -1, -1):
            if num[i] == max_val:
                max_idx = i
                break

        num[max_idx], num[min_idx] = num[min_idx], num[max_idx]

    if tc == 1:
        print(change_num, num)
