import random


def merge(arr, low, mid, high):
    n1 = mid - low + 1
    n2 = high - mid

    L = [arr[low + i] for i in range(n1)]
    R = [arr[mid + 1 + i] for i in range(n2)]

    i = 0
    j = 0
    k = low

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


def mergeSort(arr, low, high):
    if low < high:
        mid = low + (high - low) // 2
        mergeSort(arr, low, mid)
        mergeSort(arr, mid + 1, high)
        merge(arr, low, mid, high)

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low,high):
        if arr[j] < pivot:
            i += 1
            arr[j], arr[i] = arr[i], arr[j]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr,low,high);

        quick_sort(arr,low, pi - 1)
        quick_sort(arr,pi + 1, high)

def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key


if __name__ == '__main__':
    L = [random.randint(0, 100) for _ in range(10)]
    print(L)
    quick_sort(L, 0, len(L) - 1)
    print(L)
