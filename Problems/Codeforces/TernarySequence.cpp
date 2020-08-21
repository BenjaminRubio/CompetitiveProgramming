#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

ll T, x, y, z, x_, y_, z_, t;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> x >> y >> z;
        cin >> x_ >> y_ >> z_;

        ll ans = 0;
        ans += min(z, y_) * 2ll;

        t = min(z, y_);
        z -= t, y_ -= t;

        t = min(z, z_);
        z -= t, z_ -= t;

        t = min(x, z_);
        x -= t, z_ -= t;

        ans -= min(z_, y) * 2ll;
        cout << ans << '\n';
    }
}