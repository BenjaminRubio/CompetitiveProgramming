
T = int(input())
for _ in range(T):

    N = int(input())
    A = list(map(int, input().split()))

    cnt = 0
    for i in range(N):
        while A[i] % 2 == 0:
            A[i] //= 2
            cnt += 1

    M = max(A)
    for _ in range(cnt):
        M *= 2

    print(M + sum(A) - max(A))
