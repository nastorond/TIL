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