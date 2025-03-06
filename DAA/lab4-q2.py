import graphviz
import random

def merge(arr, low, mid, high,tree):
    left_copy = arr[low:mid + 1]
    right_copy = arr[mid + 1:high + 1]

    i = j = 0
    k = low

    while i < len(left_copy) and j < len(right_copy):
        if left_copy[i] <= right_copy[j]:
            arr[k] = left_copy[i]
            i += 1
        else:
            arr[k] = right_copy[j]
            j += 1
        k += 1

    while i < len(left_copy):
        arr[k] = left_copy[i]
        i += 1
        k += 1

    while j < len(right_copy):
        arr[k] = right_copy[j]
        j += 1
        k += 1

def merge_sort(n, low, high, tree):
    if low < high:
        mid = low + (high - low) // 2
        merge_sort(n, low, mid, tree)
        merge_sort(n, mid + 1, high, tree)
        merge(n,low,mid,high,tree)

def visualize_graph(n,left,right):
    dot = graphviz.Digraph()
    result = merge_sort(n,left, right, dot)
    dot.attr(label=f"Graph representation for merge_sort({n},{left},{right})")
    return result
    
L = [random.randint(1,10000) for _ in range(10)]
print(L)
tree = visualize_graph(L,0,len(L))
print(L)
