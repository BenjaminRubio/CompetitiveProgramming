
while True:
    try:
        s = sum(map(int, input().split())) # suma de todos
        print(s // 2)
    except:
        break