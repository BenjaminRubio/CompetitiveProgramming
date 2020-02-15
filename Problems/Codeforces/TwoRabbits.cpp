#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, x, y, a, b;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> x >> y >> a >> b;

        int d = y - x;
        if (d % (a + b) == 0) cout << d / (a + b) << '\n';
        else cout << -1 << '\n';
    }
}