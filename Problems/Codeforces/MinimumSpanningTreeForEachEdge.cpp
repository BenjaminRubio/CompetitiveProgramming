#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define ff first
#define ss second

struct Edge
{
    ll u, v, w, i;
    Edge(ll u, ll v, ll w, ll i) : u(u), v(v), w(w), i(i) {}
    bool operator>(const Edge &e) const { return w > e.w; }
};

vector<bool> U;
ll find_mst(vector<vector<Edge>> &g, vector<vector<Edge>> &mst)
{
    ll n = g.size();
    vector<bool> visited(n, false);
    mst.assign(n, vector<Edge>());

    ll total_cost = 0, count = 1;
    visited[0] = true;

    priority_queue<Edge, vector<Edge>, greater<Edge>> q;
    for (Edge &p : g[0]) q.emplace(0, p.v, p.w, p.i);

    while (!q.empty())
    {
        Edge e = q.top(); q.pop();

        if (visited[e.v]) continue;

        ll u = e.u, v = e.v, cost = e.w, i = e.i;
        visited[v] = true;
        total_cost += cost; U[i] = 1;
        mst[u].emplace_back(u, v, cost, i);
        mst[v].emplace_back(v, u, cost, i);

        if (++count == n) break;

        for (Edge p : g[v]) if (!visited[p.v]) q.emplace(v, p.v, p.w, p.i);
    }
    
    return total_cost;
}

ll N, M, u, v, w;
vector<vector<Edge>> G, T;
vector<Edge> E;

struct LCA
{
    ll n, maxe;
    vector<ll> A, D, MM;
    ll& anc(ll u, ll e) { return A[e * n + u]; }
    ll& mx(ll u, ll e) { return MM[e * n + u]; }
    void dfs(ll u, ll p, ll d, ll m)
    {
        anc(u, 0) = p; mx(u, 0) = m; D[u] = d;
        for (auto &e : T[u]) if (D[e.v] == -1) dfs(e.v, u, d + 1, e.w);
    }
    LCA(ll root)
    {
        n = G.size();
        maxe = 31 - __builtin_clz(n);
        D.assign(n, -1);
        A.resize(n * (maxe + 1));
        MM.resize(n * (maxe + 1));
        dfs(root, -1, 0, 0);
        rep(e, maxe) rep(u, n)
        {
            ll a = anc(u, e);
            anc(u, e + 1) = (a == -1 ? -1 : anc(a, e));
            mx(u, e + 1) = (a == -1 ? 0 : max(mx(u, e), mx(a, e)));
        }
    }
    ll raisel(ll u, ll k)
    {
        for (ll e = 0; k; e++, k >>= 1) if (k & 1) u = anc(u, e);
        return u;
    }
    ll raisem(ll u, ll k)
    {
        ll ans = 0;
        for (ll e = 0; k; e++, k >>= 1) if (k & 1)
            ans = max(ans, mx(u, e)), u = anc(u, e);
        return ans;
    }
    ll find_mx(ll u, ll v)
    {       
        if (D[u] < D[v]) swap(u, v); 
        ll ans = raisem(u, D[u] - D[v]);
        u = raisel(u, D[u] - D[v]);
        if (u == v) return ans;
        for (ll e = maxe; e >= 0; e--) if (anc(u, e) != anc(v, e))
        {
            ans = max({ans, mx(u, e), mx(v, e)});
            u = anc(u, e), v = anc(v, e);
        }
        return max({ans, mx(u, 0), mx(v, 0)});
    }
};

int main()
{
    cin >> N >> M;

    G.assign(N, {});
    rep(i, M)
    {
        cin >> u >> v >> w; u--, v--;
        G[u].emplace_back(u, v, w, i);
        G[v].emplace_back(v, u, w, i);
        E.emplace_back(u, v, w, i);
    }

    U.assign(M, 0); ll opt = find_mst(G, T);

    LCA lca(0);

    rep(i, M)
    {
        if (U[i]) cout << opt << '\n';
        else
        {
            ll aux = lca.find_mx(E[i].u, E[i].v);
            cout << opt + E[i].w - aux << '\n';
        }
    }
}