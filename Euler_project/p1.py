t1 = 1
t2 = 2
even_sum = 0
s = t1 + t2

while t2 <= 4000000:
    if t2 % 2 == 0:
        even_sum += t2

    t1 = t2
    t2 = s
    s = t1 + t2

print(even_sum)
