# ref https://m42-orion.tistory.com/70
import sys
sys.stdin = open('input.txt')


def find_height(start, end):
    mid = (start + end) // 2

    if start > end:
        return mid

    branches = sum([i-mid for i in trees if i-mid > 0])

    if branches == key:
        return mid
    elif branches > key:
        return find_height(mid + 1, end)
    else:
        return find_height(start, mid - 1)


num_tree, key = map(int, input().split())
trees = list(map(int, input().split()))
print(find_height(0, max(trees)))
