
T = int(input())

for _ in range(T):

    a, b, c, r = list(map(int, input().split()))

    if a > b:
        a, b = b, a
    
    if c + r < a or c - r > b:
            print(b - a)
    else:
        print(max(0, (c - r) - a) + max(0, b - (c + r)))
