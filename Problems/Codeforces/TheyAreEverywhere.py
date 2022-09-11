
N = int(input())
S = input()

total = len({c for c in S})

M = {c : 0 for c in S}
ans = N; cnt = 0; pos = 0
for i in range(N):

    while pos < N and cnt < total:
        M[S[pos]] += 1
        if M[S[pos]] == 1:
            cnt += 1
        pos += 1

    if cnt == total:
        ans = min(ans, pos - i)
    
    M[S[i]] -= 1
    if M[S[i]] == 0:
        cnt -= 1

print(ans)
