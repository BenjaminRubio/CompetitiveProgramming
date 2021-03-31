N, K = list(map(int, input().split()))

C = []; S = set()
for i in range(N):
    C.append(input().strip())
    S.add(C[-1])

ans = 0
for i in range(N):
    for j in range(i + 1, N):
        aux = ""
        for k in range(K):
            if C[i][k] == C[j][k]:
                aux += C[i][k]
            if (C[i][k] == 'S' and C[j][k] == 'E') or (C[i][k] == 'E' and C[j][k] == 'S'):
                aux += 'T'
            if (C[i][k] == 'S' and C[j][k] == 'T') or (C[i][k] == 'T' and C[j][k] == 'S'):
                aux += 'E'
            if (C[i][k] == 'T' and C[j][k] == 'E') or (C[i][k] == 'E' and C[j][k] == 'T'):
                aux += 'S'

        if aux in S:
            ans += 1

print(ans // 3)
