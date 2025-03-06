import networkx as nx
import matplotlib.pyplot as plt

# Step 1: Store recursion relationships
graph = nx.DiGraph()
node_counter = 0  # Unique identifier for each function call

def add_node(graph, parent, label):
    global node_counter
    node_name = f"{label}_{node_counter}"  # Unique name
    graph.add_node(node_name, label=label)
    if parent is not None:
        graph.add_edge(parent, node_name)
    node_counter += 1
    return node_name

# Step 2: Recursive Fibonacci Function (Modified to Log Calls)
def fibonacci(n, parent=None):
    if n <= 1:
        return add_node(graph, parent, str(n))
    
    current = add_node(graph, parent, f"fib({n})")
    
    left = fibonacci(n - 1, current)
    right = fibonacci(n - 2, current)
    
    return current

# Step 3: Generate the Recursion Tree
fibonacci(4)  # Change this value to get deeper trees

# Step 4: Draw the Graph
pos = nx.spring_layout(graph, seed=42)  # Position nodes
labels = nx.get_node_attributes(graph, 'label')

plt.figure(figsize=(10, 6))
nx.draw(graph, pos, with_labels=True, labels=labels, node_color="lightblue", edge_color="gray", node_size=2000, font_size=10)
plt.title("Recursion Tree for Fibonacci(4)")
plt.show()
