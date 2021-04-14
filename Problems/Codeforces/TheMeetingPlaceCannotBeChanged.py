
n = int(input())

x = list(map(int, input().split()))
v = list(map(int, input().split()))

l = 0; r = 1e9 + 1
for _ in range(1000):

    m = (l + r) * 0.5

    L = -2e9; R = 2e9
    for i in range(n):
        L = max(L, x[i] - v[i] * m)
        R = min(R, x[i] + v[i] * m)

    if R >= L:
        r = m
    else:
        l = m

print(round((l + r) / 2, 10))
