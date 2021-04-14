
while True:

    N, B = list(map(int, input().split()))

    if N == -1:
        break

    P = [0] * N
    for i in range(N):
        P[i] = int(input())

    l = 1; r = 5000000
    while l < r:

        m = (l + r) // 2

        aux = 0
        for i in range(N):
            aux += P[i] // m + bool(P[i] % m)
        
        if aux <= B:
            r = m
        else:
            l = m + 1

    print(l)
    input()
