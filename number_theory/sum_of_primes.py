def sum_of_primes(no):
    arr = [0 if i % 2 == 0 else 1 for i in range(no)]

    arr[0] = arr[1] = 0
    arr[2] = 1
    s = 2

    for i in range(3, no, 2):
        if arr[i] == 1:
            s += i

        for j in range(i * i, no, i):
            arr[j] = 0

    return s


a = int(input("enter number: "))

print(sum_of_primes(a))
