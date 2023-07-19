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