def permute(arr, p):
    new_arr = [0] * len(arr)

    for i in range(0, len(p)):
        new_arr[p[i]] = arr[i]

    return new_arr


arr = [5, 6, 7, 8]
p = [2, 1, 3, 0]

print(permute(arr, p))
