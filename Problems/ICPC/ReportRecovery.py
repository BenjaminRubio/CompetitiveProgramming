
from pprint import pprint

N = None
P = None
names = []
numbers = []
totals = None
pos = None

def check1(p, curr):
    s = 0
    l = 0
    for i in curr[:-1]:
        s += int(numbers[p][l : i])
        l = i
    if s == int(numbers[p][l : curr[-1]]):
        return True
    return False

def generate_pos(p, i, n, curr):
    if n > N + 1:
        return
    if i == len(numbers[p]):
        if n == N + 1:
            if check1(p, curr.copy()):
                pos[p].append(curr.copy())
        return

    for j in range(i, max(i + 1, int(numbers[p][i] != '0') * len(numbers[p]))):
        curr.append(j + 1)
        generate_pos(p, j + 1, n + 1, curr.copy())
        curr = curr[:-1]

def check2(curr):
    l = [0 for _ in range(P + 1)]
    for i in range(N + 1):
        s = 0
        for j in range(P):
            s += int(numbers[j][l[j] : pos[j][curr[j]][i]])
            l[j] = pos[j][curr[j]][i]
        if s != int(numbers[-1][l[-1] : pos[-1][curr[-1]][i]]):
            return False
        l[-1] = pos[-1][curr[-1]][i]
    return True

def final(p, curr):
    if p == P + 1:
        if check2(curr.copy()):

            print("gg")

            return True
        return False

    for i in range(len(pos[p])):
        curr.append(i)
        if final(p + 1, curr.copy()):
            return True
        curr = curr[:-1]
    return False

if __name__ == "__main__":

    T = int(input())

    for t in range(T):

        N = len(input().strip().split('P')[1:])
        numbers = []
        names = []

        while True:

            line = input().strip()
            name = ""
            nums = ""

            for l in line:
                if l.isalpha():
                    name += l
                else:
                    nums += l

            numbers.append(nums)
            names.append(name)

            if name == "TP":
                break

        P = len(names) - 1

        pos = [[] for i in range(P + 1)]

        for i in range(P + 1):
            generate_pos(i, 0, 0, [])

        final(0, [])

        pprint(pos)
