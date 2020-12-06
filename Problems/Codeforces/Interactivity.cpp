#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

ll MOD = 1e9 + 7;

ll mul(ll x, ll y) { return (x * y) % MOD; }
ll add(ll x, ll y) { return (x + y) % MOD; }

int N, a;
vector<vector<int>> G;

ll inv(ll a)
{
    ll ans = 1, b = a, p = MOD - 2;
    while (p)
    {
        if (p & 1ll) ans = (ans * b) % MOD;
        b = (b * b) % MOD, p >>= 1ll;
    }
    return ans;
}

ll DP[100010][2];

ll dp(int u, int t)
{
    if (DP[u][t] != -1) return DP[u][t];
    if (G[u].empty()) return 1;

    ll tot = 1, ans = 0, z = -1;
    for (int v : G[u])
    {
        ll temp = dp(v, 1);
        if (z == -1 && temp == 0) z = v;
        else if (temp == 0) z = -2;
        else tot = mul(tot, temp);
    }
    
    if (z == -2) return DP[u][t] = 0;
    if (z != -1) return DP[u][t] = mul(dp(z, 0), tot);

    if (t) ans = tot;
    for (int v : G[u])
    {
        ll temp = mul(dp(v, 0), mul(tot, inv(dp(v, 1))));
        ans = add(ans, temp);
    }

    return DP[u][t] = ans;
}

int main()
{
    cin >> N;
    G.assign(N, {});

    rep(i, N - 1)
    {
        cin >> a; a--;
        G[a].push_back(i + 1);
    }

    memset(DP, -1, sizeof DP);
    cout << (dp(0, 1) + MOD) % MOD << '\n';
}