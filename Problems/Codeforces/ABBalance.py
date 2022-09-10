
T = int(input())
for _ in range(T):

    S = input()
    N = len(S)

    print(S[:N - 1] + S[0])
