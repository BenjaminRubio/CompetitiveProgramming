
N = None
P = None
names = []
numbers = []
totals = None
ix = None


def check1(i):

    s = 0
    for j in range(N):
        s += int(numbers[i][ix[i][j][0]:ix[i][j][1]])

    if s != int(numbers[i][ix[i][N][0]:ix[i][N][1]]):
        return False

    return True


def check2():

    for j in range(N + 1):
        s = 0
        for i in range(P):
            s += int(numbers[i][ix[i][j][0]:ix[i][j][1]])

        if s != int(numbers[P][ix[P][j][0]:ix[P][j][1]]):
            return False

    return True


def generate(i, p, l):
    if i == P + 1:
        return check2()

    if l >= len(numbers[i]):
        return False

    if p == N:

        ix[i][p] = [l, len(numbers[i])]
        if numbers[i][l] != '0' or l == len(numbers[i]) - 1:
            
            if i == P or check1(i):
                return generate(i + 1, 0, 0)
        return False

    for j in range(l, min(l + 3 + (i == P), len(numbers[i]), l + 10 * (not numbers[i][l] == '0') + 1)):
        ix[i][p] = [l, j + 1]

        if generate(i, p + 1, j + 1):
            return True

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

        ix = [[[] for j in range(N + 1)] for i in range(P + 1)]

        generate(0, 0, 0)

        line = ''        
        for j in range(N):
            line += 'P' + str(j + 1) + ' '
        line += "Totals"
        print(line)

        for i in range(P + 1):

            line = names[i]
            for j in range(N + 1):
                line += ' '
                line += numbers[i][ix[i][j][0]:ix[i][j][1]]

            print(line)
