import time
from math import sqrt


def is_prime_normal(a, b):
    count = 0
    st = time.time()
    for i in range(a, b + 1):
        start = 1
        for j in range(2, int(sqrt(i) + 1)):
            if i % j == 0:
                start = 0
                break

        if start == 1:
            # print(i)
            count += 1

    et = time.time()

    t2 = et - st
    print("time taken (normal) : ", t2, "\n")
    return count, t2


def is_prime(arr, a, b):
    arr[0] = arr[1] = 0
    arr[2] = 1
    count = 0
    st = time.time()
    # initially mark every odd no as prime
    for i in range(3, b + 1, 2):
        arr[i] = 1

    # for each prime mark all its multiples as non prime
    for i in range(3, b + 1, 2):
        if arr[i] == 1:
            if i >= a:
                count += 1
                # print(i)
            for j in range(i * i, b + 1, i):
                arr[j] = 0

    et = time.time()
    t1 = et - st
    print("time taken (sieve) : ", t1, "\n")

    return count, t1


a, b = input("enter range:").split()
a, b = int(a), int(b)

arr = [0 for i in range(0, b + 1)]
c1, t1 = is_prime(arr, a, b)
c2, t2 = is_prime_normal(a, b)

# print(c1, c2)
print("time factor : ",t2/t1)
