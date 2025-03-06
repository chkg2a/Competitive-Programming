import random
import graphviz

node_counter = 0
recursion_tree = graphviz.Digraph(format='png')

def merge(arr, left, mid, right, parent_id):
    global node_counter
    left_part = arr[left:mid+1]
    right_part = arr[mid+1:right+1]
    
    i = j = 0
    k = left

    merge_id = f"Merge({left}, {mid}, {right})"
    recursion_tree.node(merge_id, merge_id)
    recursion_tree.edge(parent_id, merge_id)

    while i < len(left_part) and j < len(right_part):
        if left_part[i] <= right_part[j]:
            arr[k] = left_part[i]
            i += 1
        else:
            arr[k] = right_part[j]
            j += 1
        k += 1

    while i < len(left_part):
        arr[k] = left_part[i]
        i += 1
        k += 1

    while j < len(right_part):
        arr[k] = right_part[j]
        j += 1
        k += 1

def merge_sort(arr, left, right, parent_id=None):
    global node_counter
    if left < right:
        mid = (left + right) // 2
        node_id = f"MergeSort({left}, {right})"
        
        if parent_id:
            recursion_tree.edge(parent_id, node_id)
        else:
            recursion_tree.node(node_id, node_id)

        merge_sort(arr, left, mid, node_id)
        merge_sort(arr, mid + 1, right, node_id)
        merge(arr, left, mid, right, node_id)


n = 8
arr = [random.randint(1, 100) for _ in range(n)]
print("Unsorted Array:", arr)

merge_sort(arr, 0, len(arr) - 1)

print("Sorted Array:", arr)

recursion_tree.render('mergesort_tree', view=True)
