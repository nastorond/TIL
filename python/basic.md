## f-string
```python
bugs = roaches
counts = 13
area = living room
## Debugging roaches 13 living room
print(f'Debugging {bugs} {counts} {area}')
print('Debugging {} {} {}'.format(bugs,counts,area))
print('Debugging %s %d %s' %(bugs, counts, area))

## 응용
greeting = 'hi'
print(f'{greeting:^10}')
print(f'{greeting:>10}')
print(f'{greeting:<10}')
print(f'{3.141592:.4f}') ## 4번째 자리까지 출력
```

## 문자열
```python
my_str = 'hello'
print(my_str[2:4]) ## ll
print(my_str[::-1]) ## olleh

## TypeError: 'str' object does not support item assignment
my_str[1]='z'
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

## stack && queue
- pop
```python
li.pop() # 마지막 거
li.pop(idx) # li[idx] pop
```

## function
- parameter : 매개변수, 함수를 정의할 때 사용
- arguments : 인자, 함수를 사용할 때 사용
- 함수 인자 권장 작성순서
    - 위치, 기본, 가변, 키워드, 가변인자
    ```python
    def func(pos1, pos2, default_arg = 'default', *args, kwd, **kwargs):
    return
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


## 변수
### scope & variable
-  scope 
    - 함수는 코드 내부에 local scope를 생성, 그 외의 공간인 global scope 로 구분
    - global scope 코드 어디에서든 참조 할 수 있는 공간
    - local scope 함수가 만든 scope 내에서만 참조 가능
- variable
    - variable 역시 scope 와 같은 방식으로 동작


### 수명주기 lifecycle
- built-in scope 파이썬이 실행된 이후부터 영원히 유지
- global scope 모듈이 호출된 시점 이후 혹은 인터프리터가 끝날 때까지 유지
- local scope 함수가 호출될 때 생성되고, 함수가 종료될 때까지 유지


### 이름 검색 규칙 Name Resolution
- **LEGB Rule** 변수를 찾는 순서
- Local Scope : 지역범위(현재 작업중인 범위)
- Enclosed scope : 지역 범위 한 단계 위 범위
- Global scope : 최상단에 위치한 범위
- Built-in scope : 모든 것을 담고 있는 범위(정의하지 않고 사용할 수 있는 모든 것)
- cf. 함수 내에서는 바깥 Scope의 변수에 접근 가능하나 수정은 할 수 없음


### packing
- 여러개의 값을 하나의 변수에 담는 것
    ```python
    packed_val = 1,2,3,4,5
    print(packed_val) # (1, 2, 3, 4, 5)
    ```
- \* 을 활용한 패킹
    ```python
    nums = [1, 2, 3, 4, 5]
    a, *b, c = nums
    print(a,b,c) # 1 [2, 3, 4] 5
    ```

### unpacking
- 튜플이나 리스트 등의 객체의 요소들을 개별 변수에 할당
    ```python
    pack_val = 1,2,3,4,5
    a,b,c,d,e = pack_val
    print(a,b,c,d,e) # 1 2 3 4 5
    ```
- ** 언패킹 연산자로 사용될 때 딕셔너리의 키-값 쌍을 키워드 인자로 언패킹
    ```python
    my_dict = {'x':[1], 'y':[2]}
    print(**my_dict) # 출력함수 필요
    ```


### 모듈
- 한 파일로 묶인 변수와 함수의 모음
- 예시
    ```python
    # math 
    import math
    print(math.pi)
    math.floor # 내림
    math.ceil # 올림
    math.sqrt # 루트
    math.pow # 제곱
    print(math.pow(2, 10))
    help(math(module name)) 
    # 서로 다른 모듈이 같은 이름의 함수를 제공할 경우 마지막에 import된 이름으로 대체됨
    ```

- package : 관련된 모듈들을 하나의 디렉토리에 모아 놓은 것
- 모듈화 하는것은 구조화 하는 작업
- PSL 내부 패키지 : 설치없이 바로 import 하여 사용
- 외부 패키지 : pip를 사용하여 설치 후 import 하여 사용


## 단축키
- ctrl + alt + 화살표 아래 or 위 한번에 여러줄 선택