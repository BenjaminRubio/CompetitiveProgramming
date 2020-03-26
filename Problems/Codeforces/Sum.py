
sa, sb = input().strip().split()

base = max(int(c) for c in sa + sb) + 1

a = int(sa); b = int(sb)

ans = 0; prev = 0
while a + b + prev:
    prev = (a % 10 + b % 10 + prev) // base
    a //= 10; b //= 10
    ans += 1

print(ans)