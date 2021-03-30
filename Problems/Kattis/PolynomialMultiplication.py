
T = int(input())

for _ in range(T):
    N1 = int(input())
    C1 = list(map(int, input().split()))
    N2 = int(input())
    C2 = list(map(int, input().split()))

    ans = [0] * (N1 + N2 + 1)
    for i in range(N1 + 1):
        for j in range(N2 + 1):
            ans[i + j] += C1[i] * C2[j]

    print(N1 + N2)
    print(' '.join(map(str, ans)))
