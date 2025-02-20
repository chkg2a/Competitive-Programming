import random
import time
import matplotlib.pyplot as plt

def iterative_min(L):
    min = float('inf')
    comparision = 0
    time_start = time.time()
    for i in L:
        comparision += 1
        if i < min:
            min = i
    return round((time.time() - time_start) * 1000,4), comparision

def divide_and_conquer_min(L):
    comparision = [0]
    time_start = time.time()
    def min_helper(L):
        if len(L) == 1:
            return L[0]
        mid = len(L) // 2
        right_ele = min_helper(L[:mid])
        left_ele = min_helper(L[mid:])
        comparision[0] += 1
        return left_ele if left_ele < right_ele else right_ele
    result = min_helper(L)
    return round((time.time() - time_start) * 1000,4), comparision[0]

def print_data(data):
    for name, data in data.items():
        print(f"{name:<15}",end="")
        for i in range(len(data)):
            print(f"{data[i]:<15}",end="")
        print()

def plot_results(data, algorithm_name):
    
    plt.figure(figsize=(12, 6))
    plt.subplot(1, 2, 1)
    plt.plot(data["n"], data["e"], marker='o', label="Comparisons")
    plt.title(f"{algorithm_name}: Element Comparisons")
    plt.xlabel("n")
    plt.ylabel("Comparisons")
    plt.xscale("log")
    plt.yscale("log")
    plt.grid(True)
    plt.legend()
    
    plt.subplot(1, 2, 2)
    plt.plot(data["n"], data["t"], marker='o', color="red", label="Time (ms)")
    plt.title(f"{algorithm_name}: Execution Time")
    plt.xlabel("n")
    plt.ylabel("Time (ms)")
    plt.xscale("log")
    plt.yscale("log")
    plt.grid(True)
    plt.legend()

    plt.show()

if __name__ == "__main__":
    n = [10, 100, 1000, 10000, 100000]
    iterative_datas = {
        "n" : n,
        "e" : [],
        "t" : []
    }
    divide_and_conquer_datas = {
        "n" : n,
        "e" : [],
        "t" : []
    }

    for i in n:
        L = [random.randint(1, 100000) for _ in range(i)]
        t_value, e_value = iterative_min(L)
        iterative_datas["e"].append(e_value)
        iterative_datas["t"].append(t_value)

        t_value, e_value = divide_and_conquer_min(L)
        divide_and_conquer_datas["e"].append(e_value)
        divide_and_conquer_datas["t"].append(t_value)

    print("Iterative")
    print_data(iterative_datas)
    print("Divide and Conquer")
    print_data(divide_and_conquer_datas)
    plot_results(iterative_datas,"Iterative")
    plot_results(divide_and_conquer_datas,"Divide and Conquer")
    print()
