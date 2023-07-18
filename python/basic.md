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