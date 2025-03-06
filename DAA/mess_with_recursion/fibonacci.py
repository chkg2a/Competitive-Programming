import graphviz

i = 0
node_counter = f"node_counter_0"
def get_node_id():
    global node_counter, i
    i += 1
    node_counter = f"node_counter_{i}"
    return node_counter

def fibonacci(n, tree, parent_id=None):
    node_id = get_node_id()

    tree.node(node_id, f"fib({n})")

    if parent_id is not None:
        tree.edge(parent_id,node_id)
    
    if n <= 1:
        return n
    
    left_result = fibonacci(n-1,tree,node_id)
    right_result = fibonacci(n-2,tree,node_id)
    return left_result + right_result

def visualize_graph(n):
    dot = graphviz.Digraph()
    result = fibonacci(n, dot)
    dot.attr(label=f"Graph representation for fibonacci({n}) = {result}")
    return dot

n = 7
tree = visualize_graph(n)
tree.render(f"fibonacci({n})", format="png", cleanup=True)
