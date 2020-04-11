#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

int n, m;
vector<ll> a, b;

ll calc(ll mid)
{
    ll ans = 0;
    rep(i, n) ans += max(0ll, mid - a[i]);
    rep(i, m) ans += max(0ll, b[i] - mid);
    return ans;
}

int main()
{
    cin >> n >> m;

    a.resize(n);
    rep(i, n) cin >> a[i];

    b.resize(m);
    rep(i, m) cin >> b[i];

    ll l = 0, r = 1e9;
    while (r - l > 2)
    {
        ll m1 = (2ll * l + r) / 3ll;
        ll m2 = (l + 2ll * r) / 3ll;

        if (calc(m1) > calc(m2)) l = m1;
        else if (calc(m2) > calc(m1)) r = m2;
        else l = m1, r = m2;
    }
    ll ans = LLONG_MAX;
    for (ll i = l; i <= r; i++) ans = min(ans, calc(i));
    cout << ans << '\n';
}