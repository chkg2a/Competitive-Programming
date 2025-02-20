import math

TIME_LIMITS = {
    "1 second": 1e6,
    "1 minute": 60 * 1e6,
    "1 hour": 3600 * 1e6,
    "1 day": 86400 * 1e6,
}

def lg_n(t):
    exponent = t
    return f"2^{int(exponent):.2e}"

def sqrt_n(t):
    low = 0
    high = t ** 2
    mid = 0
    i = 0
    while (low < high):
        i+=1
        mid = low + (high - low)/2
        if(mid < high):
           low = mid + 1
        elif(mid > high):
           high = mid
        else:
            return mid
    return mid

def linear_n(t):
    low = 0
    high = t
    mid = 0
    while (low < high):
        mid = low + (high - low)/2
        if(mid < high):
           low = mid + 1
        elif(mid > high):
           high = mid
        else:
            return mid
    return mid

def n_lg_n(t):
    low = 1e-6
    high = t
    tolerance = 1e-6

    while high - low > tolerance:
        mid = low + (high - low) / 2
        mid_value = mid * math.log2(mid)

        if abs(mid_value - t) < tolerance:
            return mid
        elif mid_value < t:
            low = mid
        else:
            high = mid

    return (low + high) / 2

def n_squared(t):
    n = 1
    while n ** 2 <= t:
        n += 1
    return n - 1

def n_cubed(t):
    n = 1
    while n ** 3 <= t:
        n += 1
    return n - 1

def two_power_n(t):
    n = 1
    while 2 ** n <= t:
        n += 1
    return n - 1

def factorial_n(t):
    n = 1
    fact = 1
    while fact <= t:
        n += 1
        fact *= n
    return n - 1

FUNCTIONS = {
    "lg n": lg_n,
    "\u221a n": sqrt_n,
    "n": linear_n,
    "nlogn": n_lg_n,
    "n^2": n_squared,
    "n^3": n_cubed,
    "2^n": two_power_n,
    "n!": factorial_n,
}

results = []

for func_label, func in FUNCTIONS.items():
    row = []
    for time_label, time_value in TIME_LIMITS.items():
        row.append(func(time_value))
    results.append(row)

headers = ["", "1 second", "1 minute", "1 hour", "1 day"]
row_labels = list(FUNCTIONS.keys())

def format_value(value):
    if isinstance(value, str):
        return f"{value:<15}"
    elif value < 1e3:
        return f"{value:<15}"
    else:
        return f"{value:<15.2e}"

header_row = "".join(f"{header:<15}" for header in headers)
print(header_row)
print("-" * len(header_row))

for i, func_label in enumerate(FUNCTIONS):
    row = [f"{func_label:<15}"] + [format_value(results[i][j]) for j in range(len(TIME_LIMITS))]
    print("".join(row))
