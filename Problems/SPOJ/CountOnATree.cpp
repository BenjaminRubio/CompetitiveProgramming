#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep_(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

struct Node
{
    int v, l, r;
    Node() : v(0), l(0), r(0) {}
    Node(int v) : v(v) {}
    Node(const Node &a, const Node &b, int l, int r) : l(l), r(r)
    { v = a.v + b.v; }
};

template <class node>
struct PST 
{
    int cnt = 1, n, rc = 1; node na, nb, nc, nd;
    vector<node> st; vector<int> rt;

    node query(int u, int a, int b, int i, int j)
    {
        if (j < a || b < i) return node();
        if (a <= i && j <= b) return st[u];
        int m = (i + j) / 2, l = st[u].l, r = st[u].r;
        return node(query(l, a, b, i, m), query(r, a, b, m + 1, j), l, r);
    }
    int update(int u, int p, node v, int i, int j)
    {
        if (j < p || p < i) return u;
        st[cnt] = st[u]; int x = cnt++, m = (i + j) / 2;
        if (i == j) { st[x] = v; return x; }
        int l = st[x].l = update(st[x].l, p, v, i, m);
        int r = st[x].r = update(st[x].r, p, v, m + 1, j);
        st[x] = node(st[l], st[r], l, r); return x;
    }

    PST(int N) : st(2e6), rt(1e5), n(N) {}
    void update(int t, int p, node v) { rt[rc++] = update(rt[t], p, v, 0, n - 1); }
    node query(int t, int a, int b) { return query(rt[t], a, b, 0, n - 1); }

    int search(int k, int i, int j)
    {
        if (i == j) return i;
        int m = (i + j) / 2, v = st[na.l].v + st[nb.l].v - st[nc.l].v - st[nd.l].v;
        if (v >= k)
        {
            na = st[na.l], nb = st[nb.l], nc = st[nc.l], nd = st[nd.l];
            return search(k, i, m);
        }
        na = st[na.r], nb = st[nb.r], nc = st[nc.r], nd = st[nd.r];
        return search(k - v, m + 1, j);
    }

    int search(int a, int b, int c, int d, int k)
    {
        na = st[rt[a]], nb = st[rt[b]], nc = st[rt[c]], nd = st[rt[d]];
        return search(k, 0, n - 1);
    }
};

const int MAXN = 1e5;

int N, Q, u, v, k, id;
int W[MAXN], I[MAXN], P[MAXN];
map<int, int> m, m_;
vector<int> G[MAXN], s;

struct LCA
{
    vector<int> A, D; int n, maxe;

    int& anc(int u, int e) { return A[e * n + u]; }    
    int inline log2(int x) { return 31 - __builtin_clz(x); }
    
    void dfs(int u, int p, int depth)
    {
        anc(u, 0) = p; D[u] = depth;
        for (int v : G[u]) if (v != p) dfs(v, u, depth + 1);
    }
    LCA(int root)
    {
        n = N, maxe = log2(n);
        D.assign(n, -1); A.resize(n * (maxe + 1));
        dfs(root, -1, 0);
        repx(e, 1, maxe + 1) rep(u, n)
        {
            int a = anc(u, e - 1);
            anc(u, e) = (a == -1 ? -1 : anc(a, e - 1));
        }
    }
    int raise(int u, int k)
    {
        for (int e = 0; k; e++, k >>= 1) if (k & 1) u = anc(u, e);
        return u;
    }
    int lca(int u, int v)
    {       
        if (D[u] < D[v]) swap(u, v); 
        u = raise(u, D[u] - D[v]);
        if (u == v) return u;
        rep_(e, maxe) if (anc(u,e) != anc(v,e))
            u = anc(u,e), v = anc(v,e);
        return anc(u,0);
    }
};

void dfs(int u, int p, PST<Node> &pst)
{
    int t = (p != -1) ? I[p] : 0; I[u] = ++id, P[u] = p;
    Node n = pst.query(t, W[u], W[u]); n.v++;
    pst.update(t, W[u], n);
    for (int v : G[u]) if (v != p) dfs(v, u, pst);
}

int main()
{
    scanf("%d %d", &N, &Q);

    rep(i, N) { cin >> W[i]; s.push_back(W[i]); }

    sort(s.begin(), s.end());

    id = 0;
    for (int x : s) m[x] = id, m_[id++] = x;
    rep(i, N) W[i] = m[W[i]];

    rep(i, N - 1)
    {
        scanf("%d %d", &u, &v);; u--, v--;
        G[u].push_back(v); G[v].push_back(u);
    }

    PST<Node> pst(N);
    LCA lca(0); id = 0; dfs(0, -1, pst);

    while (Q--)
    {
        scanf("%d %d %d", &u, &v, &k);; u--, v--; int l = lca.lca(u, v);
        int a = I[u], b = I[v], c = I[l], d = (P[l] != -1) ? I[P[l]] : 0;
        printf("%d\n", m_[pst.search(a, b, c, d, k)]);
    }
}