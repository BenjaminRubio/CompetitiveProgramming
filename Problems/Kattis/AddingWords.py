import sys

value = {}; inv_value = {}

for line in sys.stdin:

    line = line.strip().split()
    w = line[0]
    
    if w == "def":
        w = line[1]
        v = int(line[2])

        if w in value.keys():
            inv_value.pop(value[w])
        
        value[w] = v
        inv_value[v] = w

    elif w == "calc":
        ans = 0; m = 1; unk = 0

        i = 1
        while True:
            w = line[i]; sign = line[i + 1]

            if w not in value.keys():
                unk = 1
                break

            ans += m * value[w]

            if sign == "+":
                m = 1
            if sign == "-":
                m = -1
            if sign == "=":
                break

            i += 2
        
        answ = None
        if unk or ans not in inv_value.keys():
            answ = "unknown"
        else:
            answ = inv_value[ans]

        print(' '.join(line[1:]), answ)
    
    else:
        value = {}; inv_value = {}
