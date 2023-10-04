import sys

sys.stdin = open('input.txt')
# input = sys.stdin.readline

n, k = map(int, input().split())
goods = [list(map(int, input().split())) for _ in range(n)]

"""
물건의 무게와, 물건의 가치 순서
"""

