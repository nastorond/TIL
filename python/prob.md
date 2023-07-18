## 백준 풀이 배껴오기

### 1158 요새푸스 문제 풀이 40ms
```python 
N, M = map(int, input().split())
arr = [i+1 for i in range(N)]
res_arr = []
now_idx = M-1
while len(arr) > 1:
    res_arr.append(arr.pop(now_idx))
    now_idx += M-1
    now_idx %= len(arr)
res_arr.append(arr.pop())
res_arr = str(res_arr)
print('<'+res_arr[1:-1]+'>')
```