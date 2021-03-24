
M = {}

N = int(input())
S = input().strip()

s = set()
for c in S:
    s.add(c)
    M[c] = 0

i = 0; j = -1; aux = 0; ans = 1e10
while j < N - 1:
    j += 1

    M[S[j]] += 1
    if M[S[j]] == 1:
        aux += 1
    while M[S[i]] > 1:
        M[S[i]] -= 1
        i += 1

    if aux == len(s):
        ans = min(ans, j - i + 1)

print(ans)
