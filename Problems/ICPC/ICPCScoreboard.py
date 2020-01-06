
T = 0
P = 0
results = [[0, 0, 0] for _ in range(101)]


def get_order(p_):

    r = [[0, 0, i] for i in range(T)]
    for i in range(T):
        r[i][0] = -1 * results[i][0]
        r[i][1] = results[i][2] + p_ * results[i][1]

    r.sort()

    pos = []
    for i in range(T):
        if i > 0:
            if r[i][0] == r[i - 1][0] and r[i][1] == r[i - 1][1]:
                pos[-1].append(r[i][2])
        pos.append([r[i][2]])

    return pos


if __name__ == "__main__":

    while True:

        T, P = list(map(int, input().strip().split()))

        if T == 0 and P == 0:
            break

        results = [[0, 0, 0] for _ in range(T)]
        for i in range(T):
            res = input().strip().split()
            for r in res:
                a, p = r.split('/')

                if p != '-':
                    results[i][0] += 1
                    results[i][2] += int(p)
                    results[i][1] += int(a) - 1

        p20 = get_order(20).copy()

        l = 1
        r = 20
        while l < r:
            m = int((l + r) / 2)
            if get_order(m) == p20:
                r = m
            else:
                l = m + 1
        low = l

        l = 20
        r = 10000
        while l < r:
            m = int((l + r) / 2)
            if get_order(m) != p20:
                r = m
            else:
                l = m + 1
        high = l - 1
        if high == 9999:
            high = '*'

        print(low, high)
