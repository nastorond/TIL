## 그래프 탐색
### *dfs*
- 구현
    ```python
    n,m = map(int, input().split())
    res = []
    vi = [0]*(n+1)

    def dfs():
        if len(res) == m:
            print(*res)
            return 

        for i in range(1,n+1):
            if vi[i] == 0:
                res.append(i)
                vi[i] = 1
                dfs()
                vi[i] = 0
                res.pop()
    dfs()
    ## permutations와 동일하게 출력
    ```
### *bfs*
- *Breath-First-Search* 너비 우선 탐색
- 시간복잡도
    - O(V+E) 노드의 개수 + 간선의 개수
- 모든 간선의 비용이 동일한 조건에서 최단 거리를 구하는 문제를 효과적으로 해결 할 수 있는 알고리즘
    - 미로를 빠져나가는 최단 거리(경로) 등
-가까운 노드부터 우선적으로 탐색, *Queue*의 자료구조를 사용
- 인접한 노드들을 반복적으로 큐에 넣어주고, 먼저 삽입된 노드부터 차례로 꺼냄
- 알고리즘 동작 방식
    - 탐색 시작 노드 정보를 큐에 삽입하고 **방문처리**
    - 큐에서 노드를 꺼내 방문하지 않은 인접 노드 정보를 모두 큐에 삽입하고 방문처리
    - 2번의 과정을 더 이상 수행할 수 없을 때까지 반복
- 구현
    ```python
    from collections import deque
    def bfs(gp, v, visited):
        # q 구현을 위한 deque 사용
        que = deque([v])
        # 현재 노드 방문처리
        visited[v] = True
        # 큐가 완전히 빌 때까지 반복
        while que:
            # 큐에 삽입된 순서대로 노드 하나 꺼내기
            r = que.popleft()
            # 탐색 순서 출력
            print(r, end = ' ')
            # 현재 처리 중인 노드에서 방문하지 않은 인접 노드를 모두 큐에 삽입
            for i in gp[r]:
                if not visited[i]:
                    que.append(i)
                    visited[i] = True
    ```
## 재귀
### 재귀 함수
- 함수 내부에서 자기 자신을 호출하는 함수
- 특정 알고리즘 식을 표현할 때 변수의 사용이 줄어들며, 코드의 가독성 증가
- 1개 이상의 base case 존재
- 재귀호출의 결과를 이용하여 문제를 작은단위의 문제까지 분할하고, 분할된 문제들의 결과를 조합하여 최종 결과를 도출
- 대표적인 예시 팩토리얼
    ```python
    def fac(n):
        if n == 0:
            return 1
        return n * fac(n - 1)
    res = fac(5)
    print(res) # 120
    ``` 

