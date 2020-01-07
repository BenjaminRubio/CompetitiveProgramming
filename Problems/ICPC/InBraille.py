
ntob = {0: ".***..", 1: "*.....", 2: "*.*...", 3: "**....", 4: "**.*..",
        5: "*..*..", 6: "***...", 7: "****..", 8: "*.**..", 9: ".**..."}

bton = {v: str(k) for k, v in ntob.items()}

while True:

    N = int(input())
    if N == 0:
        break

    t = input().strip()

    if t == 'S':

        s = input().strip()
        ans = []
        for c in s:
            ans.append(ntob[int(c)])
        
        for i in range(3):
            print(' '.join([ans[j][2 * i:2 * i + 2] for j in range(N)]))
    
    if t == 'B':

        s = [input().strip().split(), input().strip().split(), input().strip().split()]
        ans = ""
        for i in range(N):
            ans += bton[''.join([s[j][i] for j in range(3)])]

        print(ans)
