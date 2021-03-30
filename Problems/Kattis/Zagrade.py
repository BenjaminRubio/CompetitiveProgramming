
S = input().strip()
N = len(S)

s = []
P = []
for i in range(N):
    if S[i] == '(':
        s.append(i)
    if S[i] == ')':
        P.append((s.pop(), i))

M = len(P)

ans = set()
for b in range((1 << M) - 1):
    out = set()
    for i in range(M):
        if not (b & (1 << i)):
            out.add(P[i][0])
            out.add(P[i][1])
    
    aux = ""
    for i in range(N):
        if i not in out:
            aux += S[i]

    ans.add(aux)

for aux in sorted(list(ans)):
    print(aux)
