import sys

m = 0; n = 0; M = []; V = []
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]


def paint(i, j):
    cadena = [(i, j)]
    while cadena:
        now = cadena.pop(); i_ = now[0]; j_ = now[1]
        V[i_][j_] = True
        for k in range(4):
            if i_ + dx[k] >= 0 and i_ + dx[k] < m and j_ + dy[k] >= 0 and j_ + dy[k] < n:
                if M[i_ + dx[k]][j_ + dy[k]] == '-' and (not V[i_ + dx[k]][j_ + dy[k]]):
                    cadena.append((i_ + dx[k], j_ + dy[k]))


T = 1
while True:

    line = sys.stdin.readline()
    if line == "":
        break
    m, n = list(map(int, line.split()))

    M = []
    for _ in range(m):
        M.append(input().strip())
    V = [[False for j in range(n)] for i in range(m)]

    ans = 0
    for i in range(m):
        for j in range(n):
            if not V[i][j] and M[i][j] == '-':
                ans += 1
                paint(i, j)
    
    print(f"Case {T}: {ans}")
    T += 1