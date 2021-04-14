
N, L = list(map(int, input().split()))

a = list(map(int, input().split()))
a.sort()

l = 0; r = 1e9
for _ in range(1000):

    m = (l + r) * 0.5

    check = True
    t = 0
    for i in range(N):
        if t < a[i] - m:
            check = False
        t = a[i] + m
    if t < L:
        check = False

    if check:
        r = m
    else:
        l = m

print(round((l + r) / 2, 12))
