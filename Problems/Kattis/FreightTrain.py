
T = int(input())
for _ in range(T):

    N, W, L = list(map(int, input().split()))

    w = list(map(lambda x: int(x) - 1, input().split()))

    left = 1; right = N
    while left < right:

        mid = (left + right) // 2

        aux = 1; i = 0; l = 0; r = mid - 1
        while i < W:

            if w[i] > r:
                aux += 1
                l = w[i]
                r = l + mid - 1

            while i < W and w[i] <= r:
                i += 1
            if i == W:
                break

            aux += 1
            l = r + 1
            r = l + mid - 1

        if r < N:
            aux += 1

        if aux <= L:
            right = mid
        else:
            left = mid + 1

    print(left)
