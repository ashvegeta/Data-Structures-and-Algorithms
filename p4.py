largest = 0


def is_palindrome(no):
    n = no
    rev = 0

    while no > 0:
        rev = rev * 10 + no % 10
        no = int(no/10)

    if n == rev:
        return True
    else:
        return False


for i in range(101, 999):
    for j in range(101, 999):
        if is_palindrome(i * j):
            largest = max(largest,i * j)

print(largest)

