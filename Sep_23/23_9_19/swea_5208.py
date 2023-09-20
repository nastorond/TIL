import sys
sys.setrecursionlimit(10**9)
sys.stdin = open('input.txt')


def find_ans(now, goal, battery, change_cnt):
    global res1
    
    # 현재 카운트가 현재 가진 최소값 보다 크면 더 볼필요 없음
    if res < change_cnt:
        return
    
    # 배터리 잔량 + 현재 위치가 도달할 수 있으면 교체횟수 갱신
    if battery + now >= goal:
        if change_cnt < res:
            res = change_cnt
        return

    # 종점에 도착했을 때 교체횟수 갱신
    if now == goal:
        if change_cnt < res:
            res = change_cnt
        return

    # 분기 나누기
    # 배터리가 남아있는 경우만 교체없이 진행
    if battery:
        find_ans(now + 1, goal, battery - 1, change_cnt)
    find_ans(now + 1, goal, chargers[now] - 1, change_cnt + 1)


T = int(input())
for tc in range(1, T+1):
    input_values = list(map(int, input().split()))
    num_stops = input_values[0]
    chargers = input_values[1:]
    res1 = 1e9

    find_ans(1, num_stops - 1, chargers[0] - 1, 0)

    print(f'#{tc} {res1}')
