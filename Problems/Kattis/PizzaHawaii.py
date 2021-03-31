from collections import defaultdict

T = int(input())

for _ in range(T):

    N = int(input())

    S1 = defaultdict(list); S2 = defaultdict(list)
    for i in range(N):
        name = input()

        line = input().strip().split()
        for name in line[1:]:
            S1[name].append(i)

        line = input().strip().split()
        for name in line[1:]:
            S2[name].append(i)

    ans = []
    for e1 in S1.items():
        for e2 in S2.items():
            if e1[1] == e2[1]:
                ans.append((e1[0], e2[0]))

    ans.sort()

    for e in ans:
        print("({}, {})".format(*e))
    print()
