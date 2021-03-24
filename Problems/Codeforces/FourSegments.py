
H, V = 0, 0
p = set()
s = set()

for _ in range(4):
    x, y, x_, y_ = list(map(int, input().split()))
    if x == x_:
        V += 1
    if y == y_:
        H += 1

    p.add((x, y)); p.add((x_, y_))
    s.add(((x, y), (x_, y_)))
    s.add(((x_, y_), (x, y)))

if len(s) != 8 or len(p) != 4 or H != 2 or V != 2:
    print("NO")
else:
    print("YES")
