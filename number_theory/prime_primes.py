arr = [0 for i in range(1000000 + 1)]
prime_primes = [0 for i in range(1000000 + 1)]


def find_primes(b):
    temp = [0 for i in range(b + 1)]

    arr[2] = 1
    temp[2] = 1
    pp_c = 0

    # initially mark every odd no as prime
    for i in range(3, b + 1, 2):
        arr[i] = 1
        temp[i] = 1

    # for each prime mark all its multiples as non prime
    for i in range(3, b + 1, 2):
        if arr[i] == 1:
            for j in range(i * i, b + 1, i):
                arr[j] = 0
                temp[j] = 0

    for i in range(3, b + 1):
        arr[i] += arr[i - 1]

        if temp[arr[i]] == 1:
            pp_c += 1
            prime_primes[i] = pp_c
        else:
            prime_primes[i] = pp_c

    del temp


a, b = map(int, input("enter a,b: ").split())

find_primes(1000000)

print("no of primes in range", str(a) + " to " + str(b) + ": ", arr[b] - arr[a - 1])
print("no of prime primes in range", str(a) + " to " + str(b) + ": ", prime_primes[b] - prime_primes[a - 1])

# for i in range(a, b + 1):
#     print(i, prime_primes[i])
