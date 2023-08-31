import sys

sys.stdin = open('input.txt')

T = int(input())
for tc in range(1, T+1):
    # 입력
    n = int(input())
    ck = [[0, 0]] + [list(map(int, input().split())) for _ in range(n)]

    # 종료시간 기준 정렬
    ck.sort(key=lambda x: x[1])

    res = 0
    j = 0
    # 조건에 맞는 경우 카운트
    for i in range(1, n+1):
        if ck[i][0] >= ck[j][1]:
            res += 1
            j = i

    print(f'#{tc} {res}')
