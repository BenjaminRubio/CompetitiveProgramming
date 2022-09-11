
T = int(input())
for _ in range(T):
    l1 = input()
    l2 = input()
    s = set([l1[0], l1[1], l2[0], l2[1]])
    print(len(s) - 1)
