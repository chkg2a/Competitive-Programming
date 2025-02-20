import matplotlib.pyplot as plt
import numpy as np
import math

n = np.arange(1,16)

log2n = np.log10(np.log2(n), where=np.log2(n) > 0)
nlog2n = np.log10(n * np.log2(n), where=np.log2(n) > 0)
n2 = np.log10(n ** 2)
n3 = np.log10(n ** 3)
n4 = np.log10(n ** 4)
twoN = np.log10(2 ** n)
nfact = np.log10([math.factorial(i) for i in n])

functions = {
    "log2(n)" : log2n,
    "nlog2(n)" : nlog2n,
    "n^2" : n2,
    "n^3" : n3,
    "n^4" : n4,
    "2^n" : twoN,
    "n!" : nfact,
}
plt.figure(figsize=(15, 8))

bar_width = 0.15
offsets = np.arange(len(functions)) * bar_width

for i, (name, values) in enumerate(functions.items()):
    plt.plot(n + offsets[i], values,label=f"{name} (line)")
    plt.bar(n + offsets[i], values, width=bar_width, label=f"{name} (bar)")

plt.legend()
plt.xlabel("n")
plt.ylabel("log10(f(n))")
plt.title("Comparison of Growth Rates of Functions")
plt.show()
