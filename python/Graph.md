# 서로소 집합 *Disjoint-sets*
- 서로소 또는 상호배타 집합들은 서로 중복 포함된 원소가 없는 집합들
- 교집합이 없음
- 집합에 속한 하나의 특정 멤버를 통해 각 집합들을 구분 -> 대표자 *representative*
- 표현 방법
    - 연결 리스트
    - 트리
- 연산
    - Make-Set(x)
    - Find-Set(y)
    - Union(x, y)
## 표현
### 연결리스트
- 같은 집합의 원소들은 하나의 연결리스트로 관리
- 연결리스트의 맨 앞의 원소를 집합의 대표 원소로 함
- 각 원소는 집합의 대표원소를 가리키는 링크를 가짐<br>
    <img src="./image/dis-joint-linked_li.png" width="70%"><br>
- e.g.<br>
    <img src="./image/disjoint-sets-cal-eg.png" width="70%"><br>
### 트리
- 하나의 집합 *a disjoint set* 을 하나의 트리로 표현
- 자식 노드가 부모 노드를 가리키며 루트 노드가 대표자가 됨<br>
    <img src="./image/disjoint-sets-tree.png" width="70%"><br>
- e.g.<br>
    <img src="./image/disjoint-sets-tree-cal-eg.png" width="70%"><br>
- 상호배타 집합을 표현한 트리의 배열을 이용해 저장된 모습<br>
    <img src="./image/disjoint-sets-howtosaveto-tree.png" width="70%"><br>
## 연산
- <img src="./image/disjoint-sets-calculation.png" width="70%">
### 효율을 높이는 방법
- Rank를 이용한 Union
    - 각 노드는 자신을 루트로 하는 subtree 의 높이를 랭크 Rank 라는 이름으로 저장
    - 두 집합을 합칠 때 rank가 낮은 집합을 rank 가 높은 집합에 붙임
- Path compression
    - Find-Set을 행하는 과정에서 만나는 모든 노드들이 직접 root를 가리키도록 포인터를 바꿈
- e.g.<br>
    <img src="./image/path-comp.png" width="70%"><br>
## Code
```python
# make set
parent = [i for i in range(10)]

# find parenet
def find_set(x):
    if parent[x] == x:
        return x
    
    # 경로 압축
    parent[x] = finds_set(parent[x])
    return find_set(parent[x])

# union two sets
def union(x, y):
    x = find_set(x)
    y = find_set(y)

    # 대표자가 같으면 같은 집합
    if x == y: return

    # 다른 집합이면 같은 대표자로 수정
    if x < y:
        parent[y] = x
    else:
        parent[x] = y
```
# 최소 신장 트리 MST
- 신장트리
    - 모든 정점이 연결되어 있는 그래프
    - 사이클이 존재하지 않는 부분 그래프
    - 한 그래프에서 여러개의 신장트리가 나올 수 있음
    - n 개의 정점으로 이루어진 무방향 그래프에서 n 개의 정점과 n-1 개의 간선으로 이루어진 트리
- *Minimun Spanning Tree*
    - 무방향 가중치 그래프에서 신장트리를 구성하는 간선들의 가중치의 합이 최소인 신장 트리
### 표현
- 갈 수 있는 곳들 중 제일 짧은 곳으로 가자
    - 모든 정점을 방문할 때 까지
    - DFS로 구현
- 전체 간선들 중에서 제일 가중치가 적은 곳부터 선택
    - 간선 정보 정렬
    - 앞에서부터 방문 안했던 곳
## 알고리즘
### Prim 알고리즘
- 하나의 정점에서 연결된 간선들 중에 하나씩 선택하며넛 MST를 만들어 가는 방식
    - 임의 정점을 하나 선택
    - 선택한 정점과 인접하는 정점들 중의 최소 비용의 간선이 존재하는 정점 선택
    - 모든 정점이 선택될 때가지 위 과정 반복
- 서로소인 2개의 집합 *2 disjoint-sets* 정보를 유지
    - 트리 정점들 -> MST 를 만들기 위해 선택된 정점들
    - 비트리 정점들 -> 선택 되지 않은 정점들
