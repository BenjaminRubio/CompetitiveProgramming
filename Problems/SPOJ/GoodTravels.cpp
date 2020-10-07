#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N, M, u, v, s, t, id, c, s_, t_;
vector<vector<int>> G;
vector<set<int>> G_;
vector<int> D, L, C, I, F, F_; stack<int> S;

void dfs(int u)
{
    D[u] = L[u] = id++, I[u] = 1; S.push(u);
    for (int v : G[u])
    {
        if (D[v] == -1) { dfs(v); L[u] = min(L[v], L[u]); }
        else if (I[v]) L[u] = min(L[v], L[u]);
    }
    if (L[u] == D[u]) while (1)
    {
        int x = S.top(); S.pop();
        C[x] = c, I[x] = false;
        if (x == u) { c++; break; }
    }
}

vector<pair<ll, bool>> DP;

pair<ll, bool> dp(int u)
{
    if (u == t_) return {F_[t_], 1};
    if (DP[u].ff != -1) return DP[u];

    ll ans = LLONG_MIN;
    for (int v : G_[u]) if (dp(v).ss) ans = max(ans, dp(v).ff);

    return DP[u] = {ans + F_[u], ans != LLONG_MIN};
}

int main()
{
    cin >> N >> M >> s >> t; s--, t--;

    F.resize(N);
    rep(i, N) cin >> F[i];

    G.assign(N, {});
    rep(_, M)
    {
        cin >> u >> v; u--, v--;
        G[u].push_back(v);
    }

    D.assign(N, -1); L.resize(N); I.assign(N, 0); C.resize(N);
    id = c = 0; rep(u, N) if (D[u] == -1) dfs(u);

    G_.assign(c, {}); F_.assign(c, 0);
    rep(u, N)
    {
        if (u == s) s_ = C[u];
        if (u == t) t_ = C[u];
        F_[C[u]] += F[u];
        for (int v : G[u]) if (C[u] != C[v]) G_[C[u]].insert(C[v]);
    }

    DP.assign(c, {-1, 0});
    cout << dp(s_).ff << '\n';
}