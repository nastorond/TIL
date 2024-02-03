# Queue
### 다 인자 큐애 넣어서 사용하는 법
```cpp
#include <queue>
typedef struct que{
    int x, y, z;
};

int main(){
    queue <que>q;
    que s;
    int a, b, c;
    cin >> &a >> &b >> &c;
    s.x = a;
    s.y = b;
    s.z = c;
    
    q.push(s);
    que e = q.front();
    q.pop();
}
```

# 자료형
1e9 를 넘는 그런 거대한 수들은 long long 과 같은 자료형을 써야한다

# &, *
```cpp
int cache[10][10] = {};

int &a = cache[0][0];
int b = cache[0][0];
int *c = &a;
int &d = *c;

cache[0][0] = 1;

cout << "a" << " " << a << " size " << sizeof(a) << endl;
// a = 1
cout << "b" << " " << b << " size " << sizeof(b) << endl;
// b = 0
cout << "c" << " " << c << " size " << sizeof(c) << endl;
// c = 메모리 주소
cout << "d" << " " << d << " size " << sizeof(d) << endl;
// d = 1
```
- & 을 붙이면 값을 직접 가지고 있는 것이 아니라 값의 위치를 가지고 있는 것. 참조
- \* 는 역참조. 위와 같은 관계로 값을 가지고 오고 불러올 수 있음.

> What good are pointers?
```
이 시점에서, 포인터는 약간 바보 같고, 학문적이거나, 둔하게 보일 수 있다. 일반 변수를 사용할 수 있는데 포인터를 사용하는 이유는 뭘까?
포인터는 여러 가지 경우에서 유용하다.


 배열은 포인터를 사용하여 구현된다. 포인터는 배열을 반복할 때 사용할 수 있다. (배열 인덱스 대신 사용 가능)

C++에서 동적으로 메모리를 할당할 수 있는 유일한 방법이다. (가장 흔한 사용 사례)

데이터를 복사하지 않고도 많은 양의 데이터를 함수에 전달할 수 있다.

함수를 매개 변수로 다른 함수에 전달하는 데 사용할 수 있다.

상속을 다룰 때 다형성을 달성하기 위해 사용한다.

하나의 구조체/클래스 포인터를 다른 구조체/클래스에 두어 체인을 형성하는 데 사용할 수 있다. 이는 연결리스트 및 트리와 같은 고급 자료구조에서 유용하다.

지금까지 포인터에 대한 기본적인 수준을 이해했으므로, 다음 포스트부터는 다양한 사용법을 살펴볼 예정이다.
출처: https://boycoding.tistory.com/199 [소년코딩:티스토리]
```

#### map
- 각 노드가 key와 value 쌍으로 이루어진 트리.
- 중복을 허용하지 않음
- O(logn)인 레드블랙트리로 구성되어있음
- key를 기준으로 오름차순으로 정렬
```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    map<string, int> m;
    // 요소 삽입
    m.insert({"Alice", 100});
    m.insert({"Bob", 100});

    // 요소 검색
    if (m.find("Alice") != m.end()) {
        cout << "find" << endl;
    } else {
        cout << "404" << endl;
    }

    // 탐색
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }

    for (auto iter:m) {
        cout << iter.first << " " << iter.second << endl;
    }

    // 전체 삭제
    m.clear();

    // 요소 삭제
    // 처음부터 끝까지
    m.erase(m.begin(), m.end());
    // 특정 위치 요소 삭제 / 처음에서 두번째 요소 삭제
    m.erase(m.begin()+2);
    // key 값을 기준으로 삭제
    m.erase("Alice")
}
```