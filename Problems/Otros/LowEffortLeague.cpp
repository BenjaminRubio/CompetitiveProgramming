#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
typedef long long ll;

int r;
vector<ll> s;

ll DP[1 << 15][15];

inline ll train(ll x, ll y)
{
    return max(0ll, y - x) * max(0ll, y - x);
}

ll dp(int i, int lev)
{
    if (lev == 0) return 0ll;

    if (DP[i][lev] != -1ll) return DP[i][lev];

    ll ans = LLONG_MAX;

    int j = i / (1 << (lev - 1));
    int l = (j & 1) ? (j - 1) : (j + 1); l <<= (lev - 1);
    repx(k, l, l + (1 << (lev - 1)))
        ans = min(ans, dp(k, lev - 1) + train(s[i], s[k]));

    return DP[i][lev] = ans + dp(i, lev - 1);
}

int main()
{
    cin >> r;

    s.resize(1 << r);
    rep(i, 1 << r) cin >> s[i];

    memset(DP, -1ll, sizeof DP);

    cout << dp(0, r) << '\n';
}