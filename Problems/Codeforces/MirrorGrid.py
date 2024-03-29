
def rotate(i, j):
    return j, N - i - 1

T = int(input())
for _ in range(T):

    N = int(input())

    A = []
    for i in range(N):
        A.append(input())

    ans = 0
    for i in range(N):
        for j in range(N):
            x = i; y = j; s = 0
            for _ in range(4):
                s += int(A[x][y])
                x, y = rotate(x, y)
            ans += min(s, 4 - s)

    print(ans // 4)
