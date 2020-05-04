#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0ll; i < (ll)n; i++)
typedef long long ll;

ll C, N, M, D;
vector<ll> c;

int main()
{
    cin >> C >> N >> M;

    c.resize(N);
    rep(i, N) cin >> c[i];

    vector<ll> d(N);
    rep(i, N) rep(j, 12) if (c[i] * (1ll << (j + 1ll)) > C)
    {
        d[i] = j + 1ll;
        break;
    }

    rep(_, M)
    {
        cin >> D;

        ll ans = 0ll;
        rep(i, N) ans += (1ll << (max(0ll, D - d[i] + 1)));

        cout << ans << '\n';
    }
}