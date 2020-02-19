#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

int T;
ll n, x, M, a;

int main()
{
    cin >> T;
    rep(_, T)
    {
        cin >> n >> x;

        M = -1;
        ll ans = LLONG_MAX;
        rep(i, n)
        {
            cin >> a;
            ll aux = x / a;
            if (aux) ans = min(ans, aux + (ll)bool(x % a));
            else ans = min(2LL, ans);
        }

        cout << ans << '\n';
    }
}