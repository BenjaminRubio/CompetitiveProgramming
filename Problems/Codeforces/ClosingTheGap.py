
T = int(input())
for _ in range(T):

    N = int(input())
    A = list(map(int, input().split()))

    S = sum(A)
    
    print(int(bool(S % N)))
