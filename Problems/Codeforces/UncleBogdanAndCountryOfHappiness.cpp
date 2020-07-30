#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll T, N, M, u, v;
vector<ll> P, H;
vector<vector<ll>> G;

ll acc(ll u, ll p)
{
    for (ll v : G[u]) if (v != p) P[u] += acc(v, u);
    return P[u];
}

bool check(ll u, ll p)
{
    bool flag = true;
    ll ans = 0;
    for (ll v : G[u]) if (v != p)
    {
        if ((P[v] + H[v]) < 0 || (P[v] - H[v]) < 0) return false;
        if (((P[v] + H[v]) & 1ll) || ((P[v] - H[v]) & 1ll)) return false;
        ans += (P[v] + H[v]) / 2ll;
        flag &= check(v, u);
    }
    flag &= (P[u] + H[u]) >= 0 && (P[u] - H[u]) >= 0;
    flag &= !((P[u] + H[u]) & 1ll) && !((P[u] - H[u]) & 1ll);
    return flag && ((P[u] + H[u]) / 2ll >= ans);
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> M;

        P.resize(N);
        rep(i, N) cin >> P[i];

        H.resize(N);
        rep(i, N) cin >> H[i];

        G.assign(N, {});
        rep(i, N - 1)
        {
            cin >> u >> v; u--, v--;
            G[u].push_back(v); G[v].push_back(u);
        }

        acc(0, -1);

        if (check(0, -1)) cout << "YES\n";
        else cout << "NO\n";
    }
}