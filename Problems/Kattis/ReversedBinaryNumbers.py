
N = int(input())

ans = 0
while N:
    ans <<= 1
    if N & 1:
        ans += 1
    N >>= 1

print(ans)
