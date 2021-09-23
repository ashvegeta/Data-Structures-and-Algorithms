from math import sqrt


def triangle_number(no):
    return no * (no + 1) / 2


def count_divisors(no):
    count = 2
    root = sqrt(no)

    for i in range(2, int(root) + 1):
        if no % i == 0 and i != root:
            count += 2
        elif no % i == 0 and i == root:
            count += 1

    return count


def main():
    l = []

    for i in range(1, 1000000):
        l.append(triangle_number(i))

    for i in range(200, 1000000):
        if count_divisors(l[i]) >= 500:
            print("number : ", i + 1, " triangle number : ", l[i])
            break


if __name__ == "__main__":
    main()
