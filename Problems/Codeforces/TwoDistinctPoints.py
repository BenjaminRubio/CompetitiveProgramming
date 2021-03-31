
Q = int(input())

for _ in range(Q):

    l1, r1, l2, r2 = list(map(int, input().split()))

    if l1 != l2:
        print(l1, l2)
    else:
        print(l1, r2)
