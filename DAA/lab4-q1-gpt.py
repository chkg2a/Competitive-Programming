import graphviz

def guess_with_tree(x, n, tree, parent_id=None, node_id=None):
    # Create a unique ID for this node if not provided
    if node_id is None:
        node_id = f"Guess({x},{n})"
    
    # Add this node to the graph
    tree.node(node_id, f"Guess({x},{n})")
    
    # If this node has a parent, connect it
    if parent_id is not None:
        tree.edge(parent_id, node_id)
    
    # Base case
    if n == 1:
        return x
    
    # Recursive cases
    if n % 2 == 0:  # n is even
        child_id = f"Guess({x+x},{n//2})"
        result = guess_with_tree(x + x, n // 2, tree, node_id, child_id)
        return result
    else:  # n is odd
        child_id = f"Guess({x+x},{n//2})"
        result = x + guess_with_tree(x + x, n // 2, tree, node_id, child_id)
        return result

def visualize_guess(x, n):
    # Create a directed graph
    dot = graphviz.Digraph(comment=f'Recursion Tree for Guess({x},{n})')
    
    # Generate the tree while executing the function
    result = guess_with_tree(x, n, dot)
    
    # Add a title to the graph
    dot.attr(label=f'Recursion Tree for Guess({x},{n}) = {result}')
    
    # Return the graph
    return dot

# Example usage for the specified test cases
for params in [(3, 7), (5, 20), (6, 9)]:
    x, n = params
    tree = visualize_guess(x, n)
    tree.render(f'guess_tree_{x}_{n}', format='png', cleanup=True)
    print(f"Generated tree for Guess({x}, {n})")
