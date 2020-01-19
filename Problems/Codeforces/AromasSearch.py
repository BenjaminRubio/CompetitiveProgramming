
x0, y0, ax, ay, bx, by = list(map(int, input().strip().split()))
xs, ys, t = list(map(int, input().strip().split()))

xt = x0
yt = y0

x = []
y = []

d = 0

while True:
    x.append(xt)
    y.append(yt)
    delta = (ax * xt + bx - xt) + (ay * yt + by - yt)
    if d + delta <= 5 * t:
        d += delta
    else:
        break
    xt = ax * xt + bx
    yt = ay * yt + by

ans = 0

for i in range(len(x)):
    d = abs(xs - x[i]) + abs(ys - y[i])

    if d > t:
        continue

    aux = 1
    for j in range(i + 1, len(x)):
        delta = x[j] - x[j - 1] + y[j] - y[j - 1]
        if d + delta <= t:
            aux += 1
            d += delta
        else:
            break

    ans = max(ans, aux)

    d = abs(xs - x[i]) + abs(ys - y[i])

    aux = 1
    for j in range(i - 1, 0, -1):
        delta = x[j + 1] - x[j] + y[j + 1] - y[j]
        if d + delta <= t:
            aux += 1
            d += delta
        else:
            break

    ans = max(ans, aux)

print(ans)
