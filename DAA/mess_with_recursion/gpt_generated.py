import graphviz
import random

# Counter for generating unique node IDs
node_counter = 0

def get_node_id():
    global node_counter
    node_id = f"node_{node_counter}"
    node_counter += 1
    return node_id

# 1. FIBONACCI SEQUENCE
def fibonacci_with_tree(n, tree, parent_id=None):
    # Create node ID for this operation
    node_id = get_node_id()
    
    # Add node to graph
    tree.node(node_id, f"fib({n})")
    
    # Connect to parent if exists
    if parent_id is not None:
        tree.edge(parent_id, node_id)
    
    # Base cases
    if n <= 1:
        return n
    
    # Recursive cases - notice how this creates a binary tree
    left_result = fibonacci_with_tree(n-1, tree, node_id)
    right_result = fibonacci_with_tree(n-2, tree, node_id)
    
    return left_result + right_result

def visualize_fibonacci(n):
    global node_counter
    node_counter = 0  # Reset counter
    
    # Create a directed graph
    dot = graphviz.Digraph(comment=f'Recursion Tree for Fibonacci({n})')
    
    # Generate the tree while executing the function
    result = fibonacci_with_tree(n, dot)
    
    # Add a title to the graph
    dot.attr(label=f'Recursion Tree for Fibonacci({n}) = {result}')
    
    return dot

# 2. FACTORIAL
def factorial_with_tree(n, tree, parent_id=None):
    # Create node ID for this operation
    node_id = get_node_id()
    
    # Add node to graph
    tree.node(node_id, f"fact({n})")
    
    # Connect to parent if exists
    if parent_id is not None:
        tree.edge(parent_id, node_id)
    
    # Base case
    if n <= 1:
        return 1
    
    # Recursive case - creates a linear chain
    result = n * factorial_with_tree(n-1, tree, node_id)
    return result

def visualize_factorial(n):
    global node_counter
    node_counter = 0  # Reset counter
    
    # Create a directed graph
    dot = graphviz.Digraph(comment=f'Recursion Tree for Factorial({n})')
    
    # Generate the tree while executing the function
    result = factorial_with_tree(n, dot)
    
    # Add a title to the graph
    dot.attr(label=f'Recursion Tree for Factorial({n}) = {result}')
    
    return dot

# 3. BINARY SEARCH
def binary_search_with_tree(arr, target, low, high, tree, parent_id=None):
    # Create node ID for this operation
    node_id = get_node_id()
    
    # Add node to graph with the current subarray
    tree.node(node_id, f"BinarySearch({low}:{high})\nTarget: {target}\nSubarray: {arr[low:high+1]}")
    
    # Connect to parent if exists
    if parent_id is not None:
        tree.edge(parent_id, node_id)
    
    # Base case: element not found
    if low > high:
        return -1
    
    # Find middle element
    mid = (low + high) // 2
    
    # If element is at mid
    if arr[mid] == target:
        return mid
    
    # If element is smaller than mid, look in left subarray
    if arr[mid] > target:
        return binary_search_with_tree(arr, target, low, mid-1, tree, node_id)
    
    # Else look in right subarray
    return binary_search_with_tree(arr, target, mid+1, high, tree, node_id)

def visualize_binary_search(arr, target):
    global node_counter
    node_counter = 0  # Reset counter
    
    # Create a directed graph
    dot = graphviz.Digraph(comment=f'Recursion Tree for Binary Search')
    
    # Sort the array (binary search requires a sorted array)
    arr.sort()
    
    # Generate the tree while executing the function
    result = binary_search_with_tree(arr, target, 0, len(arr)-1, dot)
    
    # Add a title to the graph
    if result != -1:
        dot.attr(label=f'Recursion Tree for Binary Search\nTarget: {target}, Found at index: {result}\nArray: {arr}')
    else:
        dot.attr(label=f'Recursion Tree for Binary Search\nTarget: {target}, Not found\nArray: {arr}')
    
    return dot

# 4. TOWER OF HANOI
def hanoi_with_tree(n, source, auxiliary, target, tree, parent_id=None):
    # Create node ID for this operation
    node_id = get_node_id()
    
    # Add node to graph
    tree.node(node_id, f"Hanoi({n}, {source}, {auxiliary}, {target})")
    
    # Connect to parent if exists
    if parent_id is not None:
        tree.edge(parent_id, node_id)
    
    # Base case
    if n == 1:
        return [(source, target)]
    
    # Recursive cases - creates a ternary tree structure
    moves = []
    
    # Move n-1 disks from source to auxiliary
    moves.extend(hanoi_with_tree(n-1, source, target, auxiliary, tree, node_id))
    
    # Move the largest disk from source to target
    moves.append((source, target))
    
    # Move n-1 disks from auxiliary to target
    moves.extend(hanoi_with_tree(n-1, auxiliary, source, target, tree, node_id))
    
    return moves

def visualize_hanoi(n):
    global node_counter
    node_counter = 0  # Reset counter
    
    # Create a directed graph
    dot = graphviz.Digraph(comment=f'Recursion Tree for Tower of Hanoi({n})')
    
    # Generate the tree while executing the function
    moves = hanoi_with_tree(n, 'A', 'B', 'C', dot)
    
    # Add a title to the graph
    dot.attr(label=f'Recursion Tree for Tower of Hanoi({n})\nNumber of moves: {len(moves)}')
    
    return dot

# Generate and save all the visualizations
def generate_all_visualizations():
    # Fibonacci for n=5
    fib_tree = visualize_fibonacci(5)
    fib_tree.render('fibonacci_tree', format='png', cleanup=True)
    print("Generated recursion tree for Fibonacci(5)")
    
    # Factorial for n=5
    fact_tree = visualize_factorial(5)
    fact_tree.render('factorial_tree', format='png', cleanup=True)
    print("Generated recursion tree for Factorial(5)")
    
    # Binary Search with a sorted array
    arr = sorted(random.sample(range(1, 100), 10))
    # Choose a target that exists in the array
    target = arr[random.randint(0, len(arr)-1)]
    bin_search_tree = visualize_binary_search(arr, target)
    bin_search_tree.render('binary_search_tree', format='png', cleanup=True)
    print(f"Generated recursion tree for Binary Search (target: {target})")
    
    # Tower of Hanoi for n=3
    hanoi_tree = visualize_hanoi(3)
    hanoi_tree.render('hanoi_tree', format='png', cleanup=True)
    print("Generated recursion tree for Tower of Hanoi(3)")

# Run the function to generate all visualizations
generate_all_visualizations()
