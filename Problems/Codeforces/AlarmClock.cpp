#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

ll T, a, b, c, d;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> c >> d;

        if (b >= a) { cout << b << '\n'; continue; }

        if (d >= c) { cout << -1 << '\n'; continue; }

        ll d_ = (a - b) / (c - d);
        ll ans = b + (d_ + ll(bool((a - b) % (c - d)))) * c;
        cout << ans << '\n';
    }
}