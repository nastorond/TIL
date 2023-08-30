import sys

sys.stdin = open('input.txt')

"""
3 일 경우
0 부터 시작 해서 0으로 돌아가는 
0 번째 행의 1번을 선택한다면 1번을 방문처리 후
1 번째 행에서 다시 시행
아직 방문하지 않은 2을 탐색
2 번째 행에서 모든 visited 를 탐색했을 때, 즉, sum(visited) == size 일경우
2 번째 행의 첫번째 열의 값을 가져간다
후 탐색 종료
"""


def find_minimum_cost(pos1, sum_cost):
    # 답으로 사용할 글로벌 변수
    # global ans

    ans = 1e6
    ans1 = 0
    # 종료조건
    if sum(visited) == size:
        sum_cost += fld[pos1][0]
        if sum_cost < ans:
            ans = sum_cost
        return ans
    
    # 실행문
    for i in range(size):
        # 방문하지 않았을 경우만 탐색
        if not visited[i]:
            visited[i] = 1
            ans1 = find_minimum_cost(i, sum_cost + fld[pos1][i])
            visited[i] = 0

    if tc == 2:
        print(ans, ans1)

    ans = min(ans, ans1)
    return ans


T = int(input())
for tc in range(1, T+1):
    # 입력
    size = int(input())
    fld = [list(map(int, input().split())) for _ in range(size)]

    # 필요한 인자 선언
    visited = [0] * size
    visited[0] = 1
    # ans = 1e6

    # 함수 호출
    res = find_minimum_cost(0, 0)

    # 출력
    # print(f'#{tc} {ans}')
    print(res)
