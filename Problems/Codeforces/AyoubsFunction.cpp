#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

ll T, n, m;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> n >> m;

        ll b = min(m + 1, n - m);

        if (b == 0)
        {
            cout << (n * (n + 1)) / 2 << '\n';
            continue;
        }

        ll d = (n - m) / b;
        ll r = (n - m) % b;

        // cerr << b - r << ' ' << r << '\n';

        ll ans = (n * (n + 1)) / 2;
        ans -= (b - r) * (d * (d + 1)) / 2;
        ans -= r * ((d + 1) * (d + 2)) / 2;

        cout << ans << '\n';
    }
}