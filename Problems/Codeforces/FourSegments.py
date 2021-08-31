
H, V = 0, 0

S = []
for _ in range(4):
    x, y, x_, y_ = list(map(int, input().split()))
    S.append(((x, y), (x_, y_)))
    if x == x_:
        V += 1
    if y == y_:
        H += 1

ans = True
for s in S:
    cnt1 = 0; cnt2 = 0
    for s_ in S:
        cnt1 += (s[0] in s_)
        cnt2 += (s[1] in s_)
    if cnt1 != 2 or cnt2 != 2:
        ans = False

print("YES" if (ans and H == 2 and V == 2) else "NO")
