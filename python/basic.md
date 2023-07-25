## 자료구조
- 우리가 컴퓨터에 있는 데이터를 효율적으로 저장, 관리하기 위해 사용
- method 와 function 기능적으로는 거의 동일

## method
- 객체(class)에 속한 함수
- 객체의 상태를 조작하거나 동작을 수행
- 데이터타입 객체.method()
    - 예제
        ```python
        'hello'.capitalize() # Hello
        ```

### 시퀀스 데이터 구조
- 여러개의 값들을 **순서대로 나열**하여 저장하는 자료형 // 정렬아님

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
- string
    ```python
    my_str = 'hello'
    print(my_str[2:4]) ## ll
    print(my_str[::-1]) ## olleh

    ## TypeError: 'str' object does not support item assignment
    my_str[1]='z'
    ```

    - 문자열 조회/탐색 및 검증 method
        ```python
        s.find(x) # index 0 부터 탐색, 없으면 -1 반환
        s.index(x) # index 0 부터 탐색, 없으면 ValueError
        s.isalpha() # 알파벳 문자여부, 단순 알파벳이 아닌 유니코드 상 Letter(한국어 포함)
        s.isupper()
        s.islower()
        s.istitle()
        ```
     - 문자열 조작 메서드
        ```python
        s.replace(old, new[,count]) # old를 new로 바꿔서 변환
        s.strip() # 시작과 끝에 있는 공백 혹은 지정문자 제거
        s.split(sep=None, maxsplit=-1)
        'separator'.join([iterable])
        'hello world'.capitalize() # Hello world
        'hello world'.title() # Hello World
        s.upper() 
        s.lower()
        s.swapcase() # 대,소문자 서로 변경
        ```
    - 예시
        ```python
        text = 'heLLo, woRld!'
        new_text = text.swapcase().replace('l','z')
        print(new_text) # HEzzo, WOrLD!
        ```
    - 문자열에 포함된 문자들의 유형을 판별하는 method
        - isdecimal() 문자열이 모두 숫자
        - isdigit() 유니코드도 숫자로 인식
        - isnumeric() 몇가지 추가적인 유니코드 문자들을 인식(분수, 지수, 루트기호 등)</br>
        ==> isdeciaml < isdigit < isnumeric

## list
- 리스트값 추가 및 삭제 method
    ```python
    L.append()
    L.extend()
    L.insert(i, x) # 인덱스 i에 항목 x삽입
    L.remove(x) # index 0부터 탐색, x 제거, 없으면 Value Error
    L.pop()
    L.pop(i) # List[i] pop
    L.clear()
    ```
- 리스트 탐색 및 정렬 method
    ```python
    L.index(x, strt, end)
    L.reverse() # 순서 뒤집기
    L.sort() # 원본리스트 정렬
    L.count(x)
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

## for - loop
```python
for i in range(13):
    pass
else: # for문이 끝날 떄 까지 break가 없었다면 실행
    print('s')
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

## List Comprehension
 - 홀수만 들어있는 리스트 만들기 (1~10)
 - [expression for 변수 in iterable]
 - list(expression for 변수 in iterable)
 ```python
 li_1 = [i**2 for i in range(1,10)] # [1, 4, 9, 16, 25, 36, 49, 64, 81]
 li_2 = [i for i in range(1,11) if i%2!=0] # [1, 3, 5, 7, 9]
 li_3 = [i if i% 2 == 1 else str(i) for i in range(10)] # ['0', 1, '2', 3, '4', 5, '6', 7, '8', 9]
 # elif 안댐 if 중첩은 가능
```

## 복사
- 파이썬은 데이터의 분류에 따라 복사가 달라짐
- 유형
    - 할당
        - 같은 주소를 보게됨 변수 명만 다름
        - 객체 참조(주소)를 복사
    - 얕은 복사
        ```python
        a = [1,2,3]
        b = a[:]
        print(a, b) # [1,2,3], [1,2,3]

        b[0] = 100
        print(a, b) # [1,2,3], [100,2,3]

        c = a.copy()
        c[0] = 100
        print(a, c) # [1,2,3], [100,2,3]
        ```
        - 한계
            ```python
            a = [1,2,[1,2]]
            b = a[:]
            b[2][0] = 999
            print(a, b) # [1,2,[999,2]] [1,2,[999,2]]
            c = a.copy()
            c[2][0] = 999
            print(a, c) # [1,2,[999,2]] [1,2,[999,2]]
            ```
    - 깊은 복사
        ```python
        import copy
        a = [1,2,[1,2]]
        b = copy.deepcopy(a)
        b[2][0] = 999
        print(a, b) # [1,2,[1,2]] [1,2,[999,2]]
        ```


## 오늘의 문제
7662 24416 9184 9461 1904 11279 1764


## 단축키
- ctrl + alt + 화살표 아래 or 위 한번에 여러줄 선택

### [python 3.9 documents](https://docs.python.org/3.9/)