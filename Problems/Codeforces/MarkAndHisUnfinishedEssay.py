
T = int(input())
for _ in range(T):

    N, C, Q = list(map(int, input().split()))
    S = input()

    L = [0 for _ in range(C)]; R = [0 for _ in range(C)]
    for i in range(C):
        L[i], R[i] = list(map(int, input().split()))
        L[i] -= 1; R[i] -= 1
    
    for _ in range(Q):
        K = int(input()) - 1

        while K >= N:
            p = N - 1
            for i in range(C):
                ln = R[i] - L[i] + 1
                p += ln
                if K <= p:
                    K = L[i] - 1 + (K - (p - ln))
                    break
        
        print(S[K])
