
N, T = list(map(int, input().split()))

l = 1e9; r = 1e7
D = [0] * N; V = [0] * N
for i in range(N):
    D[i], V[i] = list(map(int, input().split()))

for i in range(N):
    l = min(l, V[i])
l = -l

for _ in range(1000):

    m = (l + r) * 0.5

    t = 0
    for i in range(N):
        t += D[i] / (V[i] + m)

    if t < T:
        r = m
    else:
        l = m

print(round((l + r) / 2, 10))
