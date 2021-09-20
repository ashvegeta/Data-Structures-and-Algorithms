def prime(n):
    for i in range(2, int(n / 2) + 1):
        if n % i == 0:
            return False

    return True


def biggest_prime(no):
    while not prime(no):
        for i in range(2, int(no / 2) + 1):
            if no % i == 0:
                no = no / i
                break

    return int(no)


factor = 600851475143
print(biggest_prime(factor))
