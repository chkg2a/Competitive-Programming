import time
import random
import matplotlib.pyplot as plt

def generate_list(n):
    return random.sample(range(n * 10), n)

def linear_search(A, x):
    comparisons = 0
    for i in range(len(A)):
        comparisons += 1
        if A[i] == x:
            return i, comparisons
    return -1, comparisons

def divide_and_conquer_search(A, x):
    comparisons = [0]
    def search_helper(L, x):
        if len(L) == 0:
            return -1
        if len(L) == 1:
            comparisons[0] += 1
            return 0 if L[0] == x else -1
        mid = len(L) // 2
        left_result = search_helper(L[:mid], x)
        if left_result != -1:
            return left_result
        right_result = search_helper(L[mid:], x)
        return mid + right_result if right_result != -1 else -1
    index = search_helper(A, x)
    return index, comparisons[0]

def measure_time_and_comparisons(search_function, A, x):
    start_time = time.time()
    index, comparisons = search_function(A, x)
    end_time = time.time()
    return comparisons, (end_time - start_time) * 1000

def run_experiment(search_function):
    ns = [10, 100, 1000, 10000]
    results = {
        "first": {"e": [], "t": []},
        "last": {"e": [], "t": []},
        "not_found": {"e": [], "t": []}
    }
    for n in ns:
        A = generate_list(n)
        first, last, not_in_list = A[0], A[-1], max(A) + 1
        for case, x in zip(["first", "last", "not_found"], [first, last, not_in_list]):
            e, t = measure_time_and_comparisons(search_function, A, x)
            results[case]["e"].append(e)
            results[case]["t"].append(t)
    return ns, results

def plot_combined_results(ns, results, title):
    fig, axes = plt.subplots(1, 2, figsize=(12, 5))
    for case, data in results.items():
        axes[0].plot(ns, data["e"], marker='o', label=f'{case} element')
        axes[1].plot(ns, data["t"], marker='o', label=f'{case} element')
    
    axes[0].set_xlabel("List Size (n)")
    axes[0].set_ylabel("Comparisons (e)")
    axes[0].set_title(f"{title}: Comparisons")
    axes[0].legend()
    
    axes[1].set_xlabel("List Size (n)")
    axes[1].set_ylabel("Time (ms)")
    axes[1].set_title(f"{title}: Time Taken")
    axes[1].legend()
    
    plt.tight_layout()
    plt.show()

# Running experiments for each search algorithm
for search_func, name in zip(
    [linear_search, divide_and_conquer_search ],
    ["Linear Search", "Divide and Conquer Search"],
):
    ns, results = run_experiment(search_func)
    plot_combined_results(ns, results, name)
