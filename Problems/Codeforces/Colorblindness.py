
T = int(input())
for _ in range(T):

    N = int(input())
    A = input()
    B = input()

    ans = True
    for i in range(N):
        if (A[i] == 'R' or B[i] == 'R') and A[i] != B[i]:
            ans = False
    
    if ans:
        print("YES")
    else:
        print("NO")
