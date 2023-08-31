# [S/W 문제해결 응용] 2일차 - 최대 상금
import sys

sys.stdin = open('input.txt')


def back_track(cnt):
    global ans

    val = int(''.join(cards))
    if val in visited[cnt]:
        return

    visited[cnt].add(val)

    if cnt == k:
        ans = max(ans, val)
    else:
        for i in range(num - 1):
            for j in range(i + 1, num):
                cards[i], cards[j] = cards[j], cards[i]
                back_track(cnt + 1)
                cards[i], cards[j] = cards[j], cards[i]


T = int(input())
for tc in range(1, T+1):
    """
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
    """
    ans = 0
    arr = list(input().split())
    cards, k = list(arr[0]), int(arr[1])
    num = len(cards)
    visited = [set() for _ in range(11)]  # 최대 10회 교환

    back_track(0)
    
    print(f'#{tc} {ans}')
