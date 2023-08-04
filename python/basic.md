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
### 배열
- *List*
- 일정한 자료형의 변수들을 하나의 이름을 열거하여 사용하는 자료구조
- 필요성
    - 단순히 다수의 변수 선언을 의미하는 것이 아니라, 다수의 변수로는 하기 힘든 작업을 배열을 활용해 쉽게 할 수 있다.
- 정렬
  - 버블 정렬(오름차순)
    - 가장 큰 수를 맨뒤로 보내고 미정렬 된 원소중 맨 큰것을 뒤로 보내는 정렬
      ```python
      def bubblesort(a, N):
          for i in range(N-1, 0, -1):
              for j in range(0, i):
                  if a[j] > a[j+1]:
                      a[j],a[j+1] = a[j+1],a[j]    
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
## 절차 지향 프로그래밍
- Procedural Programming
- 프로그램을 **데이터**와 **절차**로 구성하는 방식의 프로그래밍 **패러다임**
    - **데이터**와 해당 데이터를 처리하는 함수(절차)가 분리되어 있으며, **함수 호출의 흐름이 중요**
    - 코드의 순차적인 흐름과 함수 호출에 의해 진행됨
    - 함수 >> 데이터 (중요도)
    - 실제로 실행되는 내용이 중요
    - 데이터를 다시 재사용 하는것보다 함수를 끝까지 마치는게 중요
- 소프트웨어 위기 *Software Crisis*
    - 하드웨어의 발전으로 계산용량과 문제의 복잡성이 급격히 증가함에 따라 소프트웨어에 발생한 충격

## 객체 지향 프로그래밍
- *Object Oriented Programming*
- 데이터와 해당 데이터를 조작하는 method를 하나의 객체로 묶어 관리하는 방식의 프로그래밍 패러다임
    - method는 객체에 속한 함수
- 객체 간 상호작용과 메시지 전달이 중요
### 클래스 *Class*
- 파이썬에서 타입을 표현하는 방법
- 객체를 생성하기 위한 설계도 *Blueprint*
- 데이터와 기능을 함께 묶음
- 객체 *Object*
    - 클래스에서 정의한 것을 토대로 메모리에 할당된 것 **속성**과 **행동**으로 구성된 것
- 클래스로 만든 객체를 **인스턴스**라고도 함
    - 아이유는 객체이자 가수의 인스턴스다
- 예시
    ```python
    name = 'Alice'
    print(type(name)) # <class 'str'>
    # 변수 name은 str 클래스의 인스턴스
    # 데이터 타입은 사실 모두 클래스
    ```
    - 결국 문자열 타입 변수는 str 클래스로 만든 인스턴스
    </br>
    </br>
    ```python
    "hello".upper()
    # 객체.행동()
    # 인스턴스.method()
    ```
- 하나의 객체*object*는 특정 타입의 인스턴스*instance*이다.
- 특징
    - 타입 *type*
    - 속성 *attribute*
    - 조작법 *method*
    - 속성과 기능이 합쳐진 결과라고 함
- 클래스 구조
    ```python
    # 클래스 정의
    class Person:
        pass
    # 인스턴스 생성
    iu = Person()
    # method 호출
    iu.method()
    # 속성(변수) 접근
    iu.attribute
    ```
- 인스턴스와 클래스 간의 이름공간 *namespace*
    - 클래스를 정의하면, 클래스와 해당하는 이름의 공간 생성
    - 인스턴스를 만들면, 인스턴스 객체가 생성되고 **독립적인** 이름 공간 생성
    - 인스턴스에서 특정 속성에 접근하면, 인스턴스->클래스 순으로 탐색
- 독립적인 이름공간을 가지는 이점</br>
    - 클래스와 다른 인스턴스 간에는 서로의 데이터나 상태에 직접적인 접근이 불가능
    - 클래스와 인스턴스를 모듈화 하고 각각의 객체가 독립적으로 동작하도록 보장
    - 서로 충돌이나 영향을 주지 않으면서 독립적으로 동작할 수 있음
    - 코드의 가독성, 유지보수성, 재사용성을 높이는데 도움을 줌
### 매서드
- 인스턴스 메서드
    - 클래스로 부터 생성된 각 인스턴스에서 호출 할 수 있는 메서드</br>
    -> 인스턴스의 상태를 조작하거나 동작을 수행
    - 구조
        - 클래스 내부에 정의되는 메서드의 기본
        - 첫번째 매개변수로 인스턴스 반드시 자신 ***self***을 전달받음</br>
        -> 꼭 self를 받을 필요는 없지만 국룰임
- 클래스 메서드
    - 클래스가 호출하는 메서드</br>
    -> 클래스 변수를 조작하거나 클래스 레벨의 동작을 수행
    - *@classmethod* 데코레이터를 사용해 정의
    - 호출시, 첫 번째 인자로 호출하는 클래스(cls)가 전달됨
        ```python
        class MyClass:
            @classmethod
            def class_method(cls, arg1, ...):
            pass
        ```
- 정적 메서드 *static method*
    - 클래스, 인스턴스와 상관없이 독립적으로 동작하는 메서드</br>
    -> 주로 클래스와 관련이 있지만 인스턴스와 상호작용이 필요없는 경우
    - *@staticmethod* 데코레이터를 사용해 정의
    - 필수적으로 작성해야 할 매개변수가 없음
    - 객체나 클래스의 상태를 수정할 수 없으며 단지 기능(행동)만을 위한 메서드로 사용
        ```python
        class MyClass:
            @staticmethod
            def class_method(arg1, arg2, ...):
            pass
        ```
- 클래스는 모든 메서드를 호출 할 수 있음
    - 클래스는 클래스 메서드와 스태틱 메서드만 사용
- 인스턴스는 모든 메서드를 호출 할 수 있음
    - 인스턴스 메서드만 사용
- 데코레이터
    - 다른 함수의 코드를 유지한 채로 수정하거나 확장하기 위해 사용되는 함수
- 매직 메서드
    - 특정 상황에 자동으로 호출되는 메서드
    - Double undersocore가 있는 메서드는 특수한 동작을 위해 만들어진 메서드
        - 스페셜 메서드 혹은 매직 메서드라고 불림
## 상속
- *Inheritance*
- 기존 클래스의 속성과 메서드를 물려받아 새로운 하위 클래스를 생성하는 것
- 사용하는 이유
    - 코드 재사용
        - 상속을 통해 기존 클래스의 속성과 메서드 재사용
        - 새로운 클래스를 작성할 때 기존 클래스의 기능을 그대로 활용, 중복된 코드를 줄일 수 있음
    - 계층 구조
        - 상속을 통해 클래스들 간의 계층 구조를 형성
        - 부모 클래스와 자식 클래스 간의 관계를 표현하고, 더 구체적인 클래스를 만들 수 있음
    - 유지보수의 용의성
        - 상속을 통해 기존 클래스의 수정이 필요한 경우, 해당 클래스만 수정하면 됨
        - 코드의 일관성을 유지, 수정이 필요한 범위를 최소화할 수 있음
### 클래스 상속
- 공통적으로 사용될 기능이나 속성들을 상위 클래스에 넣어주고 하위 클래스에 자세한 내용들을 넣어 사용
- *super()*
    - 부모 클래스의 메서드를 호출하기 위해 사용되는 내장 함수
### 다중 상속
- 두 개 이상의 클래스를 상속 받는 경우
- 상속받은 모든 클래스의 요소를 활용 가능함
- 중복된 속성이나 메서드가 있는 경우 **상속 순서에 의해 결정**됨
### 상속 관련 함수와 메서드
- *mro()*
    - *Method Resolution Order*
    - 해당 인스턴스의 클래스가 어떤 부모 클래스를 가지는지 확인하는 메서드
    - 기존의 인스턴스 -> 클래스 순으로 이름 공간을 탐색하는 과정에서 상속관계에 있으면 인스턴스 -> 자식클래스 -> 부모 클래스로 확장
## 에러와 예외
### 디버깅
- 디버깅 방법
    - print 함수 활용
    - 개발 환경 등에서 제공하는 기능 활용
        - breakpoint, 변수 확인
    - Python tutor
    - 뇌 컴파일, 눈 디버깅
### 에러
- 문법 에러 *Syntax Error*
    - 구문이 올바르지 않은 경우
    - *Invalid syntax* 문법 오류
    - *assign to literal* 잘못된 할당
    - *EOL End of Line*
    - *EOF End of File*
- 예외 *Exception*
    - 실행 중 감지되는 에러, 문법에러가 아닌 에러
    - 내장 예외 *Built-in Exceptions*
    - *Zero DivisionError* 
        - 0으로 나누려 함
    - *NameError* 
        - 지역 또는 전역 이름을 찾을 수 없음
    - *TypeError*
        - 타입 불일치
        - 인자 누락
        - 인자 초과
        - 인자 타입 불일치
    - *ValueError*
        - 연산이나 함수에 문제가 없지만 부적절한 값을 가진 인자를 받았고,</br> 상황이 IndexError 처럼 더 구체적인 예외로 설명되니 않는 경우 발생
    - *IndexError*
    - *KeyError*
    - *ModuleNotFoundError*
        - 모듈을 찾을 수 없을 때
    - ImportError
        - 임포트 하려는 이름을 찾을 수 없을 때
    - *KeyboardInterrupt*
        - 사용자가 Crtl-C 또는 Delete를 누를 때 발생
        - 무한루프 시 강제 종료
    - *IndentationError*
        - 잘못된 들여쓰기와 관련된 문법 오류
### 예외 처리
- try & except
    ```python
    try:
        result = 10/0
    except ZeroDivisionError:
        print('0으로 나눌 수 없습니다.')

    try:
        num = int(input('숫자 입력 : '))
    except ValueError:
        print('숫자가 아닙니다.')
    
    try:
        name = input()
        if not len(name):
            rasie Exception('error')
    except Exception as e:
        print(e)
    ```
## 정렬
### 카운팅 정렬
- 항목들의 순서를 결정하기 위해 각 항목이 몇 개씩 있는지 세는 작업을 하여, 선형 시간에 정렬하는 효율적인 알고리즘
- 제한사항
    - 정수나 정수로 표현할 수 있는 자료에 대해서만 적용 가능
    - 집합내에 가장 큰 정수를 알아야 한다
- 시간복잡도
    - O(n + k) n: 리스트 길이, k: 정수의 최대값
- 정렬
    - Data에 각 항목들의 발생 회수를 세고, 정수 항목들로 직접 인덱스 되는 카운트 배열 counts에 저장한다
    - 정렬된 집합에서 각 항목의 앞에 위치할 항목의 개수를 반영하기 위해 counts의 원소를 조정
    - 맨 마지막 원소부터 접근해 해당 원소를 counts에서 감소시키고 새로운 list에 삽입한다
    ```python
    def counting_sort(a, b, k):
    # a 입력배열
    # b 정렬된 배열
    # c 카운트 배열
        c = [0]*(k+1)
        for i in range(0, len(a)):
            c[a[i]] += 1
        
        for i in range(1, len(c)):
            c[i] += c[i-1]
    
        for i in range(len(b)-1, -1 , -1):
            c[a[i]] -= 1
            b[c[a[i]]] = a[i]
  
        return b
    ```
## 배열
### 2차원 배열
- 1차원 List 를 묶어 놓은 List
- 2차원 이상의 다차원 List 는 차원에 따라 Index 를 선언
- 2차원 List 의 선언: 세로길이(행의 개수), 가로길이(열의 개수)를 필요로 함
- Python 에서는 데이터 초기화를 통해 변수선언과 초기화가 가능
- 배열 순회
    - 행 우선 순회
        ```python
        # i == 행의 좌표
        # j == 열의 좌표
        for i in range(n):
            for j in range(m):
                func(Arr[i][j])
        ```
    - 열 우선 순회
        ```python
        for j in range(m):
            for i in range(n):
                func(Arr[i][j])
        ```
    - 지그재그 순회
        ```python
        for i in range(n):
            for j in range(m):
                func(Arr[i][j+(m-1-2*j)*(i%2)])
        ```
    - 델타를 이용한 2차 배열 탐색
        - 2차 배열의 한 좌표에서 4방향의 인접 배열 요소를 탐색하는 방법
        ```python
        arr[0...N-1][0...N-1] # NxN 행렬
        di = [0, 1, 0, -1] # 상하 좌우
        dj = [1, 0, -1, 0]
        # di = [1, 1, -1, -1] # 대각선
        # dj = [1, -1 ,-1 ,1]
        for i in range(N):
            for j in range(N):
                for k in range(4):
                    ni = i + di[j]
                    nj = j + dj[k]
                    if 0 <= ni < N and 0 <= nj < N: # 유효한 인덱스인지 검증
                        func(arr[ni][nj])
                    """
                    if 0 <= ni and ni < N: # 위와 동일
                        if 0 <= nj and nj < N:
                            func(arr[ni][nj])
                    """
        ```
    - 전치 행렬
        ```python
        arr = [[1,2,3],[4,5,6],[7,8,9]]
        for i in range(3):
            for j in range(3):
                if i < j:
                    arr[i][j], arr[j][i] = arr[j][i], arr[i][j]
        ```
## 부분집합
### 부분집합 합 문제
- 유한 개의 정수로 이루어진 집합이 있을 때, 이 집합의 부분집합 중에서
그 집합의 원소를 모두 더한 값이 0이 되는 경우가 있는지 확인하는 문제
- 완전검색 기법으로 부분집합 합 문제를 풀기 위해서는, 우선 집합의 모든 부분집합을 생성한 후에 각 부분집합의 합을 계산
- 부분집합의 수
    - 집합의 원소가 n개 일 때, 공집합을 포함한 부분집합의 수는 2**n 개
    - 이는, 각 원소를 부분집합에 포함시키거나 포함시키지 않는 2가지 경우를 모든 원소에 적용한 경우의 수와 같다
    - bit 배열로 만들어서 연산
    - 각 원소가 부분집합에 포함되있는지를 loop 이용하여 확인하고 부분집합을 생성
        ```python
        def print_subset(bit, arr, n);
            total = 0
            for i in range(n):
                if bit[i]
                    print(arr[i], end = ' ')
                    total += arr[i]
            print(bit) # 놓침
        arr = [1, 2, 3, 4]
        bit = [0, 0, 0, 0]
        for i in range(2):
            bit[0] = i
            for j in range(2):
                bit[1] = j
                for k in range(2):
                    bit[2] = k
                    for l in range(2):
                        bit[3] = l
                        print_subset(bit, arr, 4)
        ```
- 비트연산자로 계산
    - & 비트단위로 AND 연산
    - | 비트단위로 OR 연산
    - << 피연산자의 비트 열을 왼쪽으로 이동
    - \>\> 피연산자의 비트 열을 오른쪽으로 이동
    </br></br>
    - << 연산자
        - 1 << n : 2**n 즉, 원소가 n개일 경우의 모든 부분집합의 수를 의미
    - & 연산자
        - i & (1 << j) : i의 j번째 비트가 1인지 아닌지를 검사한다.
            - i: 생성한 비트 열
    ```python
    arr = [3, 6, 7, 1, 5, 5]
    n = len(arr)
    for i in range(1<<n): # 1<<n : 부분집합의 개수
        for j in range(n): # 원소의 수만큼 비트를 비교
            if i & (1 << j): # i의 j번 비트가 1인 경우
                print(arr[j], end = ", ") # j 번 원소 출력
    ```
## 검색
- 저장되어 있는 자료 중에서 원하는 항목을 찾는 작업
- 목적하는 탐색키를 가진 항목을 찾는것
### 순차검색
- 일렬로 되어 있는 자료를 순서대로 검색하는 방법
    - 가장 간단하고 직관적
    - 배열이나 연결 리스트 등 순차구조로 구현된 자료구조에서 원하는 항목을 찾을 때 유용
    - 알고리즘이 단순, 구현하기 쉽지만, 검색대상이 많을 경우 비효율적
- 2가지 경우로 나눠서 할 수 있음
- 정렬되어 있지 않은 경우
    - 검색과정
        - 첫 번째 원소부터 순서대로 검색 대상과 키 값이 같은 원소가 있는지 비교하며 찾음
        - 키 값이 동일한 원소를 찾으면 그 원소의 인덱스 반환
        - 자료구조의 마지막에 이를 때까지 찾지못하면 검색 실패
        - 찾고자 하는 원소의 순서에 따라 비교횟수가 결정됨
### 이진검색 *Binary Search*
- 자료의 가운데에 있는 항목의 키 값과 비교하여 다음 검색의 위치를 결정하고 검색
    - 목적 키를 찾을 때까지 이진 검색을 순환적으로 반복 수행함으로써 검색범위를 반으로 줄여가면서 보다 빠르게 검색을 수행
- 이진 검색을 하기 위해선 자료가 정렬되어 있어야함
- 검색과정
    - 자료의 중앙에 있는 원소를 고른다
    - 중앙 원소의 값과 찾고자 하는 목표 값을 비교
    - 목표 값이 중앙 원소의 값보다 작으면 자료의 왼쪽 반에 대해서 새로 검색을 수행하고, 크다면 자료의 오른쪽 반에 대해서 새로 검색 수행
    - 찾고자 하는 값을 찾을 때 까지 1 ~ 3의 과정 반복
- 구현
    - 검색 범위의 시작점과 종료점을 이용하여 검색을 반복 수행
    - 이진 검색의 경우, 자료에 삽입이나 삭제가 발생했을 때 배열의 상태를 항상 정렬 상태로 유지하는 추가작업이 필요하다
    ```python
    def binarySearch(a, N, key):
        start = 0
        end = N-1
        while start <= end:
            mid = (start + end)//2
            if a[mid] == key:
                return True
            elif a[mid] > key:
                end = mid - 1
            else:
                start = mid + 1
        return False
    def binarySearch2(a, low, high, key):
        if low > high:
            return False
        else:
            mid = (low, high)//2
            if key == a[mid]:
                return True
            elif key < a[mid]:
                return binarySearch2(a, low, mid-1, key)
            elif key < a[mid]:
                return binarySearch2(a, mid-1, high, key)
    ```
### 선택정렬 *Selection Sort*
- 주어진 자료들 중 가장 작은 값의 원소부터 차례대로 선택하여 위치를 교환하는 방식
    - 앞서 살펴본 셀렉션 알고리즘을 전체 자료에 적용한 것
- 정렬 과정
    - 주어진 리스트 중에서 최소값을 찾는다
    - 그 값을 리스트의 맨 앞에 위치한 값과 교환한다
    - 맨 처음 위치를 제외한 나머지 리스트를 대상으로 위의 과정 반복
- 시간복잡도
    - O(n**2)
- 구현
    ```python
    def SelectSort(a, n):
        for i in range(n-1):
            minIdx = i
            for j in range(i+1, N):
                if a[minIdx] > a[j]:
                    minIdx = j
            a[i], a[minIdx] = a[minIdx], a[i]
    ```
- 셀렉션 알고리즘(선택정렬 응용)
- 저장되어 있는 자료로부터 K번째로 큰 혹은 작은 원소를 찾는 방법
    - 최소, 최대 혹은 중간값을 찾는 알고리즘을 의미
- 선택과정
    - 정렬 알고리즈을 이용하여 자료 정렬
    - 원하는 순서에 있는 원소 가져오기
## 오늘의 문제
## 단축키
- ctrl + alt + 화살표 아래 or 위 한번에 여러줄 선택
### [python 3.9 documents](https://docs.python.org/3.9/)