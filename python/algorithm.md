### dfs
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