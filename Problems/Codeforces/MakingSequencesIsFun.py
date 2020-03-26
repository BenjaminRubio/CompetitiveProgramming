
w, m, k = list(map(int, input().split()))

ans = 0; c = 0
n = 0
while 10 ** n <= m:
    n += 1

if (10 ** n - m) * n * k >= w:
    print(w // (n * k))
    exit()
else:
    c += (10 ** n - m) * n * k
    ans += 10 ** n - m
n += 1
while c + 10 ** (n - 1) * 9 * n * k  <= w:
    c += 10 ** (n - 1) * 9 * n * k
    ans += 10 ** (n - 1) * 9
    n += 1
ans += (w - c) // (n * k)

print(ans)