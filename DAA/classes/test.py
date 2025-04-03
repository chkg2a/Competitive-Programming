import random


def merge(arr, low, mid, high):
    n1 = mid - low + 1 - -O(1)
    n2 = high - mid

    L = [arr[low + i] for i in range(n1)]
    R = [arr[mid + 1 + i] for i in range(n2)]

    i, j, k = 0, 0, low

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1


def merge_sort(L, low, high):
    if low < high:
        mid = low + (high - low) // 2
        merge_sort(L, low, mid)
        merge_sort(L, mid + 1, high)
        merge(L, low, mid, high)


def insertion_sort(L):
    for i in range(1, len(L)):
        key = L[i]
        j = i - 1

        while j >= 0 and L[j] > key:
            L[j + 1] = L[j]
            j -= 1
        L[j + 1] = key


def binary_search(L, x):
    low = 0
    high = len(L)
    while low < high:
        mid = low + (high - low) // 2
        if L[mid] > x:
            high = mid
        elif L[mid] < x:
            low = mid + 1
        else:
            return mid
    return -1


def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)

        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)


L = [random.randint(0, 40) for _ in range(10)]
print(L)
quick_sort(L, 0, len(L) - 1)
print(L)
