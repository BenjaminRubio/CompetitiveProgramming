#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T;
ll x;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> x;

        ll ans = 0;
        while (x >= 2050ll)
        {
            ll p = 1;
            while (x >= (2050ll * p)) p = p * 10;
            p /= 10ll;
            x -= (2050ll * p);
            ans++;
        }

        if (x) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}