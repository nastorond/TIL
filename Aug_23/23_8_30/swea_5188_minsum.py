import sys

sys.stdin = open('input.txt')


def sum_unit(x, y, min_sum):
    global ans
    # 끝에 도달하면 결과값 비교 후 변경
    if x == size - 1 and y == size - 1:
        if min_sum < ans:
            ans = min_sum
        return
    
    # 오른쪽과 아래로만 진행
    for di, dj in [[0, 1], [1, 0]]:
        ni, nj = di + x, dj + y
        # 유효한 수일 경우만 진행
        if 0 <= ni < size and 0 <= nj < size:
            # 필요한 경우만 탐색
            if min_sum <= ans:
                sum_unit(ni, nj, min_sum + fld[ni][nj])


T = int(input())
for tc in range(1, T + 1):
    # 입력
    size = int(input())
    fld = [list(map(int, input().split())) for _ in range(size)]
    ans = 1e6

    sum_unit(0, 0, fld[0][0])

    print(f'#{tc} {ans}')
