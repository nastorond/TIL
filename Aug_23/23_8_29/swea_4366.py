"""
1
1010
212

"""

T = int(input())
for tc in range(1, T+1):
    bin_num = input().rstrip()
    ten_num = input().rstrip()
    num1, num2 = int(bin_num, 2), int(ten_num, 3)
    print(num1, num2)
