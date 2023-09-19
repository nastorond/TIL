def multiply(A, B):
    C = [[0, 0], [0, 0]]
    C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0]
    C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1]
    C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0]
    C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1]
    return C

def matrix_power(A, n):
    if n > 1:
        A = matrix_power(A, n // 2)
        A = multiply(A, A)

        if n % 2 == 1:
            F1 = [[1, 1], [1, 0]]
            A = multiply(A, F1)
    return A

n = int(input())
F1 = [[1, 1], [1, 0]]
F1 = matrix_power(F1, n)
print(F1[0][1]%1000000007)
