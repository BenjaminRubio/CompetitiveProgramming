#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep_(i, n) for (int i = (int)n - 1; i >= 0; i--)

int T, a, b, p;
string s;

int main()
{
    cin >> T;
    rep(_, T)
    {
        cin >> a >> b >> p;
        cin >> s;

        int n = s.size();
        int ans = n, accum = 0;
        char last = '.';
        rep_(i, n - 1)
        {
            if (s[i] != last) accum += (s[i] == 'A') ? a : b;
            if (accum <= p) ans = i + 1;
            last = s[i];
        }

        cout << ans << '\n';
    }
}