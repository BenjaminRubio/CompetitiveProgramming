
while True:

    line = list(input().lower().split())

    if line == ['*']:
        break

    yes = True
    for word in line:
        if word[0] != line[0][0]:
            print("N")
            yes = False
            break
    if yes:
        print("Y")
    