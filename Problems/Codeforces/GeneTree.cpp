#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define eb emplace_back
typedef long long ll;

struct edge
{
    int to, w;
    edge(int v, int weight) { to = v; w = weight; }
};

struct Centroid
{
    int n, root;
    vector<vector<edge>> G;
    vector<int> ST, parent, l;
    vector<ll> S, S2, d;
    vector<bool> visited;

    Centroid(int size)
    {
        n = size;
        G.resize(n);
        ST.assign(n, 1);
        visited.assign(n, false);
        parent.reserve(n);
        l.assign(n, 0); S.assign(n, 0); S2.assign(n, 0);
        d.assign(n, 0);
    }

    void add(int u, int v, int w)
    {
        G[u].eb(v, w); G[v].eb(u, w);
    }

    int dfs(int u, int p)
    {
        for (edge v : G[u]) if (v.to != p)
            ST[u] += dfs(v.to, u);
        return ST[u];
    }

    void make(int u = 0, int p = -1, int size = -1)
    {
        if (size < 0) size = dfs(u, -1);
        for (edge v : G[u]) if (!visited[v.to] && 2 * ST[v.to] >= size)
        {
            ST[u] = 0; make(v.to, p, size); return;
        }
        root = u;
    }

    int pre0(int u, int p)
    {
        if (G[u].size() == 1) return l[u] = 1;
        for (edge v : G[u]) if (v.to != p)
            l[u] += pre0(v.to, u);
        return l[u];
    }

    ll pre1(int u, int p, int w)
    {
        for (edge v : G[u]) if (v.to != p)
            S[u] += pre1(v.to, u, v.w);
        S[u] += l[u] * w;
        return S[u];
    }

    ll pre2(int u, int p, int w)
    {
        for (edge v : G[u]) if (v.to != p)
            S2[u] += pre2(v.to, u, v.w) + 2 * S[v.to] * w;
        S2[u] += l[u] * w * w;
        return S2[u];
    }

    void calc(int u, int p)
    {
        ll c = 0, aux = 0, aux2 = 0;
        for (edge v : G[u]) if (v.to != p)
        {
            d[u] += aux2 * l[v.to] + 2 * aux * S[v.to] + c * S2[v.to];
            c += l[v.to]; aux += S[v.to]; aux2 += S2[v.to];
            calc(v.to, u);
        }
    }

    ll get_d()
    {
        pre0(root, -1); pre1(root, -1, 0); pre2(root, -1, 0);
        calc(root, -1);

        ll ans = 0;
        rep(i, n) ans += d[i];
        return ans;
    }
};

int n, u, v, w;
vector<int> values;

int main()
{
    cin >> n;

    Centroid CD(n);
    rep(i, n - 1)
    {
        cin >> u >> v >> w;
        CD.add(u - 1, v - 1, w);
    }

    CD.make();
    ll ans = CD.get_d();

    cout << ans << '\n';
}
