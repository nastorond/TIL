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