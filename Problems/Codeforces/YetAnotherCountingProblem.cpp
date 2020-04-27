#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

ll T, a, b, q, l, r;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> q;
        ll m = (a * b) / __gcd(a, b);
        rep(_, q)
        {
            cin >> l >> r; l--;

            ll L = l / m;
            ll R = r / m;
            // cerr << m << ' ' << L << ' ' << R << '\n';
            ll ans = (R - L) * (m - max(a, b));
            // cerr << ans << '\n';
            L *= m; R *= m;
            ans += max(0ll, (r - (R - 1)) - max(a, b));
            // cerr << ans << '\n';
            ans -= max(0ll, (l - (L - 1)) - max(a, b));
            // cerr << ans << '\n';

            cout << ans << ' ';
        }
        cout << '\n';
    }
}