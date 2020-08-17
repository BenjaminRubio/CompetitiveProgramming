#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int T, N;
string A;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> A;

        set<char> s;
        rep(i, N) s.insert(A[i]);
        if (s.size() == 1) { cout << (N - 1) / 3 + 1 << '\n'; continue; }

        int i = 0, off;
        while (A[i] == A[0]) i++;
        off = i;
        
        int ans = 0, c = 0; char l = 'X';
        repx(j, i, N)
        {
            if (A[j] == l) c++;
            else
            {
                ans += c / 3;
                l = A[j], c = 1;
            }
        }
        if (A[N - 1] == A[0]) ans += (c + i) / 3;
        else ans += i / 3 + c / 3;

        cout << ans << '\n';
    }
}