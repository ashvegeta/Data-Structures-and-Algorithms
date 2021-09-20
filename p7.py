def find_nth_prime(n, nth_prime):
    l = [0 for i in range(0, n + 1)]

    l[2] = 1

    for i in range(3, n + 1, 2):
        l[i] = 1

    count = 1
    no = 0

    for i in range(3, n + 1, 2):
        if l[i] == 1:
            count += 1
            for j in range(i * i, n + 1, i):
                l[j] = 0

        if count == nth_prime:
            no = i
            break

    return no


print(find_nth_prime(200000, 10001))
