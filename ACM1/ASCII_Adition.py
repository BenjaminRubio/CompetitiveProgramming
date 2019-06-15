n0 = ["xxxxx", "x...x", "x...x", "x...x", "x...x", "x...x", "xxxxx"]
n1 = ["....x", "....x", "....x", "....x", "....x", "....x", "....x"]
n2 = ["xxxxx", "....x", "....x", "xxxxx", "x....", "x....", "xxxxx"]
n3 = ["xxxxx", "....x", "....x", "xxxxx", "....x", "....x", "xxxxx"]
n4 = ["x...x", "x...x", "x...x", "xxxxx", "....x", "....x", "....x"]
n5 = ["xxxxx", "x....", "x....", "xxxxx", "....x", "....x", "xxxxx"]
n6 = ["xxxxx", "x....", "x....", "xxxxx", "x...x", "x...x", "xxxxx"]
n7 = ["xxxxx", "....x", "....x", "....x", "....x", "....x", "....x"]
n8 = ["xxxxx", "x...x", "x...x", "xxxxx", "x...x", "x...x", "xxxxx"]
n9 = ["xxxxx", "x...x", "x...x", "xxxxx", "....x", "....x", "xxxxx"]

numbers = [n0, n1, n2, n3, n4, n5, n6, n7, n8, n9]

sum = []
for i in range(7):
    sum.append(input())

size = int(len(sum[0]) / 6) + 1
suma = 0
number = 0

for k in range(size):
    es_num = False
    for n in range(len(numbers)):
        todos = True
        for i in range(7):
            for j in range(5 * k + k, 5 * k + k + 5):
                if numbers[n][i][j - 5 * k - k] != sum[i][j]:
                    todos = False
                    break
        if todos:
            es_num = True
            number = number * 10 + n
            break
    if not es_num:
        suma = number
        number = 0
suma += number

final = ["", "", "", "", "", "", ""]

first = 7
while(suma):
    num = int(suma % 10)
    suma = int(suma / 10)
    for i in range(7):
        if first:
            final[i] = numbers[num][i] + final[i]
            first -=1
            continue
        final[i] = numbers[num][i] + "." + final[i]

for line in final:
    print(line)
