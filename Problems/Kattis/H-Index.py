
n = int(input())

c = []
for i in range(n):
    c.append(int(input()))

c.sort(reverse=True)

H = -1
for i in range(n):
    H = max(H, min(c[i], i + 1))

print(H)