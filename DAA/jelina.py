import random
from graphviz import Digraph

graph = Digraph(comment='Merge Sort Recursion Tree', graph_attr={'rankdir': 'TB'})

def merge_sort(arr, graph=None, previous_node=None):
    """Sorts an array using merge sort and visualizes the recursion tree."""

    node_name = f"Mergesort{arr}"
    # graph = graph or Digraph(comment='Merge Sort Recursion Tree', graph_attr={'rankdir': 'TB'})
    graph.node(node_name)

    if previous_node:
        graph.edge(previous_node, node_name)

    if len(arr) <= 1:
        return arr, graph

    mid = len(arr) // 2
    left, graph = merge_sort(arr[:mid], graph, node_name)
    right, graph = merge_sort(arr[mid:], graph, node_name)
    merged, graph = merge(left, right, graph, node_name)

    return merged, graph

def merge(left, right, graph, previous_node):
    """Merges two sorted arrays into a single sorted array."""

    node_name = f"Merge{left}, {right}"
    graph.node(node_name)
    graph.edge(previous_node, node_name)

    merged = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1
    merged.extend(left[i:])
    merged.extend(right[j:])

    return merged, graph

# Generate a random set of elements
n = 10
arr = random.sample(range(1, 51), n)

# Display the unsorted list
print("Unsorted list:", arr)


# Perform merge sort and visualize the recursion tree
sorted_arr, graph = merge_sort(arr,graph)

# Display the recursion tree
print("Merge Sort Recursion Tree:")
# display(graph)

# Display the sorted list
print("Sorted list:", sorted_arr)

graph.render(filename=f"merge_sort_tree", format="png", cleanup=True)
