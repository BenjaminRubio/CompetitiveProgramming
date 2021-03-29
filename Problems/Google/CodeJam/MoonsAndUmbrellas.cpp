#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, X, Y;
string S;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cout << "Case #" << t + 1 << ": ";

        cin >> X >> Y >> S;

        int ans = 0;

        char l = -1;
        for (char c : S)
        {
            if (c == 'J' && l == 'C') ans += X;
            if (c == 'C' && l == 'J') ans += Y;
            if (c != '?') l = c;
        }

        cout << ans << '\n';
    }
}