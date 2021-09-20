arr = [0] * 256


def fact(n):
    return 1 if n <= 1 else n * fact(n - 1)


def update(char):
    for i in range(ord(char), len(arr)):
        arr[i] -= 1


def populate_list(string):
    for i in string:
        arr[ord(i)] += 1

    for i in range(1, len(arr)):
        arr[i] += arr[i - 1]


def rank(S):
        l = len(S)
        res = 1
        populate_list(S)

        for i in range(l):
            chars = arr[ord(S[i]) - 1]
            f = fact(l - 1 - i)

            res += (chars * f)
            update(S[i])

        return res


print(rank("string"))
