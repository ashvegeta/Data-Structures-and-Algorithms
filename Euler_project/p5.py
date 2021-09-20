def gcd(a, b):
    if a == 0:
        return b
    else:
        return gcd(b % a, a)


def lcm(a, b):
    return (a * b) / gcd(a, b)


def evenly_divisible(nos):
    ans = nos[-1]

    for i in range(len(nos) - 2, -1, -1):
        ans = lcm(ans, nos[i])

    return int(ans)


print(evenly_divisible([i for i in range(1, 21)]))
