def generate_pythagorean_triplets(A, B):
    m = 2
    c = 0

    while c < B:
        for n in range(1, m):
            a = m * m - n * n
            b = 2 * m * n
            c = m * m + n * n

            if c > B:
                break

            if A <= a and A <= B and a + b + c == 1000:
                return a, b, c

        m += 1


a,b,c = generate_pythagorean_triplets(1, 1001)

print(a*b*c)
