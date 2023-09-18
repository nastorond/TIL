import sys

sys.stdin = open('input.txt')


# 직전에 왼쪽을 확인했는지 오른쪽을 확인했는지 체크해줄 flag 도 함께 선언
def bin_search(left, right, key, flg):
    if left > right:
        return 0

    mid = (left + right) // 2

    if sorted_list[mid] == key:
        return 1
    elif sorted_list[mid] > key:
        # 조건에 따라 같은 방향으로 한번 더 탐색하면 실패
        if flg == 'L':
            return 0
        # 왼쪽으로 들어갔다고 표시
        return bin_search(left, mid - 1, key, 'L')
    else:
        if flg == 'R':
            return 0
        return bin_search(mid + 1, right, key, 'R')


T = int(input())
for tc in range(1, T+1):
    n, m = map(int, input().split())
    sorted_list = list(map(int, input().split()))
    sorted_list.sort()
    targets = list(map(int, input().split()))
    cnt = 0

    for target in targets:
        cnt += bin_search(0, len(sorted_list) - 1, target, '')

    print(f'#{tc} {cnt}')
