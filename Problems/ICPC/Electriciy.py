
def next_day(D, M, Y):

    if M in {1, 3, 5, 7, 8, 10, 12}:
        if D < 31:
            return D + 1, M, Y
        elif M < 12:
            return 1, M + 1, Y
        else:
            return 1, 1, Y + 1

    elif M in {4, 6, 9, 11}:
        if D < 30:
            return D + 1, M, Y
        else:
            return 1, M + 1, Y
    
    else:
        leap = ((Y % 4 == 0) and (Y % 100 != 0)) or (Y % 400 == 0)

        if D < 28 + leap:
            return D + 1, M, Y
        else:
            return 1, 3, Y

if __name__ == "__main__":
    
    while True:

        N = int(input())
        if N == 0:
            break

        prev = None
        c = 0
        s = 0
        for _ in range(N):
            now = tuple(map(int, input().strip().split()))

            if prev and now[:-1] == next_day(*prev[:-1]):
                c += 1
                s += now[3] - prev[3]
            prev = now
        
        print(c, s)
