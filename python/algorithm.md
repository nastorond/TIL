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
- 너비우선탐색은 탐색 시작점의 인접한 정점들을 먼저 모두 차례로 방문한 후에, 방문했던 정점을 시작점으로하여 다시 인접한 정점들을 차례로 방문하는 방식
- 인접한 정점들에 대해 탐색을 한 후, 차례로 다시 너비운선탐색을 진행해야 하므로, 선입선출 형태의 자료구조인 큐를 활용함
- 거리순 탐색에 유용
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
    ```python
    def bfs(g, v):
        visited = [0]*(n+1)             # n : 정점의 개수
        q = deque()                     # 큐 생성
        q.append(v)                     # 시작점 v를 큐에 삽입
        visited[v] = 1                  # 방문처리
        while q:                        # 큐가 비어있지 않은 경우
            t = q.popleft()             # 큐의 첫번째 원소 반환
            visit(t)                    # 정점 t에서 할 일
            for i in g[t]:              # t와 연결된 모든 정점에 대해
                if not visitied[i]:     # 방문되지 않은 곳이라면
                    q.append(i)         # 큐에넣기
                    visited[i] = visited[t] + 1 # t 로 부터 1만큼 이동
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
## 문자열
### 패턴매칭
- 고지식한 알고리즘 *Brute Force*
    - 본문 문자열을 처음부터 끝까지 차례대로 순회하면서 패턴 내의 문자들을 일일이 비교하는 방식으로 동작
        ```python
        p = "is" # 찾을 패턴
        t = "This is a book~!" # 전체 텍스트
        M = len(p) # 찾을 패턴의 길이
        N = len(t) # 전체 텍스트의 길이

        def BruteForce(p, t):
            i = 0 # t index
            j = 0 # p index
            while j < M and i < N:
                if t[i] != p[j]:
                    i = i - j
                    j = -1
                i += 1
                j += 1
            if j == M: return i - M # 검색 성공
            else: return -1 # 검색 실패
        ```
- KMP 알고리즘
    - 불일치가 발생한 텍스트 스트링의 앞 부분에 어떤 문자가 있는지를 미리 알고 있으므로, 불일치가 발생한 앞 부분에 대하여 다시 비교하지 않고 매칭을 수행
    - 패턴을 전처리 하여 배열 next[M]을 구해서 잘못된 시작을 최소화
    - 시간복잡도: O(M+N)
    - 아이디어 설명
        - 텍스트에서 abcdabc까지는 매치되고, e에서 실패한 상황 패턴의 맨 앞의 abc와 실패 직전의 abc는 동일함을 이용할 수 있다.
        - 실패한 텍스트 문자와 P[4]를 비교한다
        ![Alt text](/image/image.png)
        - 매칭이 실패했을 때 돌아갈 곳을 계산한다
        ![Alt text](/image/image-1.png)
    ```python
    def KMP(t, p):
        N, M = len(t), len(p)
        lps = [0] *(M+1)
        j = 0
        lps[0] = -1
        for i in range(1, M):
            lps[i] = j
            if p[i] == p[j]:
                j += 1
            else:
                j = 0
        lps[M] = j
        print(lps)
        i = 0
        j = 0
        while i < N and j <= M:
            if j == -1 or t[i] == p[i]:
                i += 1
                j += 1
            else:
                j = lps[j]
            if j == M:
                print(i-M, end = ' ')
                j = lps[j] 
        print()
        return   
    ```
- 보이어-무어 알고리즘
    - 오른쪽에서 왼쪽으로 비교
    - 대부분의 상용 소프트웨어에서 채택하고 있는 알고리즘
    - 해당 알고리즘은 패턴에 오른쪽 끝에 있는 문자가 불일치 하고 이 문자가 패턴 내에 존재하는 경우, 이동거리는 패턴의 길이 만큼이 된다
- 문자열 매칭 알고리즘 비교
    - 찾고자 하는 문자열 패턴의 길이 m, 총 문자열 길이 n
    - 고지식한 패턴 검색 알고리즘 : O(mn)
    - 카프-라빈 알고리즘 : $\theta$(n)
    - KMP 알고리즘 : $\theta$(n)
    - 보이어 무어 : $\Omega$(n)


## 자료구조
### 스택
- 특성
    - 물건을 쌓아 올리듯 자료를 쌓아 올린 형태의 자료구조
    - 선형구조를 가짐
        - 자료간의 관계가 1대 1의 관계
    - 후입선출 *LIFO*
- 배열 사용 가능
- 저장소 자체를 스택이라고 부르기도 한다
- 스택에서 마지막 삽입된 원소의 위치를 top 이라 한다
- 고려사항
    - 1차원 배열을 사용하여 구현할 경우 구현이 쉽지만, 스택의 크기를 변형하기 어렵다
    - 저장소를 동적으로 할당하여 스택을 구현
    - 구현이 복잡하다는 단점이 있지만 메모리를 효율적으로 사용할 수 있음
- function call
    - 함수 호출과 복귀에 따른 전체 프로그램의 수행 순서를 스택형식으로 구성할 수 있음
    - 프로그램에서의 함수 호출과 복귀에 따른 수행 순서를 관리
        - 가장 마지막에 호출된 함수가 가장 먼저 실행을 완료하고 복귀를 하는 후입선출 구조의 스택을 이용하여 수행순서 관리
        - 함수 호출이 발생하면 호출한 함수 수행에 필요한 지역변수, 매개변수 및 수행 후 복귀할 주소 등의 정보를 스택 프레임 *Stack Frame* 에 저장하여 시스템 스택에 삽입
        - 함수의 실행이 끝나면 시스템 스택의 top원소(스택 프레임)를 삭제하면서 프레임에 저장되어 있던 복귀주소를 확인하고 복귀
        - 함수 호출과 복귀에 따라 이 과정을 반복하여 전체 프로그램 수행이 종료되면 시스템 스택은 공백 스택이 된다.
### 재귀호출
- 자기 자신을 호출하여 순환 수행 되는 것
- 함수에서 실행해야 하는 작업의 특성에 따라 일반적인 호출방식보다 재귀호출방식을 사용하여 함수를 만들면 프로그램의 크기를 줄이고 간단하게 작성 가능
![Alt text](/image/image-2.png)
### 스택을 활용한 계산기 만들기
- 문자열로 계산된 계산식이 주어질 때, 스택을 이용하여 계산
- 문자열 수식 계산의 일반적 방법
    - 중위표기법 : A+B
    - 후위표기법 : AB+
    - 중위 표기법의 수식을 후위표기법으로 변경
        - 수식의 각 연산자에 대해 우선순위에 따라 괄호를 사용해 다시 표현
        - 각 연산자를 그에 대응하는 오른쪽괄호의 뒤로 이동
        - 괄호 제거
        ```python
        # A*B-C/D
        # ((A*B)-(C/D))
        # ((AB)*(CD)/)-
        # AB*CD/-
        ```
    - 후위 표기법의 수식을 스택을 이용해 계산
        - 피연산자를 만나면 스택에 push
        - 연산자를 만나면 필요한 만큼의 피연산자를 스택에서 pop 하여 연산하고, </br>연산결과를 다시 스택에 push 한다.
        - 수식이 끝나면, 마지막으로 스택을 pop 하여 출력한다.
        ```python
        # 후위 표기법 계산 예제코드
        stack = [0]*100
        top = -1
        susik = "6528-*2/+"
        for x in susik:
            if x not in '+-/*':
                top += 1
                stack[top] = int(x)
            else:
                op1 = stack[top]
                top -= 1
                op2 = stack[top]
                top -= 1
                if x == '+':    # op2 + op1
                    top += 1
                    stack[top] = op2 + op1
                elif x == '-':
                    top += 1
                    stack[top] = op2 - op1
                elif x == '/':
                    top += 1
                    stack[top] = op2 / op1
                elif x == '*':
                    top += 1
                    stack[top] = op2 * op1
        print(stack[top])   # -9.0
        ```
## 큐 *Queue*
- 스택과 마찬가지로 삽입과 삭제의 위치가 제한적인 자료구조, 선형적 자료구조
- 선입선출 구조 FIFO First In First Out
- 큐의 선입 선출 구조
    - 머리부터 삭제, 꼬리쪽으로 삽입
    - 머리(Front) : 저장된 원소 중 첫번째 원소
    - 꼬리(Rear) : 저장된 원소 중 마지막 원소
- 기본 연산
    - 삽입 : enQueue
    - 삭제 : deQueue
### 원형 큐
- 초기 공백 상태
    - front = rear = 0
- Index 의 순환
    - front와 rear의 위치가 배열의 마지막 인덱스인 n-1를 가리킨 후, 그 다음에는</br>
    논리적 순환을 이루어 배열의 처음 인덱스인 0으로 이동해야함
    - 이를 위해 나머지 연산자 mod를 사용
- front 변수
    - 공백 상태와 포화 상태 구분을 쉽게 하기 위해 front 가 있는 자리는 사용하지 않고 항상 빈자리로 둠
- 삽입 삭제 위치
    - rear = (rear + 1) mod n
    - fornt = (front + 1) mod n
```python
def isEmpty():
    return front == rear

