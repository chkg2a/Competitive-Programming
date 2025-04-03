def opt1(i,X):
    if X < 0:
        return float("-inf")
    elif i == 0:
        return 0
    else:
        val1 = opt1(i-1,X)
        val2 = p[i] + opt1(i-1, X-w[i])
        if val2 > val1:
            return val2
        else:
            return val1 


if __name__ == "__main__":
    n = 3
    p = [1,2,5]
    w = [2,3,4]
    M = 6

    print(opt1(2,M))
