# 4개의 경우를 보면됨

T = int(input())

def dfs(month, acc_cost):
    global ans

    if acc_cost > ans:
        return

    # 기저 조건
    if month > 12:
        ans = min(ans, acc_cost)
        return

    # 1일 이용권으로 모두 구입
    dfs(month + 1, acc_cost + (months[month] * cost_day))

    # 1달 이용권 구입
    dfs(month + 1, acc_cost + cost_month)

    # 3달 이용권 구입
    dfs(month + 3, acc_cost + cost_month3)

    # 1년 이용권 구입
    dfs(month + 12, acc_cost + cost_year)

for tc in range(1, T + 1):
    # 이용권 가격들 (1일,1달,3달,1년)
    cost_day, cost_month, cost_month3, cost_year = map(int, input().split())
    # 12개월 이용 계획
    months = [0] + list(map(int, input().split()))
    ans = 1000000000000

    dfs(1, 0)
    print(f'#{tc} {ans}')
