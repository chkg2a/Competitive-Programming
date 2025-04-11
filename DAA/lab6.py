import graphviz

def opt1(i, X, p, w, tree, parent_id = None, node_id = None):
    if node_id is None:
        node_id = f"opt({i},{X})"

    tree.node(node_id, node_id)
    if parent_id is not None:
        tree.edge(parent_id, node_id)

    if i == 0:
        return 0
    elif X < 0:
        return float("-inf")
    else:
        child_id = f"opt({i-1},{X},{p},{w})"
        val1 = opt1(i - 1, X, p, w, tree, node_id, child_id)
        child_id = f"{p[i-1]} + opt({i-1},{X - w[i - 1]},{p},{w})"
        val2 = p[i-1] + opt1(i - 1, X - w[i-1], p, w, tree, node_id, child_id)
        if val2 > val1:
            return val2
        else:
            return val1

if __name__ == "__main__":
    n = 3
    p = [1,2,5]
    w = [2,3,4]
    M = 6
    dgraph = graphviz.Digraph()
    result = opt1(n,M,p,w,dgraph)
    print(result)
    dgraph.render(filename="dgraph", format="png")