def isFull():
    return (rear+1)%len(cQ) == front

def enQueue(item):
    global rear
    if isFull():
        print("Queue_Full")
    else:
        rear = (rear+1)%len(cQ)
        cQ[rear] = item
        
def deQueue():
    global front
    if isEmpty():
        print("Queue_Empty")
    else:
        front = (front+1)&len(cQ)
        return cQ[front]
```
## DP
### *Dynamic Programming*
- 동적 계획 알고리즘은 그리디 알고리즘과 같이 ***최적화 문제***를 해결하는 알고리즘
- 동적 계획 알고리즘은 먼저 입력 크기가 작은 부분 문제들을 모두 해결한 후에 그 해들을 이용하여 보다 큰 크기의 부분 문제들을 해결하여, 최종적으로 원래 주어진 입력의 문제를 해결하는 알고리즘
    ```python
    def fibo(n):
        dp = [0]*(n+1)
        dp[0] = 0
        dp[1] = 1
        for i in range(2, n+1):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]
    ```
    ```python
    def fibo2(n):
        if n<2:
            return memo[n]
        else:
            if memo[n] == 0:
                memo[n] = fibo2(n-1) + fibo2(n-2)
            return memo[n]
    N = 30
    memo = [0]*(n+1)
    memo[1] = 1
    ```
- DP의 구현방식
    - recursive 방식
    - iterative 방식
    - memoization을 재귀적 구조에 사용하는 것 보다 반복적 구조로 DP를 구현한 것이 성능 면에서 보다 효율적이다.
    - 재귀적 구조는 내부에 시스템 호출 스택을 사용하는 오버헤드가 발생하기 때문
## 그래프탐색 알고리즘
- 비선형구조인 그래프 구조는 그래프로 표현된 모든 자료를 빠짐없이 검색하는 것이 중요
- 두 가지 방법
- 깊이 우선 탐색 *Depth First Search DFS*   <- Stack
- 너비 우선 탐색 *Breadth First Search BFS* <- Queue
### 깊이우선탐색 *DFS*
- 시작 정점의 한 방향으로 갈 수 있는 경로가 있는 곳까지 깊이 탐색해 가다가 더이상 갈 곳이 없게되면, 가장 마지막에 만났던 갈림길 간선이 있는 정점으로 되돌아와서 다른 방향의 정점으로 탐색을 계속 반복하여 결국 모든 정점을 방문하는 순회방법
- 가장 마지막에 만났던 갈림길의 정점으로 되돌아가서 다시 깊이 우선 탐색을 반복해야 하므로 후입선출 구조의 스택 사용
- 알고리즘
    - 시작 정점 v를 결정하여 방문
    - 정점 v에 인접한 정점 중에서
        - 방문하지 않은 정점 w가 있으면, 정점 v를 스택에 push하고 정점 w를 방문한다.</br>
          그리고 w를 v로 하여 다시 반복한다
        - 방문하지 않은 정점이 없으면, 탐색의 방향을 바꾸기 위해서 스택을 pop하여 받은</br> 
          가장 마지막 방문 정점을 v로 하여 다시 반복한다.
    - 스택이 공백이 될 때까지 위 과정을 반복
    - pesudo code
        ```python
        # visited[], stack[] 초기화
        DFS(v)
            # 시작점 v 방문
            visited[v] = True
            while 1:
                if v 의 인접 정점 중 방문 안 한 정점 w 가 있으면 gp[v]:
                    push(v)
                    v = w # w에 방문
                    visited[w] = True
                else:
                    if not gp[v]:
                        pop(v)
                    else:
                        break
        ```
## 백트래킹
- 백트래킹 기법은 해를 찾는 도중에 '막히면' 되돌아가서 다시 해를 찾아가는 기법
- 최적화 문제와 결정 문제를 해결할 수 있다
    - 결정문제 : 문제의 조건을 만족하는 해가 존재하는지의 여부를 'yes' or 'no'로 답하는 문제
- 깊이우선과의 차이
    - 가지치기를 한다.
    - 불필요한 경로를 사전에 차단
- 백트래킹 기법
    - 어떤 노드의 유망성을 점검 한 후에 유망하지 않다고 결정되면 그 노드의 부모로 되돌아가 다음 자식 노드로 감
    - 어떤 노드를 방문했을 때 그 노드를 포함한 경로가 해답이 될 수 없으면 그 노드는 유망하지 않다고 하며, 반대로 해답의 가능성이 있으면 유망하다고 함
    - 가지치기 : 유망하지 않은 노드가 포함되는 경로는 더 이상 고려하지 않는다.
- 일반 백트래킹 알고리즘
    ```python
    def checknode(v):
        if promising(v):
            if there is a solution at v:
                write the solution
            else:
                for u in each child of v:
                    checknode(u)
    ```
### 부분집합의 합 Backtracking 구현
```python
def f(i, N, s, t): # i 현재단계, N 목표, s i-1 원소까지 부분집합의 합, t 찾으려는 합
    if s == t:  # 합을 찾은 경우
        print(bit)
        return
    elif i == N:  # 남은 원소가 없는 경우
        return
    elif s > t: 
        return
    else:
        bit[i] = 1  # 부분집합에 A[i] 포함
        f(i+1, N, s + A[i])
        bit[i] = 0  # 부분집합에 A[i] 미포함
        f(i+1, N, s)
        return
