import sys

sys.stdin = open('input.txt')

T = int(input())
for tc in range(1, T+1):
    # n 개의 컨테이너, m 대의 트럭으로 이송
    # 트럭 하나에 하나의 컨테이너만 가능, 적재용량 존재
    # 한 번만 운행
    # 컨테이너를 한 개도 옮길 수 없으면 0 출력
    n, m = map(int, input().split())
    freight = list(map(int, input().split()))
    limit = list(map(int, input().split()))
    
    # 역순으로 정렬
    freight.sort(reverse=True)
    limit.sort(reverse=True)
    
    # 결과값
    res = 0

    # 조건에 맞을때 트럭에 화물
    while freight and limit:
        if limit[0] >= freight[0]:
            limit.pop(0)
            res += freight.pop(0)
        else:
            freight.pop(0)

    # if tc == 1:
    print(f'#{tc} {res}')
