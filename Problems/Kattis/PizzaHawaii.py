from collections import defaultdict

T = int(input())

for _ in range(T):

    N = int(input())

    S1 = defaultdict(int); S2 = defaultdict(int)
    for i in range(N):
        name = input()

        line = input().strip().split()
        for name in line[1:]:
            S1[name] |= (1 << i)

        line = input().strip().split()
        for name in line[1:]:
            S2[name] |= (1 << i)

    M1 = defaultdict(list); M2 = defaultdict(list)
    for e in S1.items():
        M1[e[1]].append(e[0])
    for e in S2.items():
        M2[e[1]].append(e[0])

    ans = []
    for e in M1.items():
        for name1 in e[1]:
            for name2 in M2[e[0]]:
                ans.append((name1, name2))

    ans.sort()

    for e in ans:
        print("({}, {})".format(*e))
    print()
