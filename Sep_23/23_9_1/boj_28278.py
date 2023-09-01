import sys

# input = sys.stdin.readline
sys.stdin = open('input.txt')

n = int(input())
stack = []
for _ in range(n):
    order = input().rstrip()
    if order[0] == '1':
        num = order.split()[1]
        stack.append(num)
        continue

    if order[0] == '2':
        try:
            print(stack.pop())
        except IndexError:
            print(-1)
            continue

    if order[0] == '3':
        print(len(stack))
        continue

    if order[0] == '4':
        if len(stack):
            print(0)
        else:
            print(1)
        continue

    if order[0] == '5':
        if len(stack):
            print(stack[len(stack)-1])
        else:
            print(-1)
