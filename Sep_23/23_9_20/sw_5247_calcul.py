import sys
from collections import deque
sys.stdin = open('input.txt')


# 최소 연산 횟수를 찾기 위해 BFS 사용
def bfs(start, target):
    q = deque()
    q.append([start, 0])
    # 이미 확인했던 숫자는 더이상 확인하지 않음
    ck_num = [0] * (10**6 + 1)
    while q:
        now_num, cnt = q.popleft()
        # target 에 도달하면 종료
        if now_num == target:
            return cnt

        for i in range(4):
            if i == 0:
                # 조건에 맞을때만 다음 연산에 넣어줌
                if now_num + 1 <= 1e6 and ck_num[now_num + 1] == 0:
                    q.append([now_num + 1, cnt + 1])
                    ck_num[now_num + 1] = 1
            elif i == 1:
                if now_num - 1 > 0 and ck_num[now_num - 1] == 0:
                    q.append([now_num - 1, cnt + 1])
                    ck_num[now_num - 1] = 1
            elif i == 2:
                if now_num * 2 <= 1e6 and ck_num[now_num * 2] == 0:
                    q.append([now_num * 2, cnt + 1])
                    ck_num[now_num * 2] = 1
            else:
                if now_num - 10 > 0 and ck_num[now_num - 10] == 0:
                    q.append([now_num - 10, cnt + 1])
                    ck_num[now_num - 10] = 1


T = int(input())
for tc in range(1, T+1):
    n, m = map(int, input().split())
    res = bfs(n, m)
    print(f'#{tc} {res}')
