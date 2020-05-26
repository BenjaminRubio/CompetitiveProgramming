#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

ll n, x;
vector<ll> d;

int main()
{
    cin >> n >> x;

    d.resize(n);
    rep(i, n) cin >> d[i];

    ll y = 0, s = 0;
    rep(i, n) y += d[i], s += (d[i] * (d[i] + 1ll)) / 2ll;

    ll ans = 0;
    ans += s * (x / y);

    x = x % y;

    rep(i, n) d.push_back(d[i]);

    vector<ll> pres(2 * n, 0);
    rep(i, 2 * n) pres[i] = (d[i] * (d[i] + 1ll)) / 2ll + (i ? pres[i - 1] : 0ll);
    vector<ll> pred(2 * n, 0);
    rep(i, 2 * n) pred[i] = d[i] + (i ? pred[i - 1] : 0ll);

    ll aux = 0, ind = 0;
    repx(i, n, 2 * n)
    {
        while (pred[i] - pred[ind] > x) ind++;

        ll now = pres[i] - pres[ind];

        if (pred[i] - pred[ind] < x)
        {
            ll off = d[ind] - (x - pred[i] + pred[ind]);
            now += (d[ind] * (d[ind] + 1ll)) / 2ll;
            now -= (off * (off + 1ll)) / 2ll;
        }

        aux = max(aux, now);
    }

    cout << ans + aux << '\n';
}