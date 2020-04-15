#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

int T, nr, ng, nb;
vector<ll> r, g, b;

ll val(ll x, ll y, ll z)
{
    return (x - y) * (x - y) + (y - z) * (y - z) + (x - z) * (x - z);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> T;
    while (T--)
    {
        cin >> nr >> ng >> nb;

        r.resize(nr);
        rep(i, nr) cin >> r[i];
        sort(r.begin(), r.end());
        g.resize(ng);
        rep(i, ng) cin >> g[i];
        sort(g.begin(), g.end());
        b.resize(nb);
        rep(i, nb) cin >> b[i];
        sort(b.begin(), b.end());

        ll ans = val(r[0], g[0], b[0]);
        int j = 0, k = 0;
        rep(i, nr)
        {
            while (j < ng and g[j] <= r[i]) j++;
            while (k < nb and b[k] <= r[i]) k++;

            if (j and k) ans = min(ans, val(r[i], g[j - 1], b[k - 1]));
            if (j and k < nb) ans = min(ans, val(r[i], g[j - 1], b[k]));
            if (k and j < ng) ans = min(ans, val(r[i], g[j], b[k - 1]));
            if (j < ng and k < nb) ans = min(ans, val(r[i], g[j], b[k]));
        }
        j = 0, k = 0;
        rep(i, ng)
        {
            while (j < nr and r[j] <= g[i]) j++;
            while (k < nb and b[k] <= g[i]) k++;

            if (j and k) ans = min(ans, val(g[i], r[j - 1], b[k - 1]));
            if (j and k < nb) ans = min(ans, val(g[i], r[j - 1], b[k]));
            if (k and j < nr) ans = min(ans, val(g[i], r[j], b[k - 1]));
            if (j < nr and k < nb) ans = min(ans, val(g[i], r[j], b[k]));
        }
        j = 0, k = 0;
        rep(i, nb)
        {
            while (j < ng and g[j] <= b[i]) j++;
            while (k < nr and r[k] <= b[i]) k++;

            if (j and k) ans = min(ans, val(b[i], g[j - 1], r[k - 1]));
            if (j and k < nr) ans = min(ans, val(b[i], g[j - 1], r[k]));
            if (k and j < ng) ans = min(ans, val(b[i], g[j], r[k - 1]));
            if (j < ng and k < nr) ans = min(ans, val(b[i], g[j], r[k]));
        }

        cout << ans << '\n';
    }
}