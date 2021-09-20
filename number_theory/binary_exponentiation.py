from time import time


def power(base, n):
    res = 1
    st = time()
    for i in range(n):
        res *= base
    et = time()

    return res, (et - st)


def fast_power(base, n):
    res = 1

    st = time()
    while n > 0:
        if n % 2 == 0:
            n /= 2
            base *= base
        else:
            n -= 1
            res *= base

    et = time()
    return res, (et - st)


no, n = input("enter base and power: ").split()
no, n = int(no), int(n)
res1, t1 = power(no, n)
res2, t2 = fast_power(no, n)

print("\ntime taken (normal exponentiation): ", t1, "sec")
print("time taken (binary exponentiation): ", t2, "sec")
print("time factor: ", (t1 / (t2 + 1e-10)),"X")
