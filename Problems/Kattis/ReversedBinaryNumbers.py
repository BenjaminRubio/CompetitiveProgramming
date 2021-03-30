
N = int(input())

binary = []
while N:
    binary.append(N & 1)
    N >>= 1

binary = binary[::-1]

ans = 0
for i in range(len(binary)):
    if binary[i]:
        ans += (1 << i)

print(ans)
