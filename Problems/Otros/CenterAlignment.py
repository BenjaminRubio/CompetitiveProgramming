
m = []
max_size = 0

while True:
    
    try:
        line = input()
    except:
        break

    line = line.strip()
    max_size = max(max_size, len(line))
    m.append(line)

size = max_size

print("*" * (size + 2))

i = 0
for line in m:
    s = "*"

    spaces = size - len(line)

    if spaces % 2 == 1 and i % 2 == 1:
        spacel = spaces // 2 + 1
    else:
        spacel = spaces // 2

    s += (" " * spacel)
    s += line
    s += (" " * (spaces - spacel))
    s += "*"
    print(s)

    if spaces % 2 == 1:
        i += 1

print("*" * (size + 2))

