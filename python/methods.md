## 함수

### collections
- deque


### itertools
- permutations()</br>
    가능한 모든 경우의수 도출
    
- [참고자료](https://docs.python.org/ko/3/library/itertools.html)

## math
```python
import math
a, b = 3.2-3.1, 1.2-1.1
print(math.isclose(a,b)) ## True
```

## set
```python
my_set_1 = set()
my_set_2 = {1, 2, 3}
my_set_3 = {1, 1, 1}
print(my_set_1) # set()
print(my_set_2) # {1, 2, 3}
print(my_set_3) # {1}
```
- 고유한 항목들의 정렬되지 않은 컬렉션
- 중복된값을 허용하지 않음
    ```python
    s.add(x) # x추가, 이미 있으면 동일
    s.clear() # print(s) -> set()
    s.remove(x) # 없으면 key error
    s.pop() # 랜덤하게 pop
    s.discard(x) # x제거, 없어도 에러 x
    x.update(iterable) # append
    ```
    - pop 실행할때마다 다른요소를 얻는 다는 의미가 아니라 **임의**라는 의미에서 무작위</br> hash table에 저장되는 순서에 따라 나옴
        - 문자열은 저장될 때 마다 위치가 바뀌지만 정수는 안바뀜</br> -> 객체의 타입에 따라 바뀐다

- 집합 method
    ```python
    set1.difference(set2) # set1-set2
    set1.intersection(set2) # set1&set2 교집합
    set1.issubset(set2) # set1<=set2
    set1.issuperset(set2) # set1>=set2 # 부분집합
    set1.union(set2) # set1|set2 합집합
    ```


## stack && queue
- pop
```python
li.pop() # 마지막 거
li.pop(idx) # li[idx] pop
```

## map & zip
### map(function, iteralbe)
- 순회 가능한 데이터구조(iterable)의 모든 요소에 함수를 적용하고, 그 결과를 map object로 반환
- iterable 반복 가능 객체(string, tuple, list 등)
- 함수가 인자로 들어갈 수 있다는 것이 강력한 점
- map 자체로써는 객체로 저장되어 실행되지 않고 list 등으로 동작을 유도해야 함
    ```python
    nums = [1,2,3]
    res = map(str, nums)
    print(res) # <map object at 0x0000020DE1B503D0>
    print(list(res)) # ['1','2','3']

    res = []
    for num in nums:
        res.append(str(num))
    print(res) # ['1','2','3']
    ```
    ```python
    def my_func(x):
        res = x*2
        return res
    nums = [1,2,3]
    res = map(my_func, nums)
    print(list(res))
    ```
    ```python
    import sys
    sys.stdin = open('input.txt')
    T = int(input())
    K, N, M = map(int, input().split()) # unpacking
    ```

### zip(*iterables) # 임의의 iterables
- 임의의 iterable을 모아 튜플을 원소로 하는 zip object를 반환
    ```python
    girls = ['jane', 'ashley']
    boys = ['peter', 'jay']
    pair = zip(girls, boys)
    print(pair) # <zip object at 0x00000263AFC30E80>
    print(list(pair)) # [('jane', 'peter'), ('ashley', 'jay')]
    ```
    ```python
    keys = ['a','b','c']
    values = [1, 2, 3]
    my_dict = dict(zip(keys, values))
    print(my_dict) # {'a': 1, 'b': 2, 'c': 3}
    ```

### lambda 함수
- 이름 없이 정의되고 사용되는 익명 함수
- lambda 매개변수: 표현식
    ```python
    addition = lambda x, y: x + y
    res = addition(3, 5)
    print(res) # 8
    ## 근데 이럴거면 그냥 def 쓰는게 나음
    ```
- map + lambda
    ```python
    nums = [1, 2, 3, 4, 5]
    res = list(map(lambda x: x * 2, nums))
    print(res) # [2, 4, 6, 8, 10]
    # lambda는 남발하지 말고 일회성으로만 사용할 때 사용
    ```

### enumerate
- 인덱스와 iterable의 요소들이 튜플형태로 return</br>

    ```python
    res = ['a', 'b', 'c']
    print(enumerate(res)) # <enumerate object at 0x000001AE1B4D06C0>
    print(list(enumerate(res))) # [(0, 'a'), (1, 'b'), (2, 'c')]
    fruits = ['apple', 'banana', 'cherry']
    for idx, fruit in enumerate(fruits):
        print(f'인덱스 {idx}: {fruit}')
    ```

### dictionary
- **을 사용하면 keyword 형태로 작동</br>

    ```python
    my_dict = {'x': 1, 'y': 2}
    print(*my_dict) # x y
    list(**my_dict) # TypeError: list() takes no keyword arguments
    print(**my_dict) # TypeError: 'x' is an invalid keyword argument for print()
    ```
- 고유한 항목들의 정렬되지 **않은** collection
    ```python
    D.clear()
    D.get(k) # value or None/default value
    D.get(k,'Unknown') # return value or Unknown
    D.get(k, v)
    D.keys()
    D.values()
    D.items()
    D.pop(k)
    D.pop(k,v)
    D.setdefault(k)
    D.setdefault(k, v)
    D.update(other) # 제공된 key/value 값으로 딕셔너리 추가/갱신, 기존의 존재하는 key는 덮어씀
    ```


### sorted
[sorted key lambda 관련 자료](https://kingofbackend.tistory.com/98)