N = 10
A = [i for i in range(1, N+1)]
bit = [0]*N
f(0, N, 0, 1)
```
### 순열 만들기
```python
def f(i, N):
    if i==N:
        print(A)
    else:
        for j in range(i, N):
            A[i], A[j] = A[j], A[i]
            f(i+1, N)
            A[i], A[j] = A[j], A[i]
```
## 분할 정복
- 설계전략
    - 분할 : 해결 할 문제를 여러 개의 작은 부분으로 나눈다.
    - 정복 : 나눈 작은 문제를 각각 해결한다.
    - 통합 : (필요하다면) 해결된 해답을 모은다.
### 거듭제곱
- 구현
    ```python
    def Power(Base, Exponent):
        if Base == 0 or Exponent == 0:
            return 1
        
        if Exponent % 2 == 0:
            NewBase = Power(Base, Exponent/2)
            return NewBase * Base
        else:
            NewBase = Power(Base, (Exponent - 1)/2)
            return (NewBase  * NewBase) * Base
    ```
### 퀵 정렬
- 주어진 배열을 두 개로 분할하고 각각을 정렬
- 합병정렬과 다른점
    - 합병정렬은 그냥 두 부분으로 나누는 반면에, 퀵정렬은 분할할 때,</br>기준아이템(pivot item) 중심으로, 이보다 작은것은 왼편, 큰것은 오른편에 위치시킨다.
    - 각 부분의 정렬이 끝난 후, 합병정렬은 후처리가 필요한다.
```python
def quickSort(a, begin, end):
    if begin < end:
        p = partition(a, begin, end)
        quickSort(a, begin, p-1)
        quickSort(a, p + 1, end)
def partition(a, begin, end):
    pivot = (begin + end) // 2
    L = begin
    R = end
    while L < R:
        while(L<R and a[L]<a[pivot]): L += 1
        while(L<R and a[R]>a[pivot]): R -= 1
        if L < R:
            if L == pivot: pivot = R
            a[L], a[R]= a[R], a[L]
    a[pivot], a[R] = a[R], a[pivot]
    return R 
```