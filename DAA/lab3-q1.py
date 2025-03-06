import random
import time
import matplotlib.pyplot as plt

def unordered_dc_search(L, x):
    comparisons = [0]
    def search_helper(L, x, offset=0):
        if len(L) == 1:
            comparisons[0] += 1
            return offset if L[0] == x else -1
        
        mid = len(L) // 2
        i = search_helper(L[:mid], x, offset)
        if i != -1:
            return i
            
        j = search_helper(L[mid:], x, offset + mid)
        return j
        
    time_start = time.time()
    index = search_helper(L, x)
    return index, round((time.time() - time_start) * 1000, 4), comparisons[0]

def binary_search(L, x):
    def search_helper(L, x, low, high):
        if low > high:
            return -1
        mid = low + (high - low) // 2
        comparisons[0] += 1
        if L[mid] == x:
            return mid
        elif L[mid] > x:
            return search_helper(L, x, low, mid - 1)
        else:
            return search_helper(L, x, mid + 1, high)

    comparisons = [0]
    time_start = time.time()
    index = search_helper(L, x, 0, len(L) - 1)
    return index, round((time.time() - time_start) * 1000, 4), comparisons[0]

def linear_search(L, x):
    comparisons = 0
    time_start = time.time()
    for i, item in enumerate(L):
        comparisons += 1
        if item == x:
            return i, round((time.time() - time_start) * 1000, 4), comparisons
    return -1, round((time.time() - time_start) * 1000, 4), comparisons

def print_data(data):
    for name, values in data.items():
        print(f"{name:<15}", end="")
        for value in values:
            print(f"{value:<15}", end="")
        print()

def plot_results(comparison_data, time_data, algorithm_name):
    plt.figure(figsize=(12, 6))

    plt.subplot(1, 2, 1)
    for key in ["cmp 1st", "cmp last", "cmp N/A"]:
        plt.plot(comparison_data["n"], comparison_data[key], marker='o', label=key)
    plt.title(f"{algorithm_name}: Element Comparisons")
    plt.xlabel("n")
    plt.ylabel("Comparisons")
    plt.legend()

    plt.subplot(1, 2, 2)
    for key in ["t 1st", "t last", "t N/A"]:
        plt.plot(time_data["n"], time_data[key], marker='o', label=key)
    plt.title(f"{algorithm_name}: Execution Time")
    plt.xlabel("n")
    plt.ylabel("Time (ms)")
    plt.legend()

    plt.tight_layout()
    plt.show()

def run_experiment(n, search_function, sort_before=False):
    datas = {
        "n": n,
        "cmp 1st": [],
        "cmp last": [],
        "cmp N/A": [],
    }
    datas_t = {
        "n": n,
        "t 1st": [],
        "t last": [],
        "t N/A": [],
    }

    for size in n:
        first_ele = random.randint(1, 100000)
        last_ele = first_ele
        while last_ele == first_ele:
            last_ele = random.randint(1, 100000)
        not_found = 1000001

        L = [first_ele]
        unique_numbers = {first_ele}
        for _ in range(size - 2):
            while True:
                num = random.randint(1, 100000)
                if num not in unique_numbers:
                    L.append(num)
                    unique_numbers.add(num)
                    break
        L.append(last_ele)

        
        if sort_before:
            L.sort()

        i, t_value_first_ele, e_value_first_ele = search_function(L, L[0])
        j, t_value_last_ele, e_value_last_ele = search_function(L, L[-1])
        k, t_value_not_found, e_value_not_found = search_function(L, not_found)
        print(f"{search_function.__name__} : {i} {j} {k}")

        datas["cmp 1st"].append(e_value_first_ele)
        datas["cmp last"].append(e_value_last_ele)
        datas["cmp N/A"].append(e_value_not_found)

        datas_t["t 1st"].append(t_value_first_ele)
        datas_t["t last"].append(t_value_last_ele)
        datas_t["t N/A"].append(t_value_not_found)

    return datas, datas_t

if __name__ == "__main__":
    n = [10, 100, 1000, 10000]

    
    ls_data, ls_data_t = run_experiment(n, linear_search)
    us_data, us_data_t = run_experiment(n, unordered_dc_search)
    bs_data, bs_data_t = run_experiment(n, binary_search, sort_before=True)

    
    print("\nLinear Search : ")
    print_data(ls_data)
    print()
    print_data(ls_data_t)
    print()

    print("Unordered Divide and Conquer Search : ")
    print_data(us_data)
    print()
    print_data(us_data_t)
    print()

    print("Binary Search : ")
    print_data(bs_data)
    print()
    print_data(bs_data_t)

    # plot_results(ls_data, ls_data_t, "Linear Search")
    # plot_results(us_data, us_data_t, "Unordered Divide and Conquer Search")
    # plot_results(bs_data, bs_data_t, "Binary Search")
