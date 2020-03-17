
k = int(input())

for _ in range(k):

    n = int(input())
    a = list(map(int, input().split()))

    a.sort()

    for i in range(n):
        if a[i] >= n - i:
            print(n - i)
            break