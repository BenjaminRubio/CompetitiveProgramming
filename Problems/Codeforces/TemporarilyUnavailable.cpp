#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, a, b, c, r;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> a >> b >> c >> r;

        if (a > b)
            swap(a, b);

        int ans;
        if (a > c + r)
            ans = b - a;
        else if (b < c - r)
            ans = b - a;
        else
        {
            int in = min(b, c + r) - max(a, c - r);
            ans = b - a - in;
        }

        cout << ans << '\n';
    }
}