
w, m, k = list(map(int, input().split()))

ans = 0; c = 0; n = 0
while 10 ** n <= m:
    n += 1

while c + (10 ** (n) - m) * n * k  <= w:
    c += (10 ** (n) - m) * n * k
    ans += 10 ** (n) - m
    m = 10 ** n; n += 1
ans += (w - c) // (n * k)

print(ans)
