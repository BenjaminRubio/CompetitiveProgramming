
T = int(input())
for _ in range(T):

    N = int(input())
    
    for i in range(N):
        print('(' * i + '()' * (N - i) + ')' * i)
