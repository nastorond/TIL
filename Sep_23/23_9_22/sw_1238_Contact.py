import sys
sys.stdin = open('input.txt')


def bfs(start):
    q = [start]
    visited[start] = 1
    while q:
        now = q.pop(0)
        for i in gp[now]:
            if not visited[i]:
                q.append(i)
                visited[i] = visited[now] + 1


T = 10
for tc in range(1, T+1):
    len_nums, start_point = map(int, input().split())
    nums = list(map(int, input().split()))
    gp = [[] for _ in range(101)]
    visited = [0] * 101

    for idx in range(len_nums//2):
        u, v = nums[idx * 2], nums[idx * 2 + 1]
        gp[u].append(v)

    bfs(start_point)

    max_value = max(visited)
    for idx in range(100, -1 , -1):
        if visited[idx] == max_value:
            print(idx)
            break
