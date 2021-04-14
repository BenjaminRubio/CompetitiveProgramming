
N, Q = list(map(int, input().split()))
A = list(map(int, input().split()))

for _ in range(Q):

    q = int(input())

    l = 0; r = N
    while l < r:
        m = (l + r) // 2

        if A[m] >= q + 1:
            r = m
        else:
            l = m + 1
    l -= 1

    if A[l] != q:
        print(-1)
    else:
        print(l)
