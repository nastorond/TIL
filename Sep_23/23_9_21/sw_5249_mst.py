import sys
sys.stdin = open('input.txt')


# 부모 노드 찾기
def find_set(x):
    if parents[x] == x:
        return x
    
    # 경로 단축
    parents[x] = find_set(parents[x])
    return parents[x]


# 합치기
def union(x, y):
    x = find_set(x)
    y = find_set(y)

    if x == y:
        return

    if x < y:
        parents[y] = x
    else:
        parents[x] = y


T = int(input())
for tc in range(1, T+1):
    # 입력
    V, E = map(int, input().split())
    edge = []
    for _ in range(E):
        u, v, w = map(int, input().split())
        edge.append([u, v, w])

    # 정렬
    edge.sort(key=lambda x: x[2])

    parents = [i for i in range(V + 1)]

    # KRUSKAL 알고리즘 구현
    cnt = 0
    sum_weight = 0
    for u, v, w in edge:
        if find_set(u) != find_set(v):
            cnt += 1
            sum_weight += w
            union(u, v)

            if cnt == V:
                break
    print(f'#{tc} {sum_weight}')
