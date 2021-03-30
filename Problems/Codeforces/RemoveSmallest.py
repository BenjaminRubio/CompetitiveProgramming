
T = int(input())

for _ in range(T):

    N = int(input())
    A = list(map(int, input().split()))

    A.sort()

    l = -1; ans = 0
    for x in A:
        if x > l + 1:
            ans += 1
        l = x
    
    if ans == 1:
        print("YES")
    else:
        print("NO")
