
K = [['q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'],
     ['a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'],
     ['z', 'x', 'c', 'v', 'b', 'n', 'm']]

X = {}; Y = {}
for i in range(3):
    for j in range(len(K[i])):
        X[K[i][j]] = i
        Y[K[i][j]] = j

T = int(input())

for _ in range(T):

    s, N = input().split()

    N = int(N)

    ans = []
    for __ in range(N):
        
        w = input().strip()

        score = 0
        for i in range(len(w)):
            score += abs(X[w[i]] - X[s[i]]) + abs(Y[w[i]] - Y[s[i]])

        ans.append((score, w))

    ans.sort()

    for e in ans:
        print(e[1], e[0])
