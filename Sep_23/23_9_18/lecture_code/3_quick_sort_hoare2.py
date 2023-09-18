arr = [3, -100, 1000, -300, 12, 5, 2, 1, 2, 3, 5, 7, 8, 10, 9]


def hoare_partition(arr, left, right):
    pivot = arr[right]
    # i = 작은 요소들을 추적
    i = left - 1

    for j in range(left, right):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    # 피벗 위치 교환
    arr[i + 1], arr[right] = arr[right], arr[i + 1]
    # 피벗의 새 위치를 반환
    return i + 1


def quick_sort(arr, left, right):
    if left < right:
        pivot = hoare_partition(arr, left, right)
        quick_sort(arr, left, pivot - 1)
        quick_sort(arr, pivot + 1, right)


quick_sort(arr, 0, len(arr) - 1)
print(arr)