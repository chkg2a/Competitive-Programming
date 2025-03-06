import graphviz

def Guess(x, n, tree, parent_id=None, node_id=None):
    if node_id is None:
        node_id = f"Graph({x},{n})"

    tree.node(node_id, node_id)

    if parent_id is not None:
        tree.edge(parent_id, node_id)

    if n == 1:
        return x
    if n & 1 == 0:
        child_id = f"Guess({x+x},{n//2})"
        result = Guess(x+x,n//2,tree, node_id, child_id)
        return result
    else:
        child_id = f"Guess({x+x},{n//2})"
        result = x + Guess(x+x,n//2,tree,node_id, child_id)
        return result

def visualize_graph(x,n):
    dgraph = graphviz.Digraph(comment=f"Graph Representation of Guess({x},{n})")
    result = Guess(x,n,dgraph)
    dgraph.attr(label=f"Recursion Tree for Guess({x},{n}) = {result}")
    return dgraph

for params in [[3,7], [5,20],[6,9]]:
    x, n = params
    tree = visualize_graph(x,n)
    tree.render(filename=f"guess_tree_{x}_{n}", format="png", cleanup=True)
    print(f"Successfully saved for Guess({x},{n})")