- code
    ```python
    def prim(start):
        heap = []
        # MST 에 포함되었는 지 여부
        MST = [0] * V

        # 가중치, 정점 정보
        heapq.heappush(heap, (0, start))

        # 누적합 저장
        sum_weight = 0

        while heap:
            # 가장 적은 가중치를 가진 정점을 꺼냄
            weight, vertex = heapq.heappop(heap)

            # 이미 방문한 노드라면 pass
            if MSX[v]:
                continue
            
            # 방문 체크
            MST[v] = 1

            # 누적합 추가
            sum_weight += weight

            # 갈 수 있는 노드들을 체크
            for candidate in range(V):
                # 갈 수 없거나 이미 방문했다면 pass
                if graph[v][candidate] == 0 or MST[candidate]:
                    continue
                
                heapq.heappush(heap, (graph[v][candidate], candidate))

        return sum_weight


    # 인접 행렬로 구현 V == Vertex number
    graph = [[0] * V for _ in range(V)]
    ```
### KRUSKAL
- 간선을 하나씩 선택해서 MST 를 찾는 알고리즘
    - 최초, 모든 간선을 가중치에 따라 **오름차순**으로 정렬
    - 가중치가 가장 낮은 간선부터 선택하면서 트리를 증가
        - 사이클이 존재하면 다음으로 가중치가 낮은 간선 선택
    - n-1 개의 간선이 선택될때까지 반복
- code
    ```python
    def find_set(x):
        if parents[x] == x:
            return x
        
        parents[x] = find_set(parents[x])
        return parents[x]
    

    def union(x, y):
        x = find_set(x)
        y = find_set(y)

        if x == y:
            # 사이클 발생
            return
        
        if x < y:
            parents[y] = x
        else:
            parents[x] = y

    
    V, E = map(int, input().split())
    edge = [[] for _ in range(V)]
    for _ in range(E):
        u, v, w = map(int, input().split())
        edge.append([u, v, w])
    
    # w 를 기준으로 정렬
    edge.sort(key=lambda x: x[2])

    # 사이클 발생 여부를 union find 로 해결
    parent = [i for i in range(V)]

    # 현재 방문한 정점 수
    cnt = 0
    # 최소비용 계산
    sum_weight = 0
    for u, v, w in edge:
        # 사이클이 발생하지 않는다면
        if find_set(u) != find_set(v):
            cnt += 1
            sum_weight += w
            union(u, v)

            # MST 구성이 끝나면
            if cnt == V:
                break
    ```
# 최단경로
- 정의
    - 간선의 가중치가 있는 그래프에서 두 정점 사이의 경로들 중에 간선의 가중치의 합이 최소인 경로
- 하나의 시작 정점에서 끝 정점까지의 최단경로
    - 다익스트라 *dijkstra* 알고리즘
        - 음의 가중치를 허용하지 않음
    - 벨만-포드 알고리즘
        - 음의 가중치 허용
- 모든 정점들에 대한 최단 경로
    - 플로이드-워샬 *Floyd Warshall* 알고리즘
## *Dijkstra* 알고리즘
- 시작 정점에서 거리가 최소인 정점을 선택해 나가면서 최단 경로를 구하는 방식
- 시작정점 s 에서 끝정점 t 까지의 최단 경로에 정점 x 가 존재
- 최단경로는 s 에서 x 까지의 최단 경로와 x 에서 t 까지의 최단 경로로 구성
- 탐욕 기법을 사용한 알고리즘으로 MST의 프림 알고리즘과 유사
- code
    ```python
    gp = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = map(int, input().split())
        gp[u].append([v, w])
    
    # 누적거리를 계속 저장
    INF = int(1e9)
    distance = [INF] * n
    
    def dijkstra(start):
        pq = []
        # 출발점 추가
        heapq.heappush(pq, (0, start))
        distance[start] = 0

        while pq:
            dist, now = heapq.heappop(pq)

            if dist > distance[now]:
                continue
            
            for next_node, weight in gp[now]:
                cost = dist + weight
                if cost < distance[next_node]:
                    distance[next_node] = cost
                    heapq.heappush(pq, (cost, next_node))
    ``` 
## 최단 거리 문제 유형
- 특정 지점 -> 도착 지점까지의 최단 거리 : 다익스트라
- 가중치에 음수가 포함 되어 있으면 : 벨만 포드
- 여러 지점 -> 여러 지점 까지의 최단거리
    - 모두 다익스트라 하면 되긴하지만 시간 복잡도 계산을 잘 해야함
    - 플로이드 워샬
