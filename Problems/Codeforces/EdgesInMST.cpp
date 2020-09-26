#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

struct DSU
{
    vector<int> p;
    DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    void unite(int x, int y)
    {
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};

struct Edge
{
    int u, v, w, i;
    Edge() {}
    Edge(int u, int v, int w, int i) : u(u), v(v), w(w), i(i) {}
    bool operator<(const Edge &e) { return w < e.w; }
};

int N, M, u, v, w;
map<int, vector<pair<int, int>>> G;
vector<int> D, L, A;
vector<Edge> E;

void dfs(int u, int p, int d)
{
    D[u] = d, L[u] = d;
    for(auto e : G[u]) if (e.ss != p)
    {
        if (D[e.ff] == -1)
        {
            dfs(e.ff, e.ss, d + 1);
            if (L[e.ff] > D[u]) A[e.ss] = 2;
            L[u] = min(L[u], L[e.ff]); 
        }
        L[u] = min(L[u], D[e.ff]);
    }
}

int main()
{
    cin >> N >> M;

    rep(i, M) { cin >> u >> v >> w; u--, v--; E.emplace_back(u, v, w, i); }

    sort(E.begin(), E.end());

    DSU dsu(N);

    int i = 0, j = 0;
    A.assign(M, 1); D.assign(N, -1); L.assign(N, -1);
    while ((i = j) < M)
    {
        while (j < M && E[i].w == E[j].w) j++;

        G.clear();

        for (int k = i; k < j; k++)
        {
            u = dsu.get(E[k].u), v = dsu.get(E[k].v);
            if (u == v) { A[E[k].i] = 0; continue; }
            D[u] = D[v] = L[u] = L[v] = -1;
            G[u].emplace_back(v, E[k].i), G[v].emplace_back(u, E[k].i);
        }

        for (int k = i; k < j; k++)
        {
            u = dsu.get(E[k].u);
            if (D[u] == -1) dfs(u, -1, 0);
        }

        for (int k = i; k < j; k++) dsu.unite(E[k].u, E[k].v);
    }

    rep(i, M)
    {
        if (A[i] == 0) cout << "none\n";
        if (A[i] == 1) cout << "at least one\n";
        if (A[i] == 2) cout << "any\n";
    }
}