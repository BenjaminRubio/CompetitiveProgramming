
N = int(input())
s = input().strip()

ans = 0

l = '.'
for c in s:
    if l == c:
        ans += 1
    l = c

print(ans)
