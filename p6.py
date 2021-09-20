def sum_of_squares(n):
    s = n * (n+1) * (2*n+1) / 6

    return s


def squares_of_sum(n):
    s = n * (n + 1) / 2

    return s**2


print(abs(sum_of_squares(100) - squares_of_sum(100)))
