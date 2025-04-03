import graphviz
import random

node_counter = 0
recursion_tree = graphviz.Digraph(format='png')

def merge(arr, low, mid, high,node_id):
    global node_counter
    left_copy = arr[low:mid + 1]
    right_copy = arr[mid + 1:high + 1]

    i = j = 0
    k = low

    merge_id = f"Merge({low},{mid},{high})"     
    recursion_tree.node(merge_id,merge_id)
    recursion_tree.edge(node_id,merge_id)

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
        k += 1 while j < len(right_copy):
        arr[k] = right_copy[j]
        j += 1
        k += 1

def merge_sort(n, low, high, parent_id=None):
    global node_counter
    if low < high:
        mid = low + (high - low) // 2
        node_id = f"Merge Sort({low},{high})"

        if parent_id:
            recursion_tree.edge(parent_id,node_id)
        else:
            recursion_tree.node(node_id,node_id)

        merge_sort(n, low, mid, node_id)
        merge_sort(n, mid + 1, high, node_id)
        merge(n,low,mid,high,node_id)

L = [random.randint(1,10000) for _ in range(10)]
print(L)
tree = merge_sort(L,0,len(L)-1)
print(L)

recursion_tree.render('mergesort_tree', view=True)
