#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

const ll MOD = 1e9 + 7;

ll T, N, M, u, v;
vector<vector<ll>> G;
vector<ll> P, S, V;

ll dfs(ll u, ll p)
{
    for (ll v : G[u]) if (v != p) S[u] += dfs(v, u);
    return S[u];
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        G.assign(N, {});
        rep(i, N - 1)
        {
            cin >> u >> v; u--, v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        cin >> M;
        P.resize(M);
        rep(i, M) cin >> P[i];

        sort(P.rbegin(), P.rend());

        if (M > N - 1)
        {
            rep(i, M - (N - 1)) P[0] = (P[0] * P[i + 1]) % MOD;
            rep(i, N - 2) P[i + 1] = P[i + M - (N - 1) + 1];
        }

        S.assign(N, 1);
        dfs(0, -1);

        V.resize(N - 1);
        rep(i, N) if (i) V[i - 1] = S[i] * (N - S[i]);

        sort(V.rbegin(), V.rend());

        ll i = 0, ans = 0;
        for (ll e : V)
        {
            if (i < M) ans = (ans + (e * P[i]) % MOD) % MOD, i++;
            else ans = (ans + e) % MOD;
        }

        cout << (ans + MOD) % MOD << '\n';
    }
